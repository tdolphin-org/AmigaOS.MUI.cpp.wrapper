//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "TagUtil.hpp"

#include "Core/ToString.hpp"

#include <libraries/asl.h>
#include <libraries/mui.h>
#include <mui/TextEditor_mcc.h>

#define MAP_PAIR(A) { A, #A }

namespace AOS
{
    std::map<ULONG, std::string> TagUtil::mNames = {

        // Application
        MAP_PAIR(MUIA_Application_Active),
        MAP_PAIR(MUIA_Application_Author),
        MAP_PAIR(MUIA_Application_Base),
        MAP_PAIR(MUIA_Application_Broker),
        MAP_PAIR(MUIA_Application_BrokerHook),
        MAP_PAIR(MUIA_Application_BrokerPort),
        MAP_PAIR(MUIA_Application_BrokerPri),
        MAP_PAIR(MUIA_Application_Commands),
        MAP_PAIR(MUIA_Application_Copyright),
        MAP_PAIR(MUIA_Application_Description),
        MAP_PAIR(MUIA_Application_DiskObject),
        MAP_PAIR(MUIA_Application_DoubleStart),
        MAP_PAIR(MUIA_Application_DropObject),
        MAP_PAIR(MUIA_Application_ForceQuit),
        MAP_PAIR(MUIA_Application_HelpFile),
        MAP_PAIR(MUIA_Application_Iconified),
        MAP_PAIR(MUIA_Application_IconifyTitle),
        MAP_PAIR(MUIA_Application_Menu),
        MAP_PAIR(MUIA_Application_MenuAction),
        MAP_PAIR(MUIA_Application_MenuHelp),
        MAP_PAIR(MUIA_Application_Menustrip),
        MAP_PAIR(MUIA_Application_RexxHook),
        MAP_PAIR(MUIA_Application_RexxMsg),
        MAP_PAIR(MUIA_Application_RexxString),
        MAP_PAIR(MUIA_Application_SingleTask),
        MAP_PAIR(MUIA_Application_Sleep),
        MAP_PAIR(MUIA_Application_Title),
        MAP_PAIR(MUIA_Application_UseCommodities),
        MAP_PAIR(MUIA_Application_UsedClasses),
        MAP_PAIR(MUIA_Application_UseRexx),
        MAP_PAIR(MUIA_Application_UseScreenNotify),
        MAP_PAIR(MUIA_Application_Version),
        MAP_PAIR(MUIA_Application_Window),
        MAP_PAIR(MUIA_Application_WindowList),

        // Window
        MAP_PAIR(MUIA_Window_Activate),
        MAP_PAIR(MUIA_Window_ActiveObject),
        MAP_PAIR(MUIA_Window_AltHeight),
        MAP_PAIR(MUIA_Window_AltLeftEdge),
        MAP_PAIR(MUIA_Window_AltTopEdge),
        MAP_PAIR(MUIA_Window_AltWidth),
        MAP_PAIR(MUIA_Window_AppWindow),
        MAP_PAIR(MUIA_Window_Backdrop),
        MAP_PAIR(MUIA_Window_Borderless),
        MAP_PAIR(MUIA_Window_CloseGadget),
        MAP_PAIR(MUIA_Window_CloseRequest),
        MAP_PAIR(MUIA_Window_DefaultObject),
        MAP_PAIR(MUIA_Window_DepthGadget),
        MAP_PAIR(MUIA_Window_DisableKeys),
        MAP_PAIR(MUIA_Window_DragBar),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Window_DrawInfo),
#endif
        MAP_PAIR(MUIA_Window_FancyDrawing),
        MAP_PAIR(MUIA_Window_Height),
        MAP_PAIR(MUIA_Window_ID),
        MAP_PAIR(MUIA_Window_InputEvent),
        MAP_PAIR(MUIA_Window_IsSubWindow),
        MAP_PAIR(MUIA_Window_LeftEdge),
        MAP_PAIR(MUIA_Window_Menu),
        MAP_PAIR(MUIA_Window_MenuAction),
        MAP_PAIR(MUIA_Window_Menustrip),
        MAP_PAIR(MUIA_Window_MouseObject),
        MAP_PAIR(MUIA_Window_NeedsMouseObject),
        MAP_PAIR(MUIA_Window_NoMenus),
        MAP_PAIR(MUIA_Window_Opacity),
        MAP_PAIR(MUIA_Window_Open),
        MAP_PAIR(MUIA_Window_PublicScreen),
        MAP_PAIR(MUIA_Window_RefWindow),
        MAP_PAIR(MUIA_Window_RootObject),
        MAP_PAIR(MUIA_Window_Screen),
        MAP_PAIR(MUIA_Window_ScreenTitle),
        MAP_PAIR(MUIA_Window_SizeGadget),
        MAP_PAIR(MUIA_Window_SizeRight),
        MAP_PAIR(MUIA_Window_Sleep),
        MAP_PAIR(MUIA_Window_Title),
        MAP_PAIR(MUIA_Window_TopEdge),
        MAP_PAIR(MUIA_Window_UseBottomBorderScroller),
        MAP_PAIR(MUIA_Window_UseLeftBorderScroller),
        MAP_PAIR(MUIA_Window_UseRightBorderScroller),
        MAP_PAIR(MUIA_Window_Width),
        MAP_PAIR(MUIA_Window_Window),

        // Area
        MAP_PAIR(MUIA_Background),
        MAP_PAIR(MUIA_BottomEdge),
        MAP_PAIR(MUIA_ContextMenu),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_ContextMenuHook),
#endif
        MAP_PAIR(MUIA_ContextMenuTrigger),
        MAP_PAIR(MUIA_ControlChar),
        MAP_PAIR(MUIA_CycleChain),
        MAP_PAIR(MUIA_Disabled),
        MAP_PAIR(MUIA_DoubleBuffer),
        MAP_PAIR(MUIA_DoubleClick),
        MAP_PAIR(MUIA_Draggable),
        MAP_PAIR(MUIA_Dropable),
        MAP_PAIR(MUIA_ExportID),
        MAP_PAIR(MUIA_FillArea),
        MAP_PAIR(MUIA_FixHeight),
        MAP_PAIR(MUIA_FixHeightTxt),
        MAP_PAIR(MUIA_FixWidth),
        MAP_PAIR(MUIA_FixWidthTxt),
        MAP_PAIR(MUIA_Floating),
        MAP_PAIR(MUIA_Font),
        MAP_PAIR(MUIA_Frame),
        MAP_PAIR(MUIA_FrameDynamic),
        MAP_PAIR(MUIA_FramePhantomHoriz),
        MAP_PAIR(MUIA_FrameTitle),
        MAP_PAIR(MUIA_FrameVisible),
        MAP_PAIR(MUIA_Height),
        MAP_PAIR(MUIA_HorizDisappear),
        MAP_PAIR(MUIA_HorizWeight),
        MAP_PAIR(MUIA_InnerBottom),
        MAP_PAIR(MUIA_InnerLeft),
        MAP_PAIR(MUIA_InnerRight),
        MAP_PAIR(MUIA_InnerTop),
        MAP_PAIR(MUIA_InputMode),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_KnowsDisabled),
#endif
        MAP_PAIR(MUIA_LeftEdge),
        MAP_PAIR(MUIA_MaxHeight),
        MAP_PAIR(MUIA_MaxWidth),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_MinHeight),
        MAP_PAIR(MUIA_MinWidth),
        MAP_PAIR(MUIA_PointerType),
#endif
        MAP_PAIR(MUIA_Pressed),
        MAP_PAIR(MUIA_RightEdge),
        MAP_PAIR(MUIA_Selected),
        MAP_PAIR(MUIA_ShortHelp),
        MAP_PAIR(MUIA_ShowMe),
        MAP_PAIR(MUIA_ShowSelState),
        MAP_PAIR(MUIA_TextColor),
        MAP_PAIR(MUIA_Timer),
        MAP_PAIR(MUIA_TopEdge),
        MAP_PAIR(MUIA_VertDisappear),
        MAP_PAIR(MUIA_VertWeight),
        MAP_PAIR(MUIA_Weight),
        MAP_PAIR(MUIA_Width),
        MAP_PAIR(MUIA_Window),
        MAP_PAIR(MUIA_WindowObject),

        // Balance
        MAP_PAIR(MUIA_Balance_Quiet),

        // Family
        MAP_PAIR(MUIA_Family_Child),
        MAP_PAIR(MUIA_Family_ChildCount),
        MAP_PAIR(MUIA_Family_List),

        // Floattext
        MAP_PAIR(MUIA_Floattext_Justify),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Floattext_KeepStyles),
#endif
        MAP_PAIR(MUIA_Floattext_SkipChars),
        MAP_PAIR(MUIA_Floattext_TabSize),
        MAP_PAIR(MUIA_Floattext_Text),

        // Group
        MAP_PAIR(MUIA_Group_ActivePage),
        MAP_PAIR(MUIA_Group_Child),
        MAP_PAIR(MUIA_Group_ChildCount),
        MAP_PAIR(MUIA_Group_ChildList),
        MAP_PAIR(MUIA_Group_Columns),
        MAP_PAIR(MUIA_Group_Forward),
        MAP_PAIR(MUIA_Group_ForwardDepth),
        MAP_PAIR(MUIA_Group_Horiz),
        MAP_PAIR(MUIA_Group_HorizCenter),
        MAP_PAIR(MUIA_Group_HorizSpacing),
        MAP_PAIR(MUIA_Group_LayoutHook),
        MAP_PAIR(MUIA_Group_PageMode),
        MAP_PAIR(MUIA_Group_Rows),
        MAP_PAIR(MUIA_Group_SameHeight),
        MAP_PAIR(MUIA_Group_SameSize),
        MAP_PAIR(MUIA_Group_SameWidth),
        MAP_PAIR(MUIA_Group_Spacing),
        MAP_PAIR(MUIA_Group_VertCenter),
        MAP_PAIR(MUIA_Group_VertSpacing),

        // Image
        MAP_PAIR(MUIA_Image_BuiltinSpec),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Image_CopySpec),
#endif
        MAP_PAIR(MUIA_Image_FontMatch),
        MAP_PAIR(MUIA_Image_FontMatchHeight),
        MAP_PAIR(MUIA_Image_FontMatchString),
        MAP_PAIR(MUIA_Image_FontMatchWidth),
        MAP_PAIR(MUIA_Image_FreeHoriz),
        MAP_PAIR(MUIA_Image_FreeVert),
        MAP_PAIR(MUIA_Image_OldImage),
        MAP_PAIR(MUIA_Image_Spec),
        MAP_PAIR(MUIA_Image_State),

        // List
        MAP_PAIR(MUIA_List_Active),
        MAP_PAIR(MUIA_List_AdjustHeight),
        MAP_PAIR(MUIA_List_AdjustWidth),
        MAP_PAIR(MUIA_List_AgainClick),
        MAP_PAIR(MUIA_List_AutoLineHeight),
        MAP_PAIR(MUIA_List_AutoVisible),
        MAP_PAIR(MUIA_List_ClickColumn),
        MAP_PAIR(MUIA_List_ColumnOrder),
        MAP_PAIR(MUIA_List_CompareHook),
        MAP_PAIR(MUIA_List_ConstructHook),
        MAP_PAIR(MUIA_List_DefClickColumn),
        MAP_PAIR(MUIA_List_DestructHook),
        MAP_PAIR(MUIA_List_DisplayHook),
        MAP_PAIR(MUIA_List_DoubleClick),
        MAP_PAIR(MUIA_List_DragSortable),
        MAP_PAIR(MUIA_List_DragType),
        MAP_PAIR(MUIA_List_DropMark),
        MAP_PAIR(MUIA_List_Editable),
        MAP_PAIR(MUIA_List_Entries),
        MAP_PAIR(MUIA_List_First),
        MAP_PAIR(MUIA_List_Format),
        MAP_PAIR(MUIA_List_HideColumn),
        MAP_PAIR(MUIA_List_HScrollerVisibility),
        MAP_PAIR(MUIA_List_Input),
        MAP_PAIR(MUIA_List_InsertPosition),
        MAP_PAIR(MUIA_List_LineHeight),
        MAP_PAIR(MUIA_List_MaxColumns),
        MAP_PAIR(MUIA_List_MinLineHeight),
        MAP_PAIR(MUIA_List_MultiSelect),
        MAP_PAIR(MUIA_List_MultiTestHook),
        MAP_PAIR(MUIA_List_Pool),
        MAP_PAIR(MUIA_List_PoolPuddleSize),
        MAP_PAIR(MUIA_List_PoolThreshSize),
        MAP_PAIR(MUIA_List_Quiet),
        MAP_PAIR(MUIA_List_ScrollerPos),
        MAP_PAIR(MUIA_List_SelectChange),
        MAP_PAIR(MUIA_List_ShowColumn),
        MAP_PAIR(MUIA_List_ShowDropMarks),
        MAP_PAIR(MUIA_List_SortColumn),
        MAP_PAIR(MUIA_List_SourceArray),
        MAP_PAIR(MUIA_List_Stripes),
        MAP_PAIR(MUIA_List_Title),
        MAP_PAIR(MUIA_List_TitleArray),
        MAP_PAIR(MUIA_List_TitleClick),
        MAP_PAIR(MUIA_List_TopPixel),
        MAP_PAIR(MUIA_List_TotalPixel),
        MAP_PAIR(MUIA_List_Visible),
        MAP_PAIR(MUIA_List_VisiblePixel),

        // Menu
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Menuitem_AISSName),
#endif
        MAP_PAIR(MUIA_Menuitem_Checked),
        MAP_PAIR(MUIA_Menuitem_Checkit),
        MAP_PAIR(MUIA_Menuitem_CommandString),
        MAP_PAIR(MUIA_Menuitem_CopyStrings),
        MAP_PAIR(MUIA_Menuitem_Enabled),
        MAP_PAIR(MUIA_Menuitem_Exclude),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Menuitem_FreeImage),
        MAP_PAIR(MUIA_Menuitem_Image),
#endif
        MAP_PAIR(MUIA_Menuitem_Menuitem),
        MAP_PAIR(MUIA_Menuitem_Shortcut),
        MAP_PAIR(MUIA_Menuitem_Title),
        MAP_PAIR(MUIA_Menuitem_Toggle),
        MAP_PAIR(MUIA_Menuitem_Trigger),

        // Notify
        MAP_PAIR(MUIA_ApplicationObject),
        MAP_PAIR(MUIA_AppMessage),
        MAP_PAIR(MUIA_HelpLine),
        MAP_PAIR(MUIA_HelpNode),
        MAP_PAIR(MUIA_NoNotify),
        MAP_PAIR(MUIA_NoNotifyMethod),
        MAP_PAIR(MUIA_ObjectID),
        MAP_PAIR(MUIA_Parent),
        MAP_PAIR(MUIA_Revision),
        MAP_PAIR(MUIA_UserData),
        MAP_PAIR(MUIA_Version),

        // Popasl
        MAP_PAIR(MUIA_Popasl_Active),
        MAP_PAIR(MUIA_Popasl_StartHook),
        MAP_PAIR(MUIA_Popasl_StopHook),
        MAP_PAIR(MUIA_Popasl_Type),

        // Popstring
        MAP_PAIR(MUIA_Popstring_Button),
        MAP_PAIR(MUIA_Popstring_CloseHook),
        MAP_PAIR(MUIA_Popstring_OpenHook),
        MAP_PAIR(MUIA_Popstring_String),
        MAP_PAIR(MUIA_Popstring_Toggle),

        // Rectangle
        MAP_PAIR(MUIA_Rectangle_BarTitle),
        MAP_PAIR(MUIA_Rectangle_HBar),
        MAP_PAIR(MUIA_Rectangle_VBar),

        // Scrollbar
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Scrollbar_IncDecSize),
#endif
        MAP_PAIR(MUIA_Scrollbar_Type),

        // String
        MAP_PAIR(MUIA_String_Accept),
        MAP_PAIR(MUIA_String_Acknowledge),
        MAP_PAIR(MUIA_String_AdvanceOnCR),
        MAP_PAIR(MUIA_String_AttachedList),
        MAP_PAIR(MUIA_String_BufferPos),
        MAP_PAIR(MUIA_String_Contents),
        MAP_PAIR(MUIA_String_DisplayPos),
        MAP_PAIR(MUIA_String_EditHook),
        MAP_PAIR(MUIA_String_Format),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_String_InactiveContents),
#endif
        MAP_PAIR(MUIA_String_Integer),
        MAP_PAIR(MUIA_String_Integer64),
        MAP_PAIR(MUIA_String_LonelyEditHook),
        MAP_PAIR(MUIA_String_MaxLen),
        MAP_PAIR(MUIA_String_Placeholder),
        MAP_PAIR(MUIA_String_Reject),
        MAP_PAIR(MUIA_String_Secret),

        // Text
        MAP_PAIR(MUIA_Text_Contents),
        MAP_PAIR(MUIA_Text_ControlChar),
        MAP_PAIR(MUIA_Text_Copy),
#ifndef __MORPHOS__
        MAP_PAIR(MUIA_Text_Data),
#endif
        MAP_PAIR(MUIA_Text_HiChar),
        MAP_PAIR(MUIA_Text_Marking),
        MAP_PAIR(MUIA_Text_PreParse),
        MAP_PAIR(MUIA_Text_SetMax),
        MAP_PAIR(MUIA_Text_SetMin),
        MAP_PAIR(MUIA_Text_SetVMax),
        MAP_PAIR(MUIA_Text_Shorten),
        MAP_PAIR(MUIA_Text_Shortened),

        // TextEditor
        MAP_PAIR(MUIA_TextEditor_Contents),
        MAP_PAIR(MUIA_TextEditor_CursorX),
        MAP_PAIR(MUIA_TextEditor_CursorY),
        MAP_PAIR(MUIA_TextEditor_DoubleClickHook),
        MAP_PAIR(MUIA_TextEditor_TypeAndSpell),
        MAP_PAIR(MUIA_TextEditor_ExportHook),
        MAP_PAIR(MUIA_TextEditor_ExportWrap),
        MAP_PAIR(MUIA_TextEditor_FixedFont),
        MAP_PAIR(MUIA_TextEditor_Flow),
        MAP_PAIR(MUIA_TextEditor_HasChanged),
        MAP_PAIR(MUIA_TextEditor_Prop_DeltaFactor),
        MAP_PAIR(MUIA_TextEditor_ImportHook),
        MAP_PAIR(MUIA_TextEditor_InsertMode),
        MAP_PAIR(MUIA_TextEditor_ImportWrap),
        MAP_PAIR(MUIA_TextEditor_KeyBindings),
        MAP_PAIR(MUIA_TextEditor_UndoAvailable),
        MAP_PAIR(MUIA_TextEditor_RedoAvailable),
        MAP_PAIR(MUIA_TextEditor_AreaMarked),
        MAP_PAIR(MUIA_TextEditor_Prop_Entries),
        MAP_PAIR(MUIA_TextEditor_Prop_Visible),
        MAP_PAIR(MUIA_TextEditor_Quiet),
        MAP_PAIR(MUIA_TextEditor_NumLock),
        MAP_PAIR(MUIA_TextEditor_ReadOnly),
        MAP_PAIR(MUIA_TextEditor_Slider),
        MAP_PAIR(MUIA_TextEditor_InVirtualGroup),
        MAP_PAIR(MUIA_TextEditor_StyleBold),
        MAP_PAIR(MUIA_TextEditor_StyleItalic),
        MAP_PAIR(MUIA_TextEditor_StyleUnderline),
        MAP_PAIR(MUIA_TextEditor_Prop_First),
        MAP_PAIR(MUIA_TextEditor_WrapBorder),
        MAP_PAIR(MUIA_TextEditor_Separator),
        MAP_PAIR(MUIA_TextEditor_Pen),
        MAP_PAIR(MUIA_TextEditor_ColorMap),
        MAP_PAIR(MUIA_TextEditor_MultiColorQuoting),
        MAP_PAIR(MUIA_TextEditor_Rows),
        MAP_PAIR(MUIA_TextEditor_Columns),
        MAP_PAIR(MUIA_TextEditor_AutoClip),
        MAP_PAIR(MUIA_TextEditor_CursorPosition),
        MAP_PAIR(MUIA_TextEditor_KeyUpFocus),
        MAP_PAIR(MUIA_TextEditor_UndoLevels),
        MAP_PAIR(MUIA_TextEditor_WrapMode),
        MAP_PAIR(MUIA_TextEditor_ActiveObjectOnClick),
        MAP_PAIR(MUIA_TextEditor_PasteStyles),
        MAP_PAIR(MUIA_TextEditor_PasteColors),
        MAP_PAIR(MUIA_TextEditor_ConvertTabs),
        MAP_PAIR(MUIA_TextEditor_WrapWords),
        MAP_PAIR(MUIA_TextEditor_TabSize),
        MAP_PAIR(MUIA_TextEditor_Keywords),
        MAP_PAIR(MUIA_TextEditor_MatchedKeyword),
        MAP_PAIR(MUIA_TextEditor_CursorIndex),
        MAP_PAIR(MUIA_TextEditor_RGBMode),
        MAP_PAIR(MUIA_TextEditor_HorizontalSlider),
        MAP_PAIR(MUIA_TextEditor_GlobalFlow),
        MAP_PAIR(MUIA_TextEditor_ContentsChanged),
        MAP_PAIR(MUIA_TextEditor_MetaDataChanged),
        MAP_PAIR(MUIA_TextEditor_InactiveContents),

        // ASL
        MAP_PAIR(ASLFR_TextAttr),
        MAP_PAIR(ASLFR_Locale),
        MAP_PAIR(ASLFR_TitleText),
        MAP_PAIR(ASLFR_PositiveText),
        MAP_PAIR(ASLFR_NegativeText),
    };

    std::string TagUtil::ToString(const ULONG tagName)
    {
        auto tag = mNames.find(tagName);
        if (tag != mNames.end())
            return tag->second;

        return ToString::FromHexValue(tagName);
    }
}
