//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

#undef End

namespace MUI
{
    enum class NList_Jump
    {
        Top = MUIV_NList_Jump_Top,
        Active = MUIV_NList_Jump_Active,
        Bottom = MUIV_NList_Jump_Bottom,
        Down = MUIV_NList_Jump_Down,
        Up = MUIV_NList_Jump_Up,
        Active_Center = MUIV_NList_Jump_Active_Center,
    };
}
