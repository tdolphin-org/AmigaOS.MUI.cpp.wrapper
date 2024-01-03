//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI::MCC
{
    enum class NList_Select // selection type
    {
        Off = MUIV_NList_Select_Off,
        On = MUIV_NList_Select_On,
        Toggle = MUIV_NList_Select_Toggle,
        Ask = MUIV_NList_Select_Ask,
    };

    enum class NList_SelectPosition
    {
        Active = MUIV_NList_Select_Active,
        All = MUIV_NList_Select_All,
    };
}
