//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "ValueObject.hpp"

#include <stdexcept>
#include <string>

namespace AOS
{
    ValueObject::ValueObject(const void *pointer)
      : mType(ValueType::ValuePointer)
      , mValue((APTR)pointer)
    {
    }

    ValueObject::ValueObject(const unsigned long ulong)
      : mType(ValueType::ValueULong)
      , mValue((ULONG)ulong)
    {
    }

    ValueObject::ValueObject(const long slong)
      : mType(ValueType::ValueLong)
      , mValue((LONG)slong)
    {
    }

    ValueObject::ValueObject(const void **pArray)
      : mType(ValueType::ValuePtrArray)
      , mValue((APTR *)pArray)
    {
    }

    ValueObject::ValueObject(const bool boolval)
      : mType(ValueType::ValueULong)
      , mValue((ULONG)boolval)
    {
    }

    ULONG ValueObject::value() const
    {
        switch (mType)
        {
            case ValueType::ValuePointer:
                return (ULONG)mValue.pointer;
            case ValueType::ValueULong:
                return mValue.ulong;
            case ValueType::ValueLong:
                return mValue.slong;
            case ValueType::ValuePtrArray:
                return (ULONG)mValue.pArray;
            default:
                auto error = std::string { __PRETTY_FUNCTION__ } + " undefined type: " + std::to_string(static_cast<int>(mType));
                throw std::runtime_error(error);
        }
    }
}
