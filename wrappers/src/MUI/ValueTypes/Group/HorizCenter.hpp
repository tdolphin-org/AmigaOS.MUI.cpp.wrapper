//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIA_Group_HorizCenter

namespace MUI
{
    enum class Group_HorizCenter
    {
#ifdef MUIV_Group_HorizCenter_Left
        Left = MUIV_Group_HorizCenter_Left,
        Center = MUIV_Group_HorizCenter_Center,
        Right = MUIV_Group_HorizCenter_Right
#else
        Left = 0,
        Center = 1,
        Right = 2
#endif
    };
}

#endif
