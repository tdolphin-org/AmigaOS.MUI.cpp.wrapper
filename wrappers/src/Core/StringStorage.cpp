//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "StringStorage.hpp"

#include <cstring>
#include <stdexcept>

StringStorageCore::StringStorageCore()
  : mObjectIdCounter(0)
{
}

const char *StringStorageCore::Add(unsigned long &objectId, unsigned long tagName, const std::string &string)
{
    if (objectId == 0)
        objectId = ++mObjectIdCounter;

    auto pString = std::shared_ptr<char>(new char[string.size() + 1], std::default_delete<char[]>());
    std::memcpy(pString.get(), string.c_str(), string.size() + 1);

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator != mObjectIdToMap.end())
        if (outerIterator->second.find(tagName) != outerIterator->second.end())
        {
            std::string error = "String Storage Collector: Add(" + std::to_string(objectId) + "," + std::to_string(tagName) + "," + string
                + ") .. tagName for objectId already exists!";
            throw new std::runtime_error(error);
        }

    mObjectIdToMap[objectId][tagName] = pString;

    return (char *)pString.get();
}

void StringStorageCore::Invalidate(unsigned long &objectId)
{
    if (objectId == 0)
    {
        std::string error = "String Storage Collector: Invalidate(" + std::to_string(objectId) + ") .. objectId == 0!";
        throw new std::runtime_error(error);
    }

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator == mObjectIdToMap.end())
    {
        std::string error = "String Storage Collector: Invalidate(" + std::to_string(objectId) + ") .. map not found for objectId!";
        throw new std::runtime_error(error);
    }

    mObjectIdToMap.erase(outerIterator);
}

void StringStorageCore::FinalizeObject(unsigned long objectId, const Object *object)
{
    if (objectId == 0 || object == nullptr)
    {
        std::string error = "String Storage Collector: FinalizeObject(" + std::to_string(objectId) + ","
            + std::to_string(reinterpret_cast<uintptr_t>(object)) + ") .. objectId == 0 or object is nullptr!";
        throw new std::runtime_error(error);
    }

    const auto &outerIterator = mObjectIdToMap.find(objectId);
    if (outerIterator == mObjectIdToMap.end())
    {
        std::string error = "String Storage Collector: FinalizeObject(" + std::to_string(objectId) + ") .. map not found for objectId!";
        throw new std::runtime_error(error);
    }

    // copy to final object
    for (const auto &elem : outerIterator->second)
        mObjectPtrToMap[reinterpret_cast<uintptr_t>(object)][elem.first] = elem.second;

    mObjectIdToMap.erase(outerIterator);
}

char *StringStorageCore::Change(const Object *object, unsigned long tagName, const std::string &string) noexcept
{
    mGarbageStrings.clear(); // remove garbage strings

    auto pString = std::shared_ptr<char>(new char[string.size() + 1], std::default_delete<char[]>());

    const auto &outerIterator = mObjectPtrToMap.find(reinterpret_cast<uintptr_t>(object));
    if (outerIterator != mObjectPtrToMap.end())
    {
        const auto &innerIterator = outerIterator->second.find(tagName);
        if (innerIterator != outerIterator->second.end())
            mGarbageStrings.push_back(innerIterator->second); // can't be removed now, becouse still is used, move pointer to garbage
    }

    mObjectIdToMap[reinterpret_cast<uintptr_t>(object)][tagName] = pString;

    return (char *)pString.get();
}
