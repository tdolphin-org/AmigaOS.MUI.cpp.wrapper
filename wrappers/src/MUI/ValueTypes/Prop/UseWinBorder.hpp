//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

namespace MUI
{
    enum class Prop_UseWinBorder
    {
        None = MUIV_Prop_UseWinBorder_None,
        Left = MUIV_Prop_UseWinBorder_Left,
        Right = MUIV_Prop_UseWinBorder_Right,
        Bottom = MUIV_Prop_UseWinBorder_Bottom,
    };
}
