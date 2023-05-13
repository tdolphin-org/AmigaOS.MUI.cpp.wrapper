//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <intuition/classusr.h>

namespace AOS
{
    class ValueObject
    {
        enum class ValueType
        {
            ValueULong,
            ValueLong,
            ValuePointer,
            ValuePtrArray,
        };

        const ValueType mType;
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
        } mValue;

      public:
        ValueObject(const void *pointer);
        ValueObject(const unsigned long ulong);
        ValueObject(const long slong);
        ValueObject(const void **pArray);

        ULONG value() const;
    };
}
