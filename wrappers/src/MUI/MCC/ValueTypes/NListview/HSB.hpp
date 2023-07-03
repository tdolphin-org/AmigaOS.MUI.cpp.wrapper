//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <mui/NListview_mcc.h>

namespace MUI::MCC
{
    enum class NListview_HSB
    {
        Always = MUIV_NListview_HSB_Always,
        Auto = MUIV_NListview_HSB_Auto,
        FullAuto = MUIV_NListview_HSB_FullAuto,
        None = MUIV_NListview_HSB_None,
        Default = MUIV_NListview_HSB_Default,
        On = MUIV_NListview_HSB_On,
        Off = MUIV_NListview_HSB_Off,
    };
}
