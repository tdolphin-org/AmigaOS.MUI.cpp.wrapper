//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <string>
#include <vector>

#include "TagItemObject.hpp"

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

        std::string ToString() const;

      private:
        std::string TagDataSTRPTR(const ULONG value) const;
        std::string TagDataBool(const ULONG value) const;
    };
}
