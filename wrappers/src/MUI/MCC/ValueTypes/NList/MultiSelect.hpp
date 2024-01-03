//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI::MCC
{
    enum class NList_MultiSelect
    {
        None = MUIV_NList_MultiSelect_None,
        Default = MUIV_NList_MultiSelect_Default,
        Shifted = MUIV_NList_MultiSelect_Shifted,
        Always = MUIV_NList_MultiSelect_Always,
    };
}
