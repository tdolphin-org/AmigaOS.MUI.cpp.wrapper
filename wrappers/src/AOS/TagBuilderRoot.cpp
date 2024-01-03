//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "TagBuilderRoot.hpp"

#include "TagUtil.hpp"

#include <iostream>

namespace AOS
{
    void TagBuilderRoot::CheckUniqueTag(const unsigned long tagName)
    {
        if (mTagKeys.find(tagName) != mTagKeys.end())
        {
            std::string error
                = (std::string) __PRETTY_FUNCTION__ + " tag " + AOS::TagUtil::toString(tagName) + " already added by TagBuilder!";
            std::cerr << error << std::endl; // FIXME remove it, after catching exceptions will start to work
            throw std::invalid_argument(error);
        }
        mTagKeys.insert(tagName);
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const void *pointer, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, pointer));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const char *pString, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, (void *)pString));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const std::string &string, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, (void *)string.c_str()));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const unsigned long ulong, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, ulong));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const long slong, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, slong));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const bool boolean, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, (unsigned long)boolean));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const Object *pObject, const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, (void *)pObject));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const void *pArray[], const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, pArray));
    }

    void TagBuilderRoot::PushTag(const unsigned long tagName, const char *pStringArray[], const bool uniqueTag)
    {
        if (uniqueTag)
            CheckUniqueTag(tagName);
        mTags.push_back(TagItemObject(tagName, (void **)pStringArray));
    }
}
