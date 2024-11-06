//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Scrollbar_Type
    {
        Default = MUIV_Scrollbar_Type_Default,
        Bottom = MUIV_Scrollbar_Type_Bottom,
        Top = MUIV_Scrollbar_Type_Top,
        Sym = MUIV_Scrollbar_Type_Sym,
#ifdef MUIV_Scrollbar_Type_None
        None = MUIV_Scrollbar_Type_None,
#endif
    };
}
