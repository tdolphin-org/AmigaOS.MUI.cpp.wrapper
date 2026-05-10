//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIA_Group_VertCenter

namespace MUI
{
    enum class Group_VertCenter
    {
#ifdef MUIV_Group_VertCenter_Top
        Top = MUIV_Group_VertCenter_Top,
        Center = MUIV_Group_VertCenter_Center,
        Bottom = MUIV_Group_VertCenter_Bottom
#else
        Top = 0,
        Center = 1,
        Bottom = 2
#endif
    };
}

#endif
