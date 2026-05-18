//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

namespace MUI
{
    enum class InputMode
    {
        None = MUIV_InputMode_None,
        RelVerify = MUIV_InputMode_RelVerify,
        Immediate = MUIV_InputMode_Immediate,
        Toggle = MUIV_InputMode_Toggle
    };
}
