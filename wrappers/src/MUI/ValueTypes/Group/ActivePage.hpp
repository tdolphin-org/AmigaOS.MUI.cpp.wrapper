//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Group_ActivePage
    {
        First = MUIV_Group_ActivePage_First,
        Last = MUIV_Group_ActivePage_Last,
        Prev = MUIV_Group_ActivePage_Prev,
        Next = MUIV_Group_ActivePage_Next,
        Advance = MUIV_Group_ActivePage_Advance
    };
}
