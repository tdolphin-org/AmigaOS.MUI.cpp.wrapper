//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
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
}
