//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Notify.hpp"

#undef Enable
#undef Disable

namespace MUI
{
    enum class Font
    {
        Inherit = MUIV_Font_Inherit,
        Normal = MUIV_Font_Normal,
        List = MUIV_Font_List,
        Tiny = MUIV_Font_Tiny,
        Fixed = MUIV_Font_Fixed,
        Title = MUIV_Font_Title,
        Big = MUIV_Font_Big,
        Button = MUIV_Font_Button,
        Slider = MUIV_Font_Slider,
        Gauge = MUIV_Font_Gauge,
        Menu = MUIV_Font_Menu,
        Tab = MUIV_Font_Tab,
        Bubble = MUIV_Font_Bubble,
        Huge = MUIV_Font_Huge,
        Last = MUIV_Font_Last,
        Count = MUIV_Font_Count
    };

    enum class Frame
    {
        None = MUIV_Frame_None,
        Button = MUIV_Frame_Button,
        ImageButton = MUIV_Frame_ImageButton,
        Text = MUIV_Frame_Text,
        String = MUIV_Frame_String,
        ReadList = MUIV_Frame_ReadList,
        InputList = MUIV_Frame_InputList,
        Prop = MUIV_Frame_Prop,
        Gauge = MUIV_Frame_Gauge,
        Group = MUIV_Frame_Group,
        PopUp = MUIV_Frame_PopUp,
        Virtual = MUIV_Frame_Virtual,
        Slider = MUIV_Frame_Slider,
        SliderKnob = MUIV_Frame_SliderKnob,
        GaugeInner = MUIV_Frame_GaugeInner,
        Menudisplay = MUIV_Frame_Menudisplay,
        MenudisplayMenu = MUIV_Frame_MenudisplayMenu,
        PropKnob = MUIV_Frame_PropKnob,
        Window = MUIV_Frame_Window,
        Requester = MUIV_Frame_Requester,
        Page = MUIV_Frame_Page,
        Register = MUIV_Frame_Register,
        GroupTitle = MUIV_Frame_GroupTitle,
        RegisterTitle = MUIV_Frame_RegisterTitle,
        Count = MUIV_Frame_Count
    };

    enum class InputMode
    {
        None = MUIV_InputMode_None,
        RelVerify = MUIV_InputMode_RelVerify,
        Immediate = MUIV_InputMode_Immediate,
        Toggle = MUIV_InputMode_Toggle
    };

#ifndef __MORPHOS__
    enum class PointerType
    {
        Parent = MUIV_PointerType_Parent,
        Normal = MUIV_PointerType_Normal,
        Busy = MUIV_PointerType_Busy,
        Alias = MUIV_PointerType_Alias,
        Cell = MUIV_PointerType_Cell,
        ColumnResize = MUIV_PointerType_ColumnResize,
        ContextMenu = MUIV_PointerType_ContextMenu,
        Copy = MUIV_PointerType_Copy,
        Cross = MUIV_PointerType_Cross,
        DragAndDrop = MUIV_PointerType_DragAndDrop,
        EastResize = MUIV_PointerType_EastResize,
        EastWestResize = MUIV_PointerType_EastWestResize,
        Hand = MUIV_PointerType_Hand,
        Help = MUIV_PointerType_Help,
        Link = MUIV_PointerType_Link,
        Menu = MUIV_PointerType_Menu,
        NoDrop = MUIV_PointerType_NoDrop,
        None = MUIV_PointerType_None,
        NorthEastResize = MUIV_PointerType_NorthEastResize,
        NorthEastSouthWestResize = MUIV_PointerType_NorthEastSouthWestResize,
        NorthResize = MUIV_PointerType_NorthResize,
        NorthSouthResize = MUIV_PointerType_NorthSouthResize,
        NorthWestResize = MUIV_PointerType_NorthWestResize,
        NorthWestSouthEastResize = MUIV_PointerType_NorthWestSouthEastResize,
        NotAllowed = MUIV_PointerType_NotAllowed,
        Progress = MUIV_PointerType_Progress,
        RowResize = MUIV_PointerType_RowResize,
        ScrollAll = MUIV_PointerType_ScrollAll,
        SouthEastResize = MUIV_PointerType_SouthEastResize,
        SouthResize = MUIV_PointerType_SouthResize,
        SouthWestResize = MUIV_PointerType_SouthWestResize,
        Text = MUIV_PointerType_Text,
        VerticalText = MUIV_PointerType_VerticalText,
        WestResize = MUIV_PointerType_WestResize,
        ZoomIn = MUIV_PointerType_ZoomIn,
        ZoomOut = MUIV_PointerType_ZoomOut,
        Pen = MUIV_PointerType_Pen,
        Rotate = MUIV_PointerType_Rotate,
        Rubber = MUIV_PointerType_Rubber,
        Select = MUIV_PointerType_Select,
        Smudge = MUIV_PointerType_Smudge,
        Count = MUIV_PointerType_Count
    };
#endif

    enum class ImageOrBackground
    {
        WindowBack = MUII_WindowBack,
        RequesterBack = MUII_RequesterBack,
        ButtonBack = MUII_ButtonBack,
        ListBack = MUII_ListBack,
        TextBack = MUII_TextBack,
        PropBack = MUII_PropBack,
        PopupBack = MUII_PopupBack,
        SelectedBack = MUII_SelectedBack,
        ListCursor = MUII_ListCursor,
        ListSelect = MUII_ListSelect,
        ListSelCur = MUII_ListSelCur,
        ArrowUp = MUII_ArrowUp,
        ArrowDown = MUII_ArrowDown,
        ArrowLeft = MUII_ArrowLeft,
        ArrowRight = MUII_ArrowRight,
        CheckMark = MUII_CheckMark,
        RadioButton = MUII_RadioButton,
        Cycle = MUII_Cycle,
        PopUp = MUII_PopUp,
        PopFile = MUII_PopFile,
        PopDrawer = MUII_PopDrawer,
        PropKnob = MUII_PropKnob,
        Drawer = MUII_Drawer,
        HardDisk = MUII_HardDisk,
        Disk = MUII_Disk,
        Chip = MUII_Chip,
        Volume = MUII_Volume,
        RegisterBack = MUII_RegisterBack,
        Network = MUII_Network,
        Assign = MUII_Assign,
        TapePlay = MUII_TapePlay,
        TapePlayBack = MUII_TapePlayBack,
        TapePause = MUII_TapePause,
        TapeStop = MUII_TapeStop,
        TapeRecord = MUII_TapeRecord,
        GroupBack = MUII_GroupBack,
        SliderBack = MUII_SliderBack,
        SliderKnob = MUII_SliderKnob,
        TapeUp = MUII_TapeUp,
        TapeDown = MUII_TapeDown,
        PageBack = MUII_PageBack,
        ReadListBack = MUII_ReadListBack,
        PopFont = MUII_PopFont,
        ImageButtonBack = MUII_ImageButtonBack,
        ImageSelectedBack = MUII_ImageSelectedBack,
        GaugeFull = MUII_GaugeFull,
        GaugeEmpty = MUII_GaugeEmpty,
        Menudisplay = MUII_Menudisplay,
        PullOpen = MUII_PullOpen,
        StringBack = MUII_StringBack,
        StringActiveBack = MUII_StringActiveBack,
        ListTitle = MUII_ListTitle,
        GroupTitle = MUII_GroupTitle,
        RegisterTitle = MUII_RegisterTitle,
        Close = MUII_Close,
        Count = MUII_Count
    };

    class Area : public Notify
    {
      public:
        Area(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Area(const Root &root)
          : Notify(root.muiObject())
        {
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Selected ]
        bool getSelected() const;

        /// @brief [ @b MUIA_Disabled ]
        Area &setDisabled(const bool disabled);
        /// @brief [ @b MUIA_Font ] - seems that setting font doesn't work (at least for MUI::Floattext)
        Area &setFont(const enum Font font);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        Area &setPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_Selected ]
        Area &setSelected(const bool selected);
        /// @brief [ @b MUIA_ShortHelp ]
        Area &setShortHelp(const std::string &shortHelp);

        // methods, some can return object reference

        /// @brief setDisabled(false)
        Area &Enable();
        /// @brief setDisabled(true)
        Area &Disable();
    };

    template <typename T, typename U> class AreaBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        AreaBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Area)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Background ]
        T &tagBackground(const enum ImageOrBackground background);
        /// @brief [ @b MUIA_CycleChain ]
        T &tagCycleChain(const long cycleChain);
        /// @brief [ @b MUIA_Disabled ]
        T &tagDisabled(const bool disabled = true);
        /// @brief [ @b MUIA_Frame ]
        /// @param frame enum Frame
        T &tagFrame(const enum Frame frame);
        /// @brief [ @b MUIA_FrameTitle ]
        T &tagFrameTitle(char *frameTitle);
        /// @brief [ @b MUIA_Font] (for "struct TextFont *" should be separate method)
        /// @param font enum Font
        T &tagFont(const enum Font font);
        /// @brief [ @b MUIA_InputMode ]
        /// @param inputMode enum InputMode
        T &tagInputMode(const enum InputMode inputMode);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_PointerType ]
        /// @param font enum PointerType
        T &tagPointerType(const enum PointerType pointerType);
#endif
        /// @brief [ @b MUIA_ShortHelp ]
        T &tagShortHelp(const std::string &shortHelp);
        /// @brief [ @b MUIA_Weight ]
        T &tagWeight(const long weight);
    };

    class AreaBuilder : public AreaBuilderTemplate<AreaBuilder, Area>
    {
      public:
        AreaBuilder();
    };

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagBackground(const enum ImageOrBackground background)
    {
        this->PushTag(MUIA_Background, (long)background);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagCycleChain(const long cycleChain)
    {
        this->PushTag(MUIA_CycleChain, cycleChain);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagDisabled(const bool disabled)
    {
        this->PushTag(MUIA_Disabled, disabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFrame(const enum Frame frame)
    {
        this->PushTag(MUIA_Frame, (long)frame);
        return (T &)*this;
    }

    template <typename T, typename U> T &AreaBuilderTemplate<T, U>::tagFrameTitle(char *frameTitle)
    {
        this->PushTag(MUIA_FrameTitle, frameTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagFont(const enum Font font)
    {
        this->PushTag(MUIA_Font, (long)font);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagInputMode(const enum InputMode inputMode)
    {
        this->PushTag(MUIA_InputMode, (long)inputMode);
        return (T &)*this;
    }

#ifndef __MORPHOS__
    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagPointerType(const PointerType pointerType)
    {
        this->PushTag(MUIA_PointerType, (long)pointerType);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagShortHelp(const std::string &shortHelp)
    {
        this->PushTag(MUIA_ShortHelp, shortHelp);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &AreaBuilderTemplate<T, U>::tagWeight(const long weight)
    {
        this->PushTag(MUIA_Weight, weight);
        return (T &)*this;
    }
}
