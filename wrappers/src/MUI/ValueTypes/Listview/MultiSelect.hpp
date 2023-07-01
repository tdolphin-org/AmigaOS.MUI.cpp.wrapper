//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Listview_MultiSelect
    {
        None = MUIV_Listview_MultiSelect_None,
        Default = MUIV_Listview_MultiSelect_Default,
        Shifted = MUIV_Listview_MultiSelect_Shifted,
        Always = MUIV_Listview_MultiSelect_Always,
    };
}
