//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Group_VertCenter
    {
#ifndef __MORPHOS__
        Top = MUIV_Group_VertCenter_Top,
        Center = MUIV_Group_VertCenter_Center,
        Bottom = MUIV_Group_VertCenter_Bottom
#endif
    };
}
