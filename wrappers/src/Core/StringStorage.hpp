//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/Singleton.hpp"

#include <intuition/classusr.h>
#include <map>
#include <memory>
#include <string>
#include <utility/tagitem.h>
#include <vector>

/// @brief String Storage Collector (SSC), collect copies of strings as char*
class StringStorageCore
{
    friend class td::Singleton<StringStorageCore>;

    unsigned long mObjectIdCounter;
    std::vector<std::shared_ptr<char>> mGarbageStrings;
    std::map<unsigned long, std::map<Tag, std::shared_ptr<char>>> mObjectIdToMap; // objectId -> map (tag -> value)
    std::map<unsigned long, std::map<Tag, std::shared_ptr<char>>> mObjectPtrToMap; // object -> map (tag -> value)

  public:
    StringStorageCore();

    /// @brief add string to SSC for not yet created object for given object id (> 0), or for 0 to generate new id
    /// if string for objectId and tagName already exits, method throws exception
    /// @param objectId object id or 0
    /// @param tagName tag name/id
    /// @param string string to create copy
    /// @return pointer to string copy
    const char *Add(unsigned long &objectId, Tag tagName, const std::string &string);
    /// @brief invalidate (erase) all strings for not yet created object
    /// @param objectId id of object
    void Invalidate(const unsigned long objectId);
    /// @brief finalize not yet created object id with created object ptr, in case of any error throws exception
    /// @param objectId object id != 0
    /// @param object pointer to created object != nullptr
    void FinalizeObject(const unsigned long objectId, const Object *object);
    /// @brief change string for given object and for given tag, old string is removed (if exists), created new copy for new string
    /// @param object object ptr
    /// @param tagName tag name/id
    /// @param string new string
    /// @return pointer to string copy
    char *Change(const Object *object, Tag tagName, const std::string &string);
};

typedef class td::Singleton<StringStorageCore> StringStorage;