//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#ifdef MUIA_Selectgroup_Active

namespace MUI
{
    enum class Selectgroup_Active : long
    {
        Next = MUIV_Selectgroup_Active_Next,
        Prev = MUIV_Selectgroup_Active_Prev
    };
}

#endif // MUIA_Selectgroup_Active
