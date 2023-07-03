//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI
{
    enum class NList_First
    {
        Top = MUIV_NList_First_Top,
        Bottom = MUIV_NList_First_Bottom,
        Up = MUIV_NList_First_Up,
        Down = MUIV_NList_First_Down,
        PageUp = MUIV_NList_First_PageUp,
        PageDown = MUIV_NList_First_PageDown,
        Up2 = MUIV_NList_First_Up2,
        Down2 = MUIV_NList_First_Down2,
        Up4 = MUIV_NList_First_Up4,
        Down4 = MUIV_NList_First_Down4,
    };
}
