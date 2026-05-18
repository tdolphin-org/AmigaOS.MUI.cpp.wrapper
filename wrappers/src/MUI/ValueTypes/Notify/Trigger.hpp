//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

namespace MUI
{
    enum class Trigger
    {
        /// @brief value
        Value = MUIV_TriggerValue,
        /// @brief not/negative value
        NotValue = MUIV_NotTriggerValue,
    };
}
