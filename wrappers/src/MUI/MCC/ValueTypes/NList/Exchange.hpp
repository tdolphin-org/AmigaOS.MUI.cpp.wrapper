//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

#undef End

namespace MUI
{
    enum class NList_Exchange
    {
        Top = MUIV_NList_Exchange_Top,
        Active = MUIV_NList_Exchange_Active,
        Bottom = MUIV_NList_Exchange_Bottom,
        Next = MUIV_NList_Exchange_Next,
        Previous = MUIV_NList_Exchange_Previous,
    };
}
