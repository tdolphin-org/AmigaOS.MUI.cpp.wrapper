//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "TagsScope.hpp"
#include "AOS/Identifier.hpp"
#include "Core/ToString.hpp"
#include "TagUtil.hpp"

#include <sstream>

#include <libraries/asl.h>
#include <libraries/mui.h>
#include <mui/TextEditor_mcc.h>

namespace AOS
{
    TagsScope::TagsScope(const std::vector<TagItemObject> &tags)
      : mSize(tags.size() + 1)
    {
        mpTagItems = new TagItem[tags.size() + 1];
        for (int i = 0; i < tags.size(); i++)
            mpTagItems[i] = tags[i].object();
        mpTagItems[tags.size()].ti_Tag = TAG_END;
    }

    TagsScope::~TagsScope()
    {
        if (mpTagItems)
            delete[] mpTagItems;
    }

    TagsScope::TagsScope(const TagsScope &other) noexcept
      : mSize(other.mSize)
    {
        mpTagItems = new TagItem[mSize];
        memcpy(mpTagItems, other.mpTagItems, sizeof(TagItem));
    }

    TagsScope &TagsScope::operator=(const TagsScope &other) noexcept
    {
        mpTagItems = new TagItem[mSize];
        memcpy(mpTagItems, other.mpTagItems, sizeof(TagItem));

        return *this;
    }

    TagsScope::TagsScope(TagsScope &&other) noexcept
      : mpTagItems(other.mpTagItems)
    {
        other.mpTagItems = nullptr;
        mSize = 0;
    }

    TagsScope &TagsScope::operator=(TagsScope &&other) noexcept
    {
        if (this != &other)
        {
            mpTagItems = other.mpTagItems;
            other.mpTagItems = nullptr;
            mSize = 0;
        }

        return *this;
    }

    std::string TagsScope::toString() const
    {
        if (mpTagItems)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " mpTagItems is null, object probably in undefined state!";
            throw new std::runtime_error(error);
        }

        std::stringstream result;

        result << "(";
        for (int i = 0; mpTagItems[i].ti_Tag != TAG_END; i++)
        {
            auto tagName = mpTagItems[i].ti_Tag;
            auto tagValue = mpTagItems[i].ti_Data;

            switch (tagName)
            {
                case MUIA_Image_Spec:
                    result << TagUtil::toString(tagName);
                    if (tagValue <= MUII_Count)
                        result << "=" + std::to_string(tagValue);
                    else if (((char *)tagValue)[0] == '5' && ((char *)tagValue)[1] == ':')
                        result << "=" + TagUtil::TagDataSTRPTR(tagValue);
                    else
                        result << "=" + ToString::FromHexValue(tagValue);
                    break;

                // TextEditor
                case MUIA_TextEditor_Rows:
                    result << TagUtil::toString(tagName) << "=" + tagValue;
                    break;

                case MUIA_TextEditor_Slider:
                    result << TagUtil::toString(tagName) << "=" + ToString::FromHexValue(tagValue);
                    break;

                default:
                    result << TagUtil::toString(mpTagItems[i]);
            }
            result << ", ";
        }

        result << "TAG_END)";

        return result.str();
    }

}
