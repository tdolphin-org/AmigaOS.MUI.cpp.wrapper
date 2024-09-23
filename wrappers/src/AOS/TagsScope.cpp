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
        delete[] mpTagItems;
    }

    std::string TagsScope::toString() const
    {
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
