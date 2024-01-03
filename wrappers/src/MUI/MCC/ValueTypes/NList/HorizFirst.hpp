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
    enum class NList_HorizFirst
    {
        Start = MUIV_NList_Horiz_First_Start,
        End = MUIV_NList_Horiz_First_End,
        Left = MUIV_NList_Horiz_First_Left,
        Right = MUIV_NList_Horiz_First_Right,
        PageLeft = MUIV_NList_Horiz_First_PageLeft,
        PageRight = MUIV_NList_Horiz_First_PageRight,
        Left2 = MUIV_NList_Horiz_First_Left2,
        Right2 = MUIV_NList_Horiz_First_Right2,
        Left4 = MUIV_NList_Horiz_First_Left4,
        Right4 = MUIV_NList_Horiz_First_Right4,
    };
}
