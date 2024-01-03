//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Group_HorizCenter
    {
#ifndef __MORPHOS__
        Left = MUIV_Group_HorizCenter_Left,
        Center = MUIV_Group_HorizCenter_Center,
        Right = MUIV_Group_HorizCenter_Right
#endif
    };
}
