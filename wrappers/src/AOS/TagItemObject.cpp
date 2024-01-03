//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "TagItemObject.hpp"

#include <stdexcept>
#include <string>

namespace AOS
{
    TagItemObject::TagItemObject(const unsigned long tagName, const void *pointer)
      : mTagName(tagName)
      , mValueObject(pointer)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const unsigned long ulong)
      : mTagName(tagName)
      , mValueObject(ulong)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const long slong)
      : mTagName(tagName)
      , mValueObject(slong)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const void **pArray)
      : mTagName(tagName)
      , mValueObject(pArray)
    {
    }

    TagItem TagItemObject::object() const
    {
        struct TagItem tagItem;

        tagItem.ti_Tag = mTagName;
        tagItem.ti_Data = mValueObject.value();

        return tagItem;
    }
}
