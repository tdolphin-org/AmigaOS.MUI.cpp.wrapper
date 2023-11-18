//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
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

      public:
        TagsScope(const std::vector<TagItemObject> &tags);
        ~TagsScope();

        TagItem *tagItems() const
        {
            return mpTagItems;
        }

        /// @brief return tag list with names and values; only part of tags are detected and converted to "name=vale"
        /// @return string like `(MUIA_Application_Author, "author", TAG_END)`
        std::string toString() const;

      private:
        std::string TagDataSTRPTR(const ULONG value) const;
        std::string TagDataBool(const ULONG value) const;
    };
}
