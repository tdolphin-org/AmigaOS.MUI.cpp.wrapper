//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Font
    {
        Inherit = MUIV_Font_Inherit, // the same font as the surrounding object, this is the default
        Normal = MUIV_Font_Normal, // the normal font
        List = MUIV_Font_List, // the font configured for lists
        Tiny = MUIV_Font_Tiny, // the tiny font
        Fixed = MUIV_Font_Fixed, // the fixed width font
        Title = MUIV_Font_Title, // the font configured for group titles
        Big = MUIV_Font_Big, // the big font
        Button = MUIV_Font_Button, // the font configured for buttons
        Slider = MUIV_Font_Slider, // the font configured for sliders
        Gauge = MUIV_Font_Gauge, // the font configured for gauges
        Menu = MUIV_Font_Menu, // the font configured for menus
        Tab = MUIV_Font_Tab, // the font configured for tab buttons
        Bubble = MUIV_Font_Bubble, // the font configured for bubble help
        Huge = MUIV_Font_Huge, // the huge font
        Last = MUIV_Font_Last,
        Count = MUIV_Font_Count
    };
}
