//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include <string>

#include <intuition/classusr.h>
#include <utility/tagitem.h>

namespace AOS
{
    class TagItemObject
    {
        enum class TagType
        {
            TagULong,
            TagLong,
            TagPointer,
            TagPtrArray,
        };

        const ULONG tagName;
        const TagType tagType;
        union Value
        {
            const APTR pointer;
            const ULONG ulong;
            const LONG slong;
            const APTR *pArray;

            Value(const APTR pointer)
              : pointer(pointer)
            {
            }
            Value(const ULONG ulong)
              : ulong(ulong)
            {
            }
            Value(const LONG slong)
              : slong(slong)
            {
            }
            Value(const APTR *pArray)
              : pArray(pArray)
            {
            }

        } value;

      public:
        TagItemObject(const unsigned long tagName, const void *pointer);
        TagItemObject(const unsigned long tagName, const unsigned long ulong);
        TagItemObject(const unsigned long tagName, const long slong);
        TagItemObject(const unsigned long tagName, const void **pArray);

        struct TagItem object() const;
    };
}
