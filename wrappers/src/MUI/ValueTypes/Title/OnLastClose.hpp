//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Title_OnLastClose
    {
        Remove = MUIV_Title_OnLastClose_Remove,
        WindowAction = MUIV_Title_OnLastClose_WindowAction,
    };
}
