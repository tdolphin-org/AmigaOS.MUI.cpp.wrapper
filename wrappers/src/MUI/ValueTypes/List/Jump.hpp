//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

namespace MUI
{
    enum class List_Jump
    {
        Top = MUIV_List_Jump_Top,
        Active = MUIV_List_Jump_Active,
        Bottom = MUIV_List_Jump_Bottom,
        Up = MUIV_List_Jump_Up,
        Down = MUIV_List_Jump_Down,
    };
}
