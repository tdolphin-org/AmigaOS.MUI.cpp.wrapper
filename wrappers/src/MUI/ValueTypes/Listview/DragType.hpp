//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Listview_DragType
    {
        None = MUIV_Listview_DragType_None,
        Immediate = MUIV_Listview_DragType_Immediate,
    };
}
