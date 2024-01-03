//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class List_Active
    {
        Off = MUIV_List_Active_Off,
        Top = MUIV_List_Active_Top,
        Bottom = MUIV_List_Active_Bottom,
        Up = MUIV_List_Active_Up,
        Down = MUIV_List_Active_Down,
        PageUp = MUIV_List_Active_PageUp,
        PageDown = MUIV_List_Active_PageDown,
    };
}
