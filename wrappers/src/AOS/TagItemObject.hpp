//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <utility/tagitem.h>

#include "ValueObject.hpp"

namespace AOS
{
    class TagItemObject
    {
        const unsigned long mTagName;
        ValueObject mValueObject;

      public:
        TagItemObject(const unsigned long tagName, const void *pointer);
        TagItemObject(const unsigned long tagName, const unsigned long ulong);
        TagItemObject(const unsigned long tagName, const long slong);
        TagItemObject(const unsigned long tagName, const void **pArray);

        struct TagItem object() const;
    };
}
