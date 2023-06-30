//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI::MCC
{
    enum class TypeSelect
    {
        Line = MUIV_NList_TypeSelect_Line,
        Char = MUIV_NList_TypeSelect_Char
    };
}
