//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "TagItemObject.hpp"

#include <string>
#include <vector>

namespace AOS
{
    class TagsScope
    {
        TagItem *mpTagItems;
        size_t mSize;

      public:
        TagsScope(const std::vector<TagItemObject> &tags);
        ~TagsScope();

        TagItem *tagItems() const
        {
            return mpTagItems;
        }

        // explicitly no copy
        TagsScope(const TagsScope &) = delete;
        TagsScope &operator=(const TagsScope &) = delete;

        // explicitly no move
        TagsScope(TagsScope &&) = delete;
        TagsScope &operator=(TagsScope &&) = delete;

        size_t size() const
        {
            return mSize;
        }

        /// @brief return tag list with names and values; only part of tags are detected and converted to "name=vale"
        /// @return string like `(MUIA_Application_Author, "author", TAG_END)`
        std::string toString() const;
    };
}
