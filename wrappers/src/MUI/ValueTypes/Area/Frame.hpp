//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Frame
    {
        None = MUIV_Frame_None,
        Button = MUIV_Frame_Button, // for standard buttons with text in it
        ImageButton = MUIV_Frame_ImageButton, // for small buttons with images, e.g. the arrows of a scrollbar
        Text = MUIV_Frame_Text, // for a text field, e.g. a status line display
        String = MUIV_Frame_String, // for a string gadget
        ReadList = MUIV_Frame_ReadList, // for a read only list
        InputList = MUIV_Frame_InputList, // for a list that handles input (has a cursor)
        Prop = MUIV_Frame_Prop, // for proportional gadgets
        Gauge = MUIV_Frame_Gauge,
        Group = MUIV_Frame_Group, // for groups
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
}
