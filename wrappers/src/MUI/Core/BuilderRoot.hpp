//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <string>
#include <vector>

#include "AOS/TagItemObject.hpp"

namespace MUI
{
    Object *muiObject(const std::string &className, const std::vector<AOS::TagItemObject> &tags);
    /// @brief application (internal) mui custom class
    Object *amccObject(const std::string &uniqueId, const std::string &className, const std::vector<AOS::TagItemObject> &tags,
                       const unsigned long dataSize = 0, const void *pDispatcher = nullptr);

    static std::string EmptyUniqueId = "";

    template <typename T> class BuilderRoot
    {
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

        void PushTag(const unsigned long tagName, const void *pointer)
        {
            mTags.push_back(AOS::TagItemObject(tagName, pointer));
        }

        void PushTag(const unsigned long tagName, const char *pString)
        {
            mTags.push_back(AOS::TagItemObject(tagName, (void *)pString));
        }

        void PushTag(const unsigned long tagName, const std::string &string)
        {
            mTags.push_back(AOS::TagItemObject(tagName, (void *)string.c_str()));
        }

        void PushTag(const unsigned long tagName, const unsigned long ulong)
        {
            mTags.push_back(AOS::TagItemObject(tagName, ulong));
        }

        void PushTag(const unsigned long tagName, const long slong)
        {
            mTags.push_back(AOS::TagItemObject(tagName, slong));
        }

        void PushTag(const unsigned long tagName, const bool boolean)
        {
            mTags.push_back(AOS::TagItemObject(tagName, (unsigned long)boolean));
        }

        void PushTag(const unsigned long tagName, const Object *pObject)
        {
            mTags.push_back(AOS::TagItemObject(tagName, (void *)pObject));
        }

        void PushTag(const unsigned long tagName, const void *pArray[])
        {
            mTags.push_back(AOS::TagItemObject(tagName, pArray));
        }

        void PushTag(const unsigned long tagName, const char *pStringArray[])
        {
            mTags.push_back(AOS::TagItemObject(tagName, (void **)pStringArray));
        }
    };
}
