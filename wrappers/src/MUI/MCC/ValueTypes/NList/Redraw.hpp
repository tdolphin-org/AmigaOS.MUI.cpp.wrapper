//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <mui/NList_mcc.h>

#undef End

namespace MUI
{
    enum class NList_Redraw
    {
        Active = MUIV_NList_Redraw_Active,
        All = MUIV_NList_Redraw_All,
        Title = MUIV_NList_Redraw_Title,
        Selected = MUIV_NList_Redraw_Selected,
        VisibleCols = MUIV_NList_Redraw_VisibleCols,
    };
}
