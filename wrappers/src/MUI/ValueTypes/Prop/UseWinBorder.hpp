//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

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
