//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include <sstream>

#include <libraries/asl.h>
#include <libraries/mui.h>
#include <mui/TextEditor_mcc.h>

#include "AOS/Identifier.hpp"
#include "Core/ToString.hpp"
#include "TagsScope.hpp"

namespace AOS
{
    TagsScope::TagsScope(const std::vector<TagItemObject> &tags)
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
        std::string result = "(";
        for (int i = 0; mpTagItems[i].ti_Tag != TAG_END; i++)
        {
            auto tagName = mpTagItems[i].ti_Tag;
            auto tagValue = mpTagItems[i].ti_Data;
            switch (tagName)
            {
                // Application
                case MUIA_Application_Author:
                    result += "MUIA_Application_Author";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_Base:
                    result += "MUIA_Application_Base";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_Copyright:
                    result += "MUIA_Application_Copyright";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_Description:
                    result += "MUIA_Application_Description";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_Title:
                    result += "MUIA_Application_Title";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_UsedClasses:
                    result += "MUIA_Application_UsedClasses";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_Application_Version:
                    result += "MUIA_Application_Version";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Application_Window:
                    result += "MUIA_Application_Window";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // Window
                case MUIA_Window_AltHeight:
                    result += "MUIA_Window_AltHeight";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Window_AltWidth:
                    result += "MUIA_Window_AltWidth";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Window_Height:
                    result += "MUIA_Window_Height";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Window_ID:
                    result += "MUIA_Window_ID";
                    result += "=" + Identifier(tagValue).toString();
                    break;
                case MUIA_Window_RootObject:
                    result += "MUIA_Window_RootObject";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_Window_ScreenTitle:
                    result += "MUIA_Window_ScreenTitle";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Window_Title:
                    result += "MUIA_Window_Title";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Window_Width:
                    result += "MUIA_Window_Width";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Area
                case MUIA_Background:
                    result += "MUIA_Background";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_CycleChain:
                    result += "MUIA_CycleChain";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_FillArea:
                    result += "MUIA_FillArea";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_FixHeight:
                    result += "MUIA_FixHeight";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_FixHeightTxt:
                    result += "MUIA_FixHeightTxt";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_FixWidth:
                    result += "MUIA_FixWidth";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_FixWidthTxt:
                    result += "MUIA_FixWidthTxt";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Floating:
                    result += "MUIA_Floating";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Frame:
                    result += "MUIA_Frame";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_FrameTitle:
                    result += "MUIA_FrameTitle";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Font:
                    result += "MUIA_Font";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_InputMode:
                    result += "MUIA_InputMode";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_Selected:
                    result += "MUIA_Selected";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_ShortHelp:
                    result += "MUIA_ShortHelp";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_ShowSelState:
                    result += "MUIA_ShowSelState";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Weight:
                    result += "MUIA_Weight";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Balance
                case MUIA_Balance_Quiet:
                    result += "MUIA_Balance_Quiet";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Family
                case MUIA_Family_Child:
                    result += "MUIA_Family_Child";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // Floattext
                case MUIA_Floattext_TabSize:
                    result += "MUIA_Floattext_TabSize";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Floattext_Text:
                    result += "MUIA_Floattext_Text";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;

                // Group
                case MUIA_Group_Child:
                    result += "MUIA_Group_Child";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_Group_Columns:
                    result += "MUIA_Group_Columns";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Group_Horiz:
                    result += "MUIA_Group_Horiz";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Group_Rows:
                    result += "MUIA_Group_Rows";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_Group_SameHeight:
                    result += "MUIA_Group_SameHeight";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Group_SameSize:
                    result += "MUIA_Group_SameSize";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Group_SameWidth:
                    result += "MUIA_Group_SameWidth";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Group_Spacing:
                    result += "MUIA_Group_Spacing";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Image
                case MUIA_Image_CopySpec:
                    result += "MUIA_Image_CopySpec";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Image_FreeHoriz:
                    result += "MUIA_Image_FreeHoriz";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Image_FreeVert:
                    result += "MUIA_Image_FreeVert";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Image_Spec:
                    result += "MUIA_Image_Spec";
                    if (tagValue <= MUII_Count)
                        result += "=" + std::to_string(tagValue);
                    else if (((char *)tagValue)[0] == '5' && ((char *)tagValue)[1] == ':')
                        result += "=" + TagDataSTRPTR(tagValue);
                    else
                        result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // List
                case MUIA_List_CompareHook:
                    result += "MUIA_List_CompareHook";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_List_ConstructHook:
                    result += "MUIA_List_ConstructHook";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_List_DestructHook:
                    result += "MUIA_List_DestructHook";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_List_DisplayHook:
                    result += "MUIA_List_DisplayHook";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_List_DragType:
                    result += "MUIA_List_DragType";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_List_DragSortable:
                    result += "MUIA_List_DragSortable";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_List_Format:
                    result += "MUIA_List_Format";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_List_Input:
                    result += "MUIA_List_Input";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_List_SortColumn:
                    result += "MUIA_List_SortColumn";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_List_SourceArray:
                    result += "MUIA_List_SourceArray";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // Menu
                case MUIA_Menuitem_Enabled:
                    result += "MUIA_Menuitem_Enabled";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Menuitem_Title:
                    result += "MUIA_Menuitem_Title";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;

                // Notify
                case MUIA_HelpLine:
                    result += "MUIA_HelpLine";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_UserData:
                    result += "MUIA_UserData";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Popasl
                case MUIA_Popasl_Type:
                    result += "MUIA_Popasl_Type";
                    result += "=" + std::to_string(tagValue);
                    break;

                // Popasl
                case MUIA_Popstring_Button:
                    result += "MUIA_Popstring_Button";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;
                case MUIA_Popstring_String:
                    result += "MUIA_Popstring_String";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // Rectangle
                case MUIA_Rectangle_BarTitle:
                    result += "MUIA_Rectangle_BarTitle";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_Rectangle_HBar:
                    result += "MUIA_Rectangle_HBar";
                    result += "=" + TagDataBool(tagValue);
                    break;
                case MUIA_Rectangle_VBar:
                    result += "MUIA_Rectangle_VBar";
                    result += "=" + TagDataBool(tagValue);
                    break;

                // Scrollbar
                case MUIA_Scrollbar_Type:
                    result += "MUIA_Scrollbar_Type";
                    result += "=" + std::to_string(tagValue);
                    break;

                // String
                case MUIA_String_Contents:
                    result += "MUIA_String_Contents";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;
                case MUIA_String_MaxLen:
                    result += "MUIA_String_MaxLen";
                    result += "=" + std::to_string(tagValue);
                    break;
                case MUIA_String_Placeholder:
                    result += "MUIA_String_Placeholder";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;

                // Text
                case MUIA_Text_Contents:
                    result += "MUIA_Text_Contents";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;

                // TextEditor
                case MUIA_TextEditor_Rows:
                    result += "MUIA_TextEditor_Rows";
                    result += "=" + std::to_string(tagValue);
                    break;

                case MUIA_TextEditor_Slider:
                    result += "MUIA_TextEditor_Slider";
                    result += "=" + ToString::FromHexValue(tagValue);
                    break;

                // ASL
                case ASLFR_TitleText:
                    result += "ASLFR_TitleText";
                    result += "=" + TagDataSTRPTR(tagValue);
                    break;

                case ASLFR_DrawersOnly:
                    result += "ASLFR_DrawersOnly";
                    result += "=" + TagDataBool(tagValue);
                    break;

                default:
                    result += ToString::ToString::FromHexValue(tagName);
            }
            result += ", ";
        }

        result += "TAG_END)";

        return result;
    }

    std::string TagsScope::TagDataSTRPTR(const ULONG value) const
    {
        return "\"" + std::string((const char *)value) + "\"";
    }

    std::string TagsScope::TagDataBool(const ULONG value) const
    {
        return value == TRUE ? "TRUE" : "FALSE";
    }
}
