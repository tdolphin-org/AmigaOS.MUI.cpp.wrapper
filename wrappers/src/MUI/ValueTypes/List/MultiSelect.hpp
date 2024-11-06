//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIA_List_MultiSelect

namespace MUI
{
    enum class List_MultiSelect
    {
        /// @brief The listview cannot multiselect at all.
        None = MUIV_List_MultiSelect_None,
        /// @brief The multi select type (with or without shift) depends on the user's preferences setting.
        Default = MUIV_List_MultiSelect_Default,
        /// @brief Overrides the users prefs, multi selecting only together with shift key.
        Shifted = MUIV_List_MultiSelect_Shifted,
        /// @brief Overrides the users prefs, multi selecting without shift key.
        Always = MUIV_List_MultiSelect_Always,
    };
}

#endif
