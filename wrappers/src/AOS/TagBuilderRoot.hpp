//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AOS/TagItemObject.hpp"

#include <set>
#include <string>
#include <vector>

namespace AOS
{
    class TagBuilderRoot
    {
        std::set<unsigned long> mTagKeys;
        std::vector<AOS::TagItemObject> mTags;

      public:
        void CheckUniqueTag(const unsigned long tagName);

        void PushTag(const unsigned long tagName, const void *pointer, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const char *pString, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const std::string &string, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const unsigned long ulong, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const long slong, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const bool boolean, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const Object *pObject, const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const void *pArray[], const bool uniqueTag = true);
        void PushTag(const unsigned long tagName, const char *pStringArray[], const bool uniqueTag = true);

        const std::vector<AOS::TagItemObject> &getTags() const
        {
            return mTags;
        }
    };
}
