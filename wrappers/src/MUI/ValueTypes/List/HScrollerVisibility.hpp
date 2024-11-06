//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

#ifdef MUIA_List_HScrollerVisibility

namespace MUI
{
    enum class List_HScrollerVisibility
    {
        Always = MUIV_List_HScrollerVisibility_Always,
        Never = MUIV_List_HScrollerVisibility_Never,
        Auto = MUIV_List_HScrollerVisibility_Auto,
    };
}

#endif
