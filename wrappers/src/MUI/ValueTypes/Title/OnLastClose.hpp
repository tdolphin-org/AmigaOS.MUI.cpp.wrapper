//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

#ifdef MUIC_Title

namespace MUI
{
    enum class Title_OnLastClose
    {
        Remove = MUIV_Title_OnLastClose_Remove,
        WindowAction = MUIV_Title_OnLastClose_WindowAction,
    };
}

#endif
