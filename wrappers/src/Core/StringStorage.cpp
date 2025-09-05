//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
//

#include "StringStorage.hpp"

#include "AOS/TagUtil.hpp"
#include "Core/ToString.hpp"

#include <cstring>
#include <stdexcept>

#ifdef TRACE_SSC
#include <iostream>
#endif

StringStorageCore::StringStorageCore()
  : mObjectIdCounter(0)
{
}

StringStorageCore::~StringStorageCore()
{
    ClearAll();
}

const char *StringStorageCore::Add(unsigned long &objectId, Tag tagName, const std::string &string)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Add(objectId = " << objectId << ", tag = " << AOS::TagUtil::toString(tagName) << ", string = \"" << string << "\")"
              << std::endl;
#endif
    if (objectId == 0)
        objectId = ++mObjectIdCounter;

    // Check if tagName already exists for this objectId
    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator != mObjectIdToMap.end())
        if (outerIterator->second.find(tagName) != outerIterator->second.end())
        {
            auto error = "String Storage Collector: Add(" + std::to_string(objectId) + "," + AOS::TagUtil::toString(tagName) + "," + string
                + ") .. tagName for objectId already exists!";
            throw std::runtime_error(error);
        }

    // Create copy of string
    auto pString = new char[string.size() + 1];
    std::memcpy(pString, string.c_str(), string.size() + 1);

    mObjectIdToMap[objectId][tagName] = (const char *)pString; // map objectId and tagName to string copy

    return (const char *)pString;
}

const char **StringStorageCore::Add(unsigned long &objectId, Tag tagName, const std::vector<std::string> &strings)
{
#ifdef TRACE_SSC
    std::cout << "SSC::AddArray(objectId = " << objectId << ", tag = " << AOS::TagUtil::toString(tagName)
              << ", strings.size() = " << strings.size() << ")" << std::endl;
#endif

    if (objectId == 0)
        objectId = ++mObjectIdCounter;

    // Check if tagName already exists for this objectId
    const auto &outerIterator = mObjectIdToArrayMap.find(objectId);
    if (outerIterator != mObjectIdToArrayMap.end())
        if (outerIterator->second.find(tagName) != outerIterator->second.end())
        {
            auto error = "String Storage Collector: AddArray(" + std::to_string(objectId) + "," + AOS::TagUtil::toString(tagName)
                + ") .. tagName for objectId already exists!";
            throw std::runtime_error(error);
        }

    // Create array of char* pointers (with null terminator)
    auto pArray = new char *[strings.size() + 1];

    // Create copies of individual strings and store pointers
    for (size_t i = 0; i < strings.size(); i++)
    {
        auto pString = new char[strings[i].size() + 1];
        std::memcpy(pString, strings[i].c_str(), strings[i].size() + 1);

        pArray[i] = pString;
    }
    pArray[strings.size()] = nullptr; // Null-terminate the array

    mObjectIdToArrayMap[objectId][tagName] = (const char **)pArray; // map objectId and tagName to array of string copies

    return (const char **)(pArray);
}

void StringStorageCore::Invalidate(const unsigned long objectId)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Invalidate(objectId = " << objectId << ")" << std::endl;
#endif

    if (objectId == 0)
    {
        auto error = "String Storage Collector: Invalidate(" + std::to_string(objectId) + ") .. objectId == 0!";
        throw std::runtime_error(error);
    }

    // Copy pointers to garbage
    const auto &stringIterator = mObjectIdToMap.find(objectId);
    if (stringIterator != mObjectIdToMap.end())
        for (const auto &elem : stringIterator->second)
            mGarbageStrings.push_back(elem.second);

    // Copy array pointers to garbage
    const auto &arrayIterator = mObjectIdToArrayMap.find(objectId);
    if (arrayIterator != mObjectIdToArrayMap.end())
        for (const auto &elem : arrayIterator->second)
            mGarbageStringArrays.push_back(elem.second);

    // Remove from both maps
    mObjectIdToMap.erase(stringIterator);
    mObjectIdToArrayMap.erase(arrayIterator);

    ClearGarbage(); // remove garbage strings and string arrays
}

void StringStorageCore::FinalizeObject(const unsigned long objectId, const Object *object)
{
#ifdef TRACE_SSC
    std::cout << "SSC::FinalizeObject(objectId = " << objectId << ", object = " << ToString::FromDataPointer(object) << ")" << std::endl;
#endif

    if (objectId == 0 || object == nullptr)
    {
        auto error = "String Storage Collector: FinalizeObject(" + std::to_string(objectId) + ","
            + std::to_string(reinterpret_cast<uintptr_t>(object)) + ") .. objectId == 0 or object is nullptr!";
        throw std::runtime_error(error);
    }

    // Copy strings to final object
    const auto &stringIterator = mObjectIdToMap.find(objectId);
    if (stringIterator != mObjectIdToMap.end())
    {
        for (const auto &elem : stringIterator->second)
            mObjectPtrToMap[reinterpret_cast<uintptr_t>(object)][elem.first] = elem.second;
        mObjectIdToMap.erase(stringIterator);
    }

    // Copy arrays to final object
    const auto &arrayIterator = mObjectIdToArrayMap.find(objectId);
    if (arrayIterator != mObjectIdToArrayMap.end())
    {
        for (const auto &elem : arrayIterator->second)
            mObjectPtrToArrayMap[reinterpret_cast<uintptr_t>(object)][elem.first] = elem.second;
        mObjectIdToArrayMap.erase(arrayIterator);
    }
}

const char *StringStorageCore::Change(const Object *object, Tag tagName, const std::string &string)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Change(object = " << ToString::FromDataPointer(object) << ", tag = " << AOS::TagUtil::toString(tagName)
              << ", string = \"" << string << "\")" << std::endl;
#endif

    ClearGarbage(); // remove garbage strings and string arrays

    // Create copy of string
    auto pString = new char[string.size() + 1];
    std::memcpy(pString, string.c_str(), string.size() + 1);

    const auto &outerIterator = mObjectPtrToMap.find(reinterpret_cast<uintptr_t>(object));
    if (outerIterator != mObjectPtrToMap.end())
    {
        const auto &innerIterator = outerIterator->second.find(tagName);
        if (innerIterator != outerIterator->second.end())
        {
            mGarbageStrings.push_back(innerIterator->second); // can't be removed now, becouse still is used, move pointer to garbage
            outerIterator->second.erase(innerIterator);
        }
    }

    mObjectPtrToMap[reinterpret_cast<uintptr_t>(object)][tagName] = pString;

    return (const char *)pString;
}

const char **StringStorageCore::Change(const Object *object, Tag tagName, const std::vector<std::string> &strings)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Change(object = " << ToString::FromDataPointer(object) << ", tag = " << AOS::TagUtil::toString(tagName)
              << ", strings.size() = " << strings.size() << ")" << std::endl;
#endif

    ClearGarbage(); // remove garbage strings and string arrays

    // Create array of char* pointers (with null terminator)
    auto pArray = new char *[strings.size() + 1];

    // Create copies of individual strings and store pointers
    for (size_t i = 0; i < strings.size(); i++)
    {
        auto pString = new char[strings[i].size() + 1];
        std::memcpy(pString, strings[i].c_str(), strings[i].size() + 1);

        pArray[i] = pString;
    }
    pArray[strings.size()] = nullptr; // Null-terminate the array

    const auto &outerIterator = mObjectPtrToArrayMap.find(reinterpret_cast<uintptr_t>(object));
    if (outerIterator != mObjectPtrToArrayMap.end())
    {
        const auto &innerIterator = outerIterator->second.find(tagName);
        if (innerIterator != outerIterator->second.end())
        {
            mGarbageStringArrays.push_back(innerIterator->second); // can't be removed now, becouse still is used, move pointer to garbage
            outerIterator->second.erase(innerIterator);
        }
    }

    mObjectPtrToArrayMap[reinterpret_cast<uintptr_t>(object)][tagName] = (const char **)pArray;

    return (const char **)pArray;
}

void StringStorageCore::ClearGarbage()
{
    // Delete all garbage strings
    for (const auto &str : mGarbageStrings)
        delete[] str;
    mGarbageStrings.clear();

    // Delete all garbage string arrays
    for (const auto &array : mGarbageStringArrays)
    {
        for (auto it = array; *it != nullptr; ++it)
            delete[] *it;
        delete[] array;
    }
    mGarbageStringArrays.clear();
}

void StringStorageCore::ClearAll()
{
    // Clear all managed strings and string arrays

    for (auto &outerPair : mObjectIdToMap)
        for (auto &innerPair : outerPair.second)
            mGarbageStrings.push_back(innerPair.second);
    mObjectIdToMap.clear();

    for (auto &outerPair : mObjectPtrToMap)
        for (auto &innerPair : outerPair.second)
            mGarbageStrings.push_back(innerPair.second);
    mObjectPtrToMap.clear();

    for (auto &outerPair : mObjectIdToArrayMap)
        for (auto &innerPair : outerPair.second)
            mGarbageStringArrays.push_back(innerPair.second);
    mObjectIdToArrayMap.clear();

    for (auto &outerPair : mObjectPtrToArrayMap)
        for (auto &innerPair : outerPair.second)
            mGarbageStringArrays.push_back(innerPair.second);
    mObjectPtrToArrayMap.clear();

    ClearGarbage(); // remove garbage strings and string arrays
}
