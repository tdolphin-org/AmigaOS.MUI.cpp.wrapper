//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include <stdexcept>
#include <string>

#include "TagItemObject.hpp"

namespace AOS
{
    TagItemObject::TagItemObject(const unsigned long tagName, const void *pointer)
      : tagName(tagName)
      , tagType(TagType::TagPointer)
      , value((APTR)pointer)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const unsigned long ulong)
      : tagName(tagName)
      , tagType(TagType::TagULong)
      , value((ULONG)ulong)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const long slong)
      : tagName(tagName)
      , tagType(TagType::TagLong)
      , value((LONG)slong)
    {
    }

    TagItemObject::TagItemObject(const unsigned long tagName, const void **pArray)
      : tagName(tagName)
      , tagType(TagType::TagPtrArray)
      , value((APTR *)pArray)
    {
    }

    TagItem TagItemObject::object() const
    {
        struct TagItem tagItem;

        tagItem.ti_Tag = tagName;
        switch (tagType)
        {
            case TagType::TagPointer:
                tagItem.ti_Data = (ULONG)value.pointer;
                break;
            case TagType::TagULong:
                tagItem.ti_Data = value.ulong;
                break;
            case TagType::TagLong:
                tagItem.ti_Data = value.slong;
                break;
            case TagType::TagPtrArray:
                tagItem.ti_Data = (ULONG)value.pArray;
                break;
            default:
                std::string error = (std::string) __PRETTY_FUNCTION__ + " undefined tag type: " + std::to_string(static_cast<int>(tagType));
                throw std::runtime_error(error);
        }

        return tagItem;
    }
}
