//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class MultiSelect
    {
        None = MUIV_List_MultiSelect_None,
        Default = MUIV_List_MultiSelect_Default,
        Shifted = MUIV_List_MultiSelect_Shifted,
        Always = MUIV_List_MultiSelect_Always,
    };
}
