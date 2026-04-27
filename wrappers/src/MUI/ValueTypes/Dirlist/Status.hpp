//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Dirlist_Status
    {
        Invalid = MUIV_Dirlist_Status_Invalid,
        Reading = MUIV_Dirlist_Status_Reading,
        Valid = MUIV_Dirlist_Status_Valid,
    };
}
