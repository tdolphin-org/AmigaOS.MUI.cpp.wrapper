//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

#ifdef MUIA_List_DragType

namespace MUI
{
    enum class List_DragType
    {
        None = MUIV_List_DragType_None,
        Immediate = MUIV_List_DragType_Immediate,
    };
}

#endif
