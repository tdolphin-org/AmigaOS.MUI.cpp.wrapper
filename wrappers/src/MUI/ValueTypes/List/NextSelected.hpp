//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <libraries/mui.h>

#undef End

namespace MUI
{
    enum class List_NextSelected
    {
        Start = MUIV_List_NextSelected_Start,
        End = MUIV_List_NextSelected_End
    };
}
