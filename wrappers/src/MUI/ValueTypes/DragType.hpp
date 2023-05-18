//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class DragType
    {
        None = MUIV_List_DragType_None,
        Immediate = MUIV_List_DragType_Immediate,
    };
}
