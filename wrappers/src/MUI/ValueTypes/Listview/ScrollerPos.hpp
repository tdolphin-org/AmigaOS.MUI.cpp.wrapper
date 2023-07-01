//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Listview_ScrollerPos
    {
        Default = MUIV_Listview_ScrollerPos_Default,
        Left = MUIV_Listview_ScrollerPos_Left,
        Right = MUIV_Listview_ScrollerPos_Right,
        None = MUIV_Listview_ScrollerPos_None,
    };
}
