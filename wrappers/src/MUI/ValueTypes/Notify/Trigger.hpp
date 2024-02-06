//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

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
