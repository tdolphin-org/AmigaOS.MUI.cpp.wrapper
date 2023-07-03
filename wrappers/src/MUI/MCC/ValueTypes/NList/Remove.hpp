//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI::MCC
{
    enum class NList_Remove
    {
        First = MUIV_NList_Remove_First,
        Active = MUIV_NList_Remove_Active,
        Last = MUIV_NList_Remove_Last,
        Selected = MUIV_NList_Remove_Selected,
    };
}
