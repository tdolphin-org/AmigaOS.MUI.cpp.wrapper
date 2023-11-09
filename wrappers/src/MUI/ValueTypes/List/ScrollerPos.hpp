//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class List_ScrollerPos
    {
        Default = MUIV_List_ScrollerPos_Default,
        Left = MUIV_List_ScrollerPos_Left,
        Right = MUIV_List_ScrollerPos_Right,
        None = MUIV_List_ScrollerPos_None,
    };
}
