//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI
{
    enum class NList_Active
    {
        Off = MUIV_NList_Active_Off,
        Top = MUIV_NList_Active_Top,
        Bottom = MUIV_NList_Active_Bottom,
        Up = MUIV_NList_Active_Up,
        Down = MUIV_NList_Active_Down,
        PageUp = MUIV_NList_Active_PageUp,
        PageDown = MUIV_NList_Active_PageDown,
    };
}
