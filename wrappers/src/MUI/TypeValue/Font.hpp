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
}
