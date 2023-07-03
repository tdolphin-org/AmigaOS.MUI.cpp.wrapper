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
    enum class NList_Insert
    {
        Top = MUIV_NList_Insert_Top,
        Active = MUIV_NList_Insert_Active,
        Sorted = MUIV_NList_Insert_Sorted,
        Bottom = MUIV_NList_Insert_Bottom,
        Flag_Raw = MUIV_NList_Insert_Flag_Raw,
    };
}
