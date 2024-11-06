//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "TagUtil.hpp"

#include "Core/ToString.hpp"

#include <libraries/asl.h>
#include <libraries/mui.h>
#include <mui/TextEditor_mcc.h>

#define MAP_PAIR(A, B) { A, { #A, B } }

namespace AOS
{
    std::map<Tag, TagUtil::TagSpec> TagUtil::mNames = {

        // Application
        MAP_PAIR(MUIA_Application_Active, ValueType::Bool),
        MAP_PAIR(MUIA_Application_Author, ValueType::String),
        MAP_PAIR(MUIA_Application_Base, ValueType::Bool),
        MAP_PAIR(MUIA_Application_Broker, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_BrokerHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_BrokerPort, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_BrokerPri, ValueType::Long),
        MAP_PAIR(MUIA_Application_Commands, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_Copyright, ValueType::String),
        MAP_PAIR(MUIA_Application_Description, ValueType::String),
        MAP_PAIR(MUIA_Application_DiskObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_DoubleStart, ValueType::Bool),
        MAP_PAIR(MUIA_Application_DropObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_ForceQuit, ValueType::Bool),
        MAP_PAIR(MUIA_Application_HelpFile, ValueType::String),
        MAP_PAIR(MUIA_Application_Iconified, ValueType::Bool),
#ifdef MUIA_Application_IconifyTitle
        MAP_PAIR(MUIA_Application_IconifyTitle, ValueType::String),
#endif
        MAP_PAIR(MUIA_Application_Menu, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_MenuAction, ValueType::ULong),
        MAP_PAIR(MUIA_Application_MenuHelp, ValueType::ULong),
        MAP_PAIR(MUIA_Application_Menustrip, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_RexxHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_RexxMsg, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_RexxString, ValueType::String),
        MAP_PAIR(MUIA_Application_SingleTask, ValueType::Bool),
        MAP_PAIR(MUIA_Application_Sleep, ValueType::Bool),
        MAP_PAIR(MUIA_Application_Title, ValueType::String),
        MAP_PAIR(MUIA_Application_UseCommodities, ValueType::Bool),
#ifdef MUIA_Application_UsedClasses
        MAP_PAIR(MUIA_Application_UsedClasses, ValueType::StringArray),
#endif
        MAP_PAIR(MUIA_Application_UseRexx, ValueType::Bool),
#ifdef MUIA_Application_UseScreenNotify
        MAP_PAIR(MUIA_Application_UseScreenNotify, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Application_Version, ValueType::String),
        MAP_PAIR(MUIA_Application_Window, ValueType::Pointer),
        MAP_PAIR(MUIA_Application_WindowList, ValueType::Pointer),

        // Window
        MAP_PAIR(MUIA_Window_Activate, ValueType::Bool),
        MAP_PAIR(MUIA_Window_ActiveObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_AltHeight, ValueType::Long),
        MAP_PAIR(MUIA_Window_AltLeftEdge, ValueType::Long),
        MAP_PAIR(MUIA_Window_AltTopEdge, ValueType::Long),
        MAP_PAIR(MUIA_Window_AltWidth, ValueType::Long),
        MAP_PAIR(MUIA_Window_AppWindow, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Backdrop, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Borderless, ValueType::Bool),
        MAP_PAIR(MUIA_Window_CloseGadget, ValueType::Bool),
        MAP_PAIR(MUIA_Window_CloseRequest, ValueType::Bool),
        MAP_PAIR(MUIA_Window_DefaultObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_DepthGadget, ValueType::Bool),
#ifdef MUIA_Window_DisableKeys
        MAP_PAIR(MUIA_Window_DisableKeys, ValueType::ULong),
#endif
        MAP_PAIR(MUIA_Window_DragBar, ValueType::Pointer),
#ifdef MUIA_Window_DrawInfo
        MAP_PAIR(MUIA_Window_DrawInfo, ValueType::Pointer),
#endif
        MAP_PAIR(MUIA_Window_FancyDrawing, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Height, ValueType::Long),
        MAP_PAIR(MUIA_Window_ID, ValueType::ULong),
        MAP_PAIR(MUIA_Window_InputEvent, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_IsSubWindow, ValueType::Bool),
        MAP_PAIR(MUIA_Window_LeftEdge, ValueType::Long),
        MAP_PAIR(MUIA_Window_Menu, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_MenuAction, ValueType::ULong),
        MAP_PAIR(MUIA_Window_Menustrip, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_MouseObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_NeedsMouseObject, ValueType::Bool),
        MAP_PAIR(MUIA_Window_NoMenus, ValueType::Bool),
#ifdef MUIA_Window_Opacity
        MAP_PAIR(MUIA_Window_Opacity, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Window_Open, ValueType::Bool),
        MAP_PAIR(MUIA_Window_PublicScreen, ValueType::String),
        MAP_PAIR(MUIA_Window_RefWindow, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_RootObject, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_Screen, ValueType::Pointer),
        MAP_PAIR(MUIA_Window_ScreenTitle, ValueType::String),
        MAP_PAIR(MUIA_Window_SizeGadget, ValueType::Bool),
        MAP_PAIR(MUIA_Window_SizeRight, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Sleep, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Title, ValueType::String),
        MAP_PAIR(MUIA_Window_TopEdge, ValueType::Long),
        MAP_PAIR(MUIA_Window_UseBottomBorderScroller, ValueType::Bool),
        MAP_PAIR(MUIA_Window_UseLeftBorderScroller, ValueType::Bool),
        MAP_PAIR(MUIA_Window_UseRightBorderScroller, ValueType::Bool),
        MAP_PAIR(MUIA_Window_Width, ValueType::Long),
        MAP_PAIR(MUIA_Window_Window, ValueType::Pointer),

        // Area
        MAP_PAIR(MUIA_Background, ValueType::Long),
        MAP_PAIR(MUIA_BottomEdge, ValueType::Long),
        MAP_PAIR(MUIA_ContextMenu, ValueType::Pointer),
#ifdef MUIA_ContextMenuHook
        MAP_PAIR(MUIA_ContextMenuHook, ValueType::Pointer),
#endif
        MAP_PAIR(MUIA_ContextMenuTrigger, ValueType::Pointer),
        MAP_PAIR(MUIA_ControlChar, ValueType::Char),
        MAP_PAIR(MUIA_CycleChain, ValueType::Long),
        MAP_PAIR(MUIA_Disabled, ValueType::Bool),
#ifdef MUIA_DoubleBuffer
        MAP_PAIR(MUIA_DoubleBuffer, ValueType::Bool),
#endif
#ifdef MUIA_DoubleClick
        MAP_PAIR(MUIA_DoubleClick, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Draggable, ValueType::Bool),
        MAP_PAIR(MUIA_Dropable, ValueType::Bool),
        MAP_PAIR(MUIA_ExportID, ValueType::ULong),
        MAP_PAIR(MUIA_FillArea, ValueType::Bool),
        MAP_PAIR(MUIA_FixHeight, ValueType::Long),
        MAP_PAIR(MUIA_FixHeightTxt, ValueType::String),
        MAP_PAIR(MUIA_FixWidth, ValueType::Long),
        MAP_PAIR(MUIA_FixWidthTxt, ValueType::String),
#ifdef MUIA_Floating
        MAP_PAIR(MUIA_Floating, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Font, ValueType::Pointer),
        MAP_PAIR(MUIA_Frame, ValueType::Long),
#ifdef MUIA_FrameDynamic
        MAP_PAIR(MUIA_FrameDynamic, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_FramePhantomHoriz, ValueType::Bool),
        MAP_PAIR(MUIA_FrameTitle, ValueType::String),
#ifdef MUIA_FrameVisible
        MAP_PAIR(MUIA_FrameVisible, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Height, ValueType::Long),
        MAP_PAIR(MUIA_HorizDisappear, ValueType::Long),
        MAP_PAIR(MUIA_HorizWeight, ValueType::Word),
        MAP_PAIR(MUIA_InnerBottom, ValueType::Long),
        MAP_PAIR(MUIA_InnerLeft, ValueType::Long),
        MAP_PAIR(MUIA_InnerRight, ValueType::Long),
        MAP_PAIR(MUIA_InnerTop, ValueType::Long),
        MAP_PAIR(MUIA_InputMode, ValueType::Long),
#ifdef MUIA_KnowsDisabled
        MAP_PAIR(MUIA_KnowsDisabled, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_LeftEdge, ValueType::Long),
        MAP_PAIR(MUIA_MaxHeight, ValueType::Long),
        MAP_PAIR(MUIA_MaxWidth, ValueType::Long),
#ifdef MUIA_MinHeight
        MAP_PAIR(MUIA_MinHeight, ValueType::Long),
#endif
#ifdef MUIA_MinWidth
        MAP_PAIR(MUIA_MinWidth, ValueType::Long),
#endif
#ifdef MUIA_PointerType
        MAP_PAIR(MUIA_PointerType, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Pressed, ValueType::Bool),
        MAP_PAIR(MUIA_RightEdge, ValueType::Long),
        MAP_PAIR(MUIA_Selected, ValueType::Bool),
        MAP_PAIR(MUIA_ShortHelp, ValueType::String),
        MAP_PAIR(MUIA_ShowMe, ValueType::Bool),
        MAP_PAIR(MUIA_ShowSelState, ValueType::Bool),
#ifdef MUIA_TextColor
        MAP_PAIR(MUIA_TextColor, ValueType::ULong),
#endif
        MAP_PAIR(MUIA_Timer, ValueType::Long),
        MAP_PAIR(MUIA_TopEdge, ValueType::Long),
        MAP_PAIR(MUIA_VertDisappear, ValueType::Long),
        MAP_PAIR(MUIA_VertWeight, ValueType::Word),
        MAP_PAIR(MUIA_Weight, ValueType::Word),
        MAP_PAIR(MUIA_Width, ValueType::Long),
        MAP_PAIR(MUIA_Window, ValueType::Pointer),
        MAP_PAIR(MUIA_WindowObject, ValueType::Pointer),

        // Balance
#ifdef MUIA_Balance_Quiet
        MAP_PAIR(MUIA_Balance_Quiet, ValueType::Long),
#endif

        // Family
        MAP_PAIR(MUIA_Family_Child, ValueType::Pointer),
#ifdef MUIA_Family_ChildCount
        MAP_PAIR(MUIA_Family_ChildCount, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Family_List, ValueType::Pointer),

        // Floattext
        MAP_PAIR(MUIA_Floattext_Justify, ValueType::Bool),
#ifdef MUIA_Floattext_KeepStyles
        MAP_PAIR(MUIA_Floattext_KeepStyles, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Floattext_SkipChars, ValueType::String),
        MAP_PAIR(MUIA_Floattext_TabSize, ValueType::Long),
        MAP_PAIR(MUIA_Floattext_Text, ValueType::String),

        // Group
        MAP_PAIR(MUIA_Group_ActivePage, ValueType::Long),
        MAP_PAIR(MUIA_Group_Child, ValueType::Pointer),
#ifdef MUIA_Group_ChildCount
        MAP_PAIR(MUIA_Group_ChildCount, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Group_ChildList, ValueType::Pointer),
        MAP_PAIR(MUIA_Group_Columns, ValueType::Long),
#ifdef MUIA_Group_Forward
        MAP_PAIR(MUIA_Group_Forward, ValueType::Bool),
#endif
#ifdef MUIA_Group_ForwardDepth
        MAP_PAIR(MUIA_Group_ForwardDepth, ValueType::ULong),
#endif
        MAP_PAIR(MUIA_Group_Horiz, ValueType::Bool),
#ifdef MUIA_Group_HorizCenter
        MAP_PAIR(MUIA_Group_HorizCenter, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Group_HorizSpacing, ValueType::Long),
        MAP_PAIR(MUIA_Group_LayoutHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Group_PageMode, ValueType::Bool),
        MAP_PAIR(MUIA_Group_Rows, ValueType::Long),
        MAP_PAIR(MUIA_Group_SameHeight, ValueType::Bool),
        MAP_PAIR(MUIA_Group_SameSize, ValueType::Bool),
        MAP_PAIR(MUIA_Group_SameWidth, ValueType::Bool),
        MAP_PAIR(MUIA_Group_Spacing, ValueType::Long),
#ifdef MUIA_Group_VertCenter
        MAP_PAIR(MUIA_Group_VertCenter, ValueType::Long),
#endif
        MAP_PAIR(MUIA_Group_VertSpacing, ValueType::Long),

        // Image
#ifdef MUIA_Image_BuiltinSpec
        MAP_PAIR(MUIA_Image_BuiltinSpec, ValueType::ULong),
#endif
#ifdef MUIA_Image_CopySpec
        MAP_PAIR(MUIA_Image_CopySpec, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Image_FontMatch, ValueType::Bool),
        MAP_PAIR(MUIA_Image_FontMatchHeight, ValueType::Bool),
#ifdef MUIA_Image_FontMatchString
        MAP_PAIR(MUIA_Image_FontMatchString, ValueType::String),
#endif
        MAP_PAIR(MUIA_Image_FontMatchWidth, ValueType::Bool),
        MAP_PAIR(MUIA_Image_FreeHoriz, ValueType::Bool),
        MAP_PAIR(MUIA_Image_FreeVert, ValueType::Bool),
        MAP_PAIR(MUIA_Image_OldImage, ValueType::Pointer),
        MAP_PAIR(MUIA_Image_Spec, ValueType::String),
        MAP_PAIR(MUIA_Image_State, ValueType::Long),

        // List
        MAP_PAIR(MUIA_List_Active, ValueType::Long),
        MAP_PAIR(MUIA_List_AdjustHeight, ValueType::Bool),
        MAP_PAIR(MUIA_List_AdjustWidth, ValueType::Bool),
#ifdef MUIA_List_AgainClick
        MAP_PAIR(MUIA_List_AgainClick, ValueType::Bool),
#endif
#ifdef MUIA_List_AutoLineHeight
        MAP_PAIR(MUIA_List_AutoLineHeight, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_List_AutoVisible, ValueType::Bool),
#ifdef MUIA_List_ClickColumn
        MAP_PAIR(MUIA_List_ClickColumn, ValueType::Long),
#endif
#ifdef MUIA_List_ColumnOrder
        MAP_PAIR(MUIA_List_ColumnOrder, ValueType::Byte),
#endif
        MAP_PAIR(MUIA_List_CompareHook, ValueType::Pointer),
        MAP_PAIR(MUIA_List_ConstructHook, ValueType::Pointer),
#ifdef MUIA_List_DefClickColumn
        MAP_PAIR(MUIA_List_DefClickColumn, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_DestructHook, ValueType::Pointer),
        MAP_PAIR(MUIA_List_DisplayHook, ValueType::Pointer),
#ifdef MUIA_List_DoubleClick
        MAP_PAIR(MUIA_List_DoubleClick, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_List_DragSortable, ValueType::Bool),
#ifdef MUIA_List_DragType
        MAP_PAIR(MUIA_List_DragType, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_DropMark, ValueType::Long),
#ifdef MUIA_List_Editable
        MAP_PAIR(MUIA_List_Editable, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_List_Entries, ValueType::Long),
        MAP_PAIR(MUIA_List_First, ValueType::Long),
        MAP_PAIR(MUIA_List_Format, ValueType::String),
#ifdef MUIA_List_HideColumn
        MAP_PAIR(MUIA_List_HideColumn, ValueType::Long),
#endif
#ifdef MUIA_List_HScrollerVisibility
        MAP_PAIR(MUIA_List_HScrollerVisibility, ValueType::Long),
#endif
#ifdef MUIA_List_Input
        MAP_PAIR(MUIA_List_Input, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_List_InsertPosition, ValueType::Long),
#ifdef MUIA_List_LineHeight
        MAP_PAIR(MUIA_List_LineHeight, ValueType::ULong),
#endif
#ifdef MUIA_List_MaxColumns
        MAP_PAIR(MUIA_List_MaxColumns, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_MinLineHeight, ValueType::Long),
#ifdef MUIA_List_MultiSelect
        MAP_PAIR(MUIA_List_MultiSelect, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_MultiTestHook, ValueType::Pointer),
        MAP_PAIR(MUIA_List_Pool, ValueType::Pointer),
        MAP_PAIR(MUIA_List_PoolPuddleSize, ValueType::ULong),
        MAP_PAIR(MUIA_List_PoolThreshSize, ValueType::ULong),
        MAP_PAIR(MUIA_List_Quiet, ValueType::Bool),
#ifdef MUIA_List_ScrollerPos
        MAP_PAIR(MUIA_List_ScrollerPos, ValueType::Long),
#endif
#ifdef MUIA_List_SelectChange
        MAP_PAIR(MUIA_List_SelectChange, ValueType::Bool),
#endif
#ifdef MUIA_List_ShowColumn
        MAP_PAIR(MUIA_List_ShowColumn, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_ShowDropMarks, ValueType::Bool),
#ifdef MUIA_List_SortColumn
        MAP_PAIR(MUIA_List_SortColumn, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_SourceArray, ValueType::Pointer),
#ifdef MUIA_List_Stripes
        MAP_PAIR(MUIA_List_Stripes, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_List_Title, ValueType::String),
#ifdef MUIA_List_TitleArray
        MAP_PAIR(MUIA_List_TitleArray, ValueType::StringArray),
#endif
#ifdef MUIA_List_TitleClick
        MAP_PAIR(MUIA_List_TitleClick, ValueType::Long),
#endif
#ifdef MUIA_List_TopPixel
        MAP_PAIR(MUIA_List_TopPixel, ValueType::Long),
#endif
#ifdef MUIA_List_TotalPixel
        MAP_PAIR(MUIA_List_TotalPixel, ValueType::Long),
#endif
        MAP_PAIR(MUIA_List_Visible, ValueType::Long),
#ifdef MUIA_List_VisiblePixel
        MAP_PAIR(MUIA_List_VisiblePixel, ValueType::Long),
#endif

    // Menu
#ifdef MUIA_Menuitem_AISSName
        MAP_PAIR(MUIA_Menuitem_AISSName, ValueType::String),
#endif
        MAP_PAIR(MUIA_Menuitem_Checked, ValueType::Bool),
        MAP_PAIR(MUIA_Menuitem_Checkit, ValueType::Bool),
        MAP_PAIR(MUIA_Menuitem_CommandString, ValueType::Bool),
#ifdef MUIA_Menuitem_CopyStrings
        MAP_PAIR(MUIA_Menuitem_CopyStrings, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Menuitem_Enabled, ValueType::Bool),
        MAP_PAIR(MUIA_Menuitem_Exclude, ValueType::Long),
#ifdef MUIA_Menuitem_FreeImage
        MAP_PAIR(MUIA_Menuitem_FreeImage, ValueType::Bool),
#endif
#ifdef MUIA_Menuitem_Image
        MAP_PAIR(MUIA_Menuitem_Image, ValueType::Pointer),
#endif
#ifdef MUIA_Menuitem_Menuitem
        MAP_PAIR(MUIA_Menuitem_Menuitem, ValueType::Pointer),
#endif
        MAP_PAIR(MUIA_Menuitem_Shortcut, ValueType::String),
        MAP_PAIR(MUIA_Menuitem_Title, ValueType::String),
        MAP_PAIR(MUIA_Menuitem_Toggle, ValueType::Bool),
        MAP_PAIR(MUIA_Menuitem_Trigger, ValueType::Pointer),

        // Notify
        MAP_PAIR(MUIA_ApplicationObject, ValueType::Pointer),
        MAP_PAIR(MUIA_AppMessage, ValueType::Pointer),
        MAP_PAIR(MUIA_HelpLine, ValueType::Long),
        MAP_PAIR(MUIA_HelpNode, ValueType::String),
        MAP_PAIR(MUIA_NoNotify, ValueType::Bool),
#ifdef MUIA_NoNotifyMethod
        MAP_PAIR(MUIA_NoNotifyMethod, ValueType::ULong),
#endif
        MAP_PAIR(MUIA_ObjectID, ValueType::ULong),
        MAP_PAIR(MUIA_Parent, ValueType::Pointer),
        MAP_PAIR(MUIA_Revision, ValueType::Long),
        MAP_PAIR(MUIA_UserData, ValueType::ULong),
        MAP_PAIR(MUIA_Version, ValueType::Long),

        // Popasl
        MAP_PAIR(MUIA_Popasl_Active, ValueType::Bool),
        MAP_PAIR(MUIA_Popasl_StartHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Popasl_StopHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Popasl_Type, ValueType::ULong),

        // Popstring
        MAP_PAIR(MUIA_Popstring_Button, ValueType::Pointer),
        MAP_PAIR(MUIA_Popstring_CloseHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Popstring_OpenHook, ValueType::Pointer),
        MAP_PAIR(MUIA_Popstring_String, ValueType::Pointer),
        MAP_PAIR(MUIA_Popstring_Toggle, ValueType::Bool),

        // Rectangle
        MAP_PAIR(MUIA_Rectangle_BarTitle, ValueType::String),
        MAP_PAIR(MUIA_Rectangle_HBar, ValueType::Bool),
        MAP_PAIR(MUIA_Rectangle_VBar, ValueType::Bool),

    // Scrollbar
#ifdef MUIA_Scrollbar_IncDecSize
        MAP_PAIR(MUIA_Scrollbar_IncDecSize, ValueType::ULong),
#endif
        MAP_PAIR(MUIA_Scrollbar_Type, ValueType::Long),

        // String
        MAP_PAIR(MUIA_String_Accept, ValueType::String),
        MAP_PAIR(MUIA_String_Acknowledge, ValueType::String),
        MAP_PAIR(MUIA_String_AdvanceOnCR, ValueType::Bool),
        MAP_PAIR(MUIA_String_AttachedList, ValueType::Pointer),
        MAP_PAIR(MUIA_String_BufferPos, ValueType::Long),
        MAP_PAIR(MUIA_String_Contents, ValueType::String),
        MAP_PAIR(MUIA_String_DisplayPos, ValueType::Long),
        MAP_PAIR(MUIA_String_EditHook, ValueType::Pointer),
        MAP_PAIR(MUIA_String_Format, ValueType::Long),
#ifdef MUIA_String_InactiveContents
        MAP_PAIR(MUIA_String_InactiveContents, ValueType::String),
#endif
        MAP_PAIR(MUIA_String_Integer, ValueType::ULong),
#ifdef MUIA_String_Integer64
        MAP_PAIR(MUIA_String_Integer64, ValueType::Int64Pointer),
#endif
        MAP_PAIR(MUIA_String_LonelyEditHook, ValueType::Bool),
        MAP_PAIR(MUIA_String_MaxLen, ValueType::Long),
#ifdef MUIA_String_Placeholder
        MAP_PAIR(MUIA_String_Placeholder, ValueType::String),
#endif
        MAP_PAIR(MUIA_String_Reject, ValueType::String),
        MAP_PAIR(MUIA_String_Secret, ValueType::Bool),

        // Text
        MAP_PAIR(MUIA_Text_Contents, ValueType::String),
#ifdef MUIA_Text_ControlChar
        MAP_PAIR(MUIA_Text_ControlChar, ValueType::Char),
#endif
#ifdef MUIA_Text_Copy
        MAP_PAIR(MUIA_Text_Copy, ValueType::Bool),
#endif
#ifdef MUIA_Text_Data
        MAP_PAIR(MUIA_Text_Data, ValueType::Pointer),
#endif
        MAP_PAIR(MUIA_Text_HiChar, ValueType::Char),
#ifdef MUIA_Text_Marking
        MAP_PAIR(MUIA_Text_Marking, ValueType::Bool),
#endif
        MAP_PAIR(MUIA_Text_PreParse, ValueType::String),
        MAP_PAIR(MUIA_Text_SetMax, ValueType::Bool),
        MAP_PAIR(MUIA_Text_SetMin, ValueType::Bool),
        MAP_PAIR(MUIA_Text_SetVMax, ValueType::Bool),
#ifdef MUIA_Text_Shorten
        MAP_PAIR(MUIA_Text_Shorten, ValueType::Long),
#endif
#ifdef MUIA_Text_Shortened
        MAP_PAIR(MUIA_Text_Shortened, ValueType::Bool),
#endif

        // ASL
        MAP_PAIR(ASLFR_TextAttr, ValueType::Pointer),
        MAP_PAIR(ASLFR_Locale, ValueType::Pointer),
        MAP_PAIR(ASLFR_TitleText, ValueType::String),
        MAP_PAIR(ASLFR_PositiveText, ValueType::String),
        MAP_PAIR(ASLFR_NegativeText, ValueType::String),

        MAP_PAIR(ASLFR_DrawersOnly, ValueType::Bool),
        MAP_PAIR(ASLFR_FilterFunc, ValueType::Pointer),
        MAP_PAIR(ASLFR_RejectIcons, ValueType::Bool),
        MAP_PAIR(ASLFR_RejectPattern, ValueType::String),
        MAP_PAIR(ASLFR_AcceptPattern, ValueType::String),
        MAP_PAIR(ASLFR_FilterDrawers, ValueType::Bool),
        MAP_PAIR(ASLFR_HookFunc, ValueType::Pointer)
    };

    std::string TagUtil::toString(const Tag tagName)
    {
        auto tag = mNames.find(tagName);
        if (tag != mNames.end())
            return tag->second.tagName;

        return ToString::FromHexValue(tagName);
    }

    std::string TagUtil::toString(const TagItem &tagItem)
    {
        auto tag = mNames.find(tagItem.ti_Tag);
        if (tag != mNames.end())
        {
            return tag->second.tagName + "=" + [&]() {
                switch (tag->second.valueType)
                {
                    case ValueType::String:
                        return TagDataSTRPTR(tagItem.ti_Data);
                    case ValueType::StringArray:
                        return ToString::FromHexValue(tagItem.ti_Tag); // TODO show list of strings
                    case ValueType::Bool:
                        return TagDataBool(tagItem.ti_Data);
                    case ValueType::Byte:
                        return std::to_string((signed char)tagItem.ti_Data);
                    case ValueType::Char:
                        return TagDataChar(tagItem.ti_Data);
                    case ValueType::Word:
                        return std::to_string((short)tagItem.ti_Data);
                    case ValueType::Long:
                        return std::to_string((long)tagItem.ti_Data);
                    case ValueType::ULong:
                        return std::to_string(tagItem.ti_Data);
                    case ValueType::Pointer:
                        return ToString::FromHexValue(tagItem.ti_Data);
                    case ValueType::Int64Pointer:
                        return ToString::FromHexValue(tagItem.ti_Data); // TODO show hex value of 64bit int
                    default:
                        return std::to_string(tagItem.ti_Data);
                }
            }();
        }

        return ToString::FromHexValue(tagItem.ti_Tag) + "=" + std::to_string(tagItem.ti_Data);
    }

    std::string TagUtil::TagDataSTRPTR(const ULONG value)
    {
        return "\"" + std::string((const char *)value) + "\"";
    }

    std::string TagUtil::TagDataBool(const ULONG value)
    {
        return value == TRUE ? "TRUE" : "FALSE";
    }

    std::string TagUtil::TagDataChar(const ULONG value)
    {
        return std::string("'") + (char)value + "'";
    }
}
