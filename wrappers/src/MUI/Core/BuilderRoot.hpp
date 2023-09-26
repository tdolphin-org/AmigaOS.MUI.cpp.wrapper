//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

#include "AOS/TagItemObject.hpp"
#include "Core/ToString.hpp"

namespace MUI
{
    Object *muiObject(const std::string &className, const std::vector<AOS::TagItemObject> &tags);
    /// @brief application (internal) mui custom class
    Object *amccObject(const std::string &uniqueId, const std::string &className, const std::vector<AOS::TagItemObject> &tags,
                       const unsigned long dataSize = 0, const void *pDispatcher = nullptr);

    static std::string EmptyUniqueId = "";

    template <typename T> class BuilderRoot
    {
        std::set<ULONG> mTagKeys;
        std::vector<AOS::TagItemObject> mTags;
        const std::string mClassName;
        /// @brief not empty if class is internal for application, created based od other MUI builtin class
        const std::string mUniqueId;

      public:
        /// @brief
        /// @param uniqueId be default set to empty "", only for internal app class is set
        /// @param className class name: #?.mui, #?.mcc
        BuilderRoot(const std::string &uniqueId, const std::string &className)
          : mUniqueId(uniqueId)
          , mClassName(className)
        {
        }

        T object() const
        {
            return T(mUniqueId.empty() ? muiObject(mClassName, mTags) : amccObject(mUniqueId, mClassName, mTags));
        }

      protected:
        T object(const unsigned long dataSize, const void *pDispatcher) const
        {
            return T(mUniqueId.empty() ? muiObject(mClassName, mTags) : amccObject(mUniqueId, mClassName, mTags, dataSize, pDispatcher));
        }

        void CheckUniqueTag(const unsigned long tagName)
        {
            if (mTagKeys.find(tagName) != mTagKeys.end())
            {
                std::string error = (std::string) __PRETTY_FUNCTION__ + " tag already exists: " + ToString::FromHexValue(tagName);
                std::cerr << error << std::endl;
                throw std::invalid_argument(error);
            }
            mTagKeys.insert(tagName);
        }

        void PushTag(const unsigned long tagName, const void *pointer, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, pointer));
        }

        void PushTag(const unsigned long tagName, const char *pString, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, (void *)pString));
        }

        void PushTag(const unsigned long tagName, const std::string &string, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, (void *)string.c_str()));
        }

        void PushTag(const unsigned long tagName, const unsigned long ulong, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, ulong));
        }

        void PushTag(const unsigned long tagName, const long slong, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, slong));
        }

        void PushTag(const unsigned long tagName, const bool boolean, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, (unsigned long)boolean));
        }

        void PushTag(const unsigned long tagName, const Object *pObject, const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, (void *)pObject));
        }

        void PushTag(const unsigned long tagName, const void *pArray[], const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, pArray));
        }

        void PushTag(const unsigned long tagName, const char *pStringArray[], const bool uniqueTag = true)
        {
            if (uniqueTag)
                CheckUniqueTag(tagName);
            mTags.push_back(AOS::TagItemObject(tagName, (void **)pStringArray));
        }
    };
}
