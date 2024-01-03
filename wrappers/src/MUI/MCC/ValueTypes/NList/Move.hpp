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
    enum class NList_Move
    {
        Top = MUIV_NList_Move_Top,
        Active = MUIV_NList_Move_Active,
        Bottom = MUIV_NList_Move_Bottom,
        Next = MUIV_NList_Move_Next,
        Previous = MUIV_NList_Move_Previous,
        Selected = MUIV_NList_Move_Selected,
    };
}
