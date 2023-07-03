//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NListview_mcc.h>

namespace MUI::MCC
{
    enum class NListview_VSB
    {
        Always = MUIV_NListview_VSB_Always,
        Auto = MUIV_NListview_VSB_Auto,
        FullAuto = MUIV_NListview_VSB_FullAuto,
        None = MUIV_NListview_VSB_None,
        Default = MUIV_NListview_VSB_Default,
        Left = MUIV_NListview_VSB_Left,
        On = MUIV_NListview_VSB_On,
        Off = MUIV_NListview_VSB_Off,
    };
}
