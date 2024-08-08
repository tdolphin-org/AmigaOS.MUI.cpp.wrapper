//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "StringStorage.hpp"

#include "AOS/TagUtil.hpp"
#include "ToString.hpp"

#include <cstring>
#include <stdexcept>

#ifdef TRACE_SSC
#include <iostream>
#endif

StringStorageCore::StringStorageCore()
  : mObjectIdCounter(0)
{
}

const char *StringStorageCore::Add(unsigned long &objectId, Tag tagName, const std::string &string)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Add(objectId = " << objectId << ", tag = " << AOS::TagUtil::toString(tagName) << ", string = \"" << string << "\")"
              << std::endl;
#endif
    if (objectId == 0)
        objectId = ++mObjectIdCounter;

    auto pString = std::shared_ptr<char>(new char[string.size() + 1], std::default_delete<char[]>());
    std::memcpy(pString.get(), string.c_str(), string.size() + 1);

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator != mObjectIdToMap.end())
        if (outerIterator->second.find(tagName) != outerIterator->second.end())
        {
            auto error = "String Storage Collector: Add(" + std::to_string(objectId) + "," + AOS::TagUtil::toString(tagName) + "," + string
                + ") .. tagName for objectId already exists!";
            throw new std::runtime_error(error);
        }

    mObjectIdToMap[objectId][tagName] = pString;

    return (char *)pString.get();
}

void StringStorageCore::Invalidate(const unsigned long objectId)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Invalidate(objectId = " << objectId << ")" << std::endl;
#endif

    if (objectId == 0)
    {
        auto error = "String Storage Collector: Invalidate(" + std::to_string(objectId) + ") .. objectId == 0!";
        throw new std::runtime_error(error);
    }

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator == mObjectIdToMap.end())
    {
        auto error = "String Storage Collector: Invalidate(" + std::to_string(objectId) + ") .. map not found for objectId!";
        throw new std::runtime_error(error);
    }

    mObjectIdToMap.erase(outerIterator);
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
        throw new std::runtime_error(error);
    }

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator == mObjectIdToMap.end())
    {
        auto error = "String Storage Collector: FinalizeObject(" + std::to_string(objectId) + ") .. map not found for objectId!";
        throw new std::runtime_error(error);
    }

    // copy to final object
    for (const auto &elem : outerIterator->second)
        mObjectPtrToMap[reinterpret_cast<uintptr_t>(object)][elem.first] = elem.second;

    mObjectIdToMap.erase(outerIterator);
}

char *StringStorageCore::Change(const Object *object, Tag tagName, const std::string &string)
{
#ifdef TRACE_SSC
    std::cout << "SSC::Change(object = " << ToString::FromDataPointer(object) << ", tag = " << AOS::TagUtil::toString(tagName)
              << ", string = \"" << string << "\")" << std::endl;
#endif

    mGarbageStrings.clear(); // remove garbage strings

    auto pString = std::shared_ptr<char>(new char[string.size() + 1], std::default_delete<char[]>());
    std::memcpy(pString.get(), string.c_str(), string.size() + 1);

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

    return (char *)pString.get();
}
