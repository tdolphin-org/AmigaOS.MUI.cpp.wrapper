//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

namespace MUI::MCC
{
    enum class NList_DragType
    {
        None = MUIV_NList_DragType_None,
        Default = MUIV_NList_DragType_Default,
        Immediate = MUIV_NList_DragType_Immediate,
        Borders = MUIV_NList_DragType_Borders,
        Qualifier = MUIV_NList_DragType_Qualifier,
    };
}
