//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "StringStorage.hpp"

#include "AOS/TagUtil.hpp"
#include "Core/ToString.hpp"

#include <cstdio>
#include <cstring>
#include <stdexcept>

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
    return Add(objectId, tagName, string.c_str());
}

const char *StringStorageCore::Add(unsigned long &objectId, Tag tagName, const char *string)
{
#ifdef TRACE_SSC
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::Add(objectId = %lu, tag = %s, c-string = %s%s%s)\n", objectId, tagString.c_str(),
                 string != nullptr ? "\"" : "", string != nullptr ? string : "nullptr", string != nullptr ? "\"" : "");
#endif

    if (string == nullptr)
    {
        if (objectId != 0)
            Remove(objectId, tagName);
        return nullptr;
    }

    if (objectId == 0)
        objectId = ++mObjectIdCounter;

    // Check if tagName already exists for this objectId
    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator != mObjectIdToMap.end())
        if (outerIterator->second.find(tagName) != outerIterator->second.end())
        {
            auto error = "String Storage Collector: Add(" + std::to_string(objectId) + "," + AOS::TagUtil::toString(tagName)
                + ",const char*) .. tagName for objectId already exists!";
            throw std::runtime_error(error);
        }

    // Create copy of string
    const size_t stringLength = std::strlen(string);
    auto pString = new char[stringLength + 1];
    std::memcpy(pString, string, stringLength + 1);

    mObjectIdToMap[objectId][tagName] = pString; // map objectId and tagName to string copy

    return pString;
}

const char **StringStorageCore::Add(unsigned long &objectId, Tag tagName, const std::vector<std::string> &strings)
{
#ifdef TRACE_SSC
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::AddArray(objectId = %lu, tag = %s, strings.size() = %zu)\n", objectId, tagString.c_str(), strings.size());
#endif

    auto pStrings = new const char *[strings.size() + 1];
    for (size_t i = 0; i < strings.size(); ++i)
        pStrings[i] = strings[i].c_str();
    pStrings[strings.size()] = nullptr;

    const char **result = Add(objectId, tagName, pStrings);
    delete[] pStrings;

    return result;
}

const char **StringStorageCore::Add(unsigned long &objectId, Tag tagName, const char *strings[])
{
    if (strings == nullptr)
    {
        if (objectId != 0)
            Remove(objectId, tagName);
        return nullptr;
    }

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

    size_t stringsCount = 0;
    for (const char **entry = strings; *entry != nullptr; ++entry)
        ++stringsCount;

    // Create array of char* pointers (with null terminator)
    auto pArray = new char *[stringsCount + 1];

    // Create copies of individual strings and store pointers
    size_t i = 0;
    for (const char **entry = strings; *entry != nullptr; ++entry, ++i)
    {
        const size_t stringLength = std::strlen(*entry);
        auto pString = new char[stringLength + 1];
        std::memcpy(pString, *entry, stringLength + 1);

        pArray[i] = pString;
    }
    pArray[stringsCount] = nullptr; // Null-terminate the array

    mObjectIdToArrayMap[objectId][tagName] = (const char **)pArray; // map objectId and tagName to array of string copies

    return (const char **)pArray;
}

void StringStorageCore::Invalidate(const unsigned long objectId)
{
#ifdef TRACE_SSC
    std::fprintf(stderr, "SSC::Invalidate(objectId = %lu)\n", objectId);
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
    const auto objectString = ToString::FromDataPointer(object);
    std::fprintf(stderr, "SSC::FinalizeObject(objectId = %lu, object = %s)\n", objectId, objectString.c_str());
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
    return Change(object, tagName, string.c_str());
}

const char *StringStorageCore::Change(const Object *object, Tag tagName, const char *string)
{
#ifdef TRACE_SSC
    const auto objectString = ToString::FromDataPointer(object);
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::Change(object = %s, tag = %s, c-string = %s%s%s)\n", objectString.c_str(), tagString.c_str(),
                 string != nullptr ? "\"" : "", string != nullptr ? string : "nullptr", string != nullptr ? "\"" : "");
#endif

    if (string == nullptr)
    {
        Remove(object, tagName);
        return nullptr;
    }

    ClearGarbage(); // remove garbage strings and string arrays

    // Create copy of string
    const size_t stringLength = std::strlen(string);
    auto pString = new char[stringLength + 1];
    std::memcpy(pString, string, stringLength + 1);

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

    return pString;
}

const char **StringStorageCore::Change(const Object *object, Tag tagName, const std::vector<std::string> &strings)
{
#ifdef TRACE_SSC
    const auto objectString = ToString::FromDataPointer(object);
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::Change(object = %s, tag = %s, strings.size() = %zu)\n", objectString.c_str(), tagString.c_str(),
                 strings.size());
#endif

    auto pStrings = new const char *[strings.size() + 1];
    for (size_t i = 0; i < strings.size(); ++i)
        pStrings[i] = strings[i].c_str();
    pStrings[strings.size()] = nullptr;

    const char **result = Change(object, tagName, pStrings);
    delete[] pStrings;

    return result;
}

const char **StringStorageCore::Change(const Object *object, Tag tagName, const char *strings[])
{
    if (strings == nullptr)
    {
        Remove(object, tagName);
        return nullptr;
    }

    ClearGarbage(); // remove garbage strings and string arrays

    size_t stringsCount = 0;
    for (const char **entry = strings; *entry != nullptr; ++entry)
        ++stringsCount;

    // Create array of char* pointers (with null terminator)
    auto pArray = new char *[stringsCount + 1];

    // Create copies of individual strings and store pointers
    size_t i = 0;
    for (const char **entry = strings; *entry != nullptr; ++entry, ++i)
    {
        const size_t stringLength = std::strlen(*entry);
        auto pString = new char[stringLength + 1];
        std::memcpy(pString, *entry, stringLength + 1);

        pArray[i] = pString;
    }
    pArray[stringsCount] = nullptr; // Null-terminate the array

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

void StringStorageCore::Remove(const Object *object, Tag tagName)
{
#ifdef TRACE_SSC
    const auto objectString = ToString::FromDataPointer(object);
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::Remove(object = %s, tag = %s)\n", objectString.c_str(), tagString.c_str());
#endif

    ClearGarbage();

    const auto objectKey = reinterpret_cast<uintptr_t>(object);

    const auto &stringOuterIterator = mObjectPtrToMap.find(objectKey);
    if (stringOuterIterator != mObjectPtrToMap.end())
    {
        const auto &stringInnerIterator = stringOuterIterator->second.find(tagName);
        if (stringInnerIterator != stringOuterIterator->second.end())
        {
            mGarbageStrings.push_back(stringInnerIterator->second);
            stringOuterIterator->second.erase(stringInnerIterator);
        }
    }

    const auto &arrayOuterIterator = mObjectPtrToArrayMap.find(objectKey);
    if (arrayOuterIterator != mObjectPtrToArrayMap.end())
    {
        const auto &arrayInnerIterator = arrayOuterIterator->second.find(tagName);
        if (arrayInnerIterator != arrayOuterIterator->second.end())
        {
            mGarbageStringArrays.push_back(arrayInnerIterator->second);
            arrayOuterIterator->second.erase(arrayInnerIterator);
        }
    }
}

void StringStorageCore::Remove(const unsigned long objectId, Tag tagName)
{
#ifdef TRACE_SSC
    const auto tagString = AOS::TagUtil::toString(tagName);
    std::fprintf(stderr, "SSC::Remove(objectId = %lu, tag = %s)\n", objectId, tagString.c_str());
#endif

    if (objectId == 0)
        return;

    ClearGarbage();

    const auto &stringOuterIterator = mObjectIdToMap.find(objectId);
    if (stringOuterIterator != mObjectIdToMap.end())
    {
        const auto &stringInnerIterator = stringOuterIterator->second.find(tagName);
        if (stringInnerIterator != stringOuterIterator->second.end())
        {
            mGarbageStrings.push_back(stringInnerIterator->second);
            stringOuterIterator->second.erase(stringInnerIterator);
        }
    }

    const auto &arrayOuterIterator = mObjectIdToArrayMap.find(objectId);
    if (arrayOuterIterator != mObjectIdToArrayMap.end())
    {
        const auto &arrayInnerIterator = arrayOuterIterator->second.find(tagName);
        if (arrayInnerIterator != arrayOuterIterator->second.end())
        {
            mGarbageStringArrays.push_back(arrayInnerIterator->second);
            arrayOuterIterator->second.erase(arrayInnerIterator);
        }
    }
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
