//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

namespace MUI
{
    // MUIV_Font_* are typed differently per platform: AmigaOS/MorphOS use plain negative
    // ints (e.g. -1) while AROS Zune casts them as ((IPTR)-1) (64-bit unsigned). Normalizing
    // each enumerator through static_cast<int> makes it fit the default (int) underlying type
    // on every target; the resulting value (e.g. -1) matches the (long) casts used at call sites.
    enum class Font
    {
        Inherit = static_cast<int>(MUIV_Font_Inherit), // the same font as the surrounding object, this is the default
        Normal = static_cast<int>(MUIV_Font_Normal), // the normal font
        List = static_cast<int>(MUIV_Font_List), // the font configured for lists
        Tiny = static_cast<int>(MUIV_Font_Tiny), // the tiny font
        Fixed = static_cast<int>(MUIV_Font_Fixed), // the fixed width font
        Title = static_cast<int>(MUIV_Font_Title), // the font configured for group titles
        Big = static_cast<int>(MUIV_Font_Big), // the big font
        Button = static_cast<int>(MUIV_Font_Button), // the font configured for buttons
#ifdef MUIV_Font_Slider
        Slider = static_cast<int>(MUIV_Font_Slider), // the font configured for sliders
        Gauge = static_cast<int>(MUIV_Font_Gauge), // the font configured for gauges
        Menu = static_cast<int>(MUIV_Font_Menu), // the font configured for menus
        Tab = static_cast<int>(MUIV_Font_Tab), // the font configured for tab buttons
        Bubble = static_cast<int>(MUIV_Font_Bubble), // the font configured for bubble help
        Huge = static_cast<int>(MUIV_Font_Huge), // the huge font
        Last = static_cast<int>(MUIV_Font_Last),
        Count = static_cast<int>(MUIV_Font_Count),
#endif
    };
}
