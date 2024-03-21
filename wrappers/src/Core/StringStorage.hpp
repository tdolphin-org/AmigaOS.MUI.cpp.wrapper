//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Singleton.hpp"

#include <intuition/classusr.h>
#include <map>
#include <memory>
#include <string>
#include <vector>

/// @brief String Storage Collector (SSC) for strings, collect copies of strings as char*
class StringStorageCore
{
    friend class td::Singleton<StringStorageCore>;

    unsigned long mObjectIdCounter;
    std::vector<std::shared_ptr<char[]>> mGarbageStrings;
    std::map<unsigned long, std::map<unsigned long, std::shared_ptr<char[]>>> mObjectIdToMap; // objectId -> map (tag -> value)
    std::map<unsigned long, std::map<unsigned long, std::shared_ptr<char[]>>> mObjectPtrToMap; // object -> map (tag -> value)

  public:
    StringStorageCore();

    /// @brief add string to SSC for not yet created object for given object od, or 0 to get new id
    /// if there is string for objectId and tagName, methods throws exception
    /// @param objectId object id or 0
    /// @param tagName tag name/id
    /// @param string string to create copy
    /// @return pointer to string copy
    const char *Add(unsigned long &objectId, unsigned long tagName, const std::string &string);
    /// @brief invalidate all strings for not yet created object
    /// @param objectId id of object
    void Invalidate(unsigned long &objectId);
    /// @brief finalize not yet created object with created object, in case of any error throws exception!
    /// @param objectId object id != 0
    /// @param object pointer to created object != nullptr
    void FinalizeObject(unsigned long objectId, const Object *object);
    /// @brief change string for goien object and for givent tag, old string is removed (if exists), created new copy for new string
    /// @param object object ptr
    /// @param tagName tag name/id
    /// @param string new string
    /// @return pointer to string copy
    char *Change(const Object *object, unsigned long tagName, const std::string &string) noexcept;
};

typedef class td::Singleton<StringStorageCore> StringStorage;