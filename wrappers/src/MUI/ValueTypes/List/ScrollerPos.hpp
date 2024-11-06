//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIA_List_ScrollerPos

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

#endif
