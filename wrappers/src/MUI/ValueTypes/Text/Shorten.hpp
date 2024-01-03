//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <libraries/mui.h>

namespace MUI
{
    enum class Text_Shorten
    {
        Nothing = MUIV_Text_Shorten_Nothing,
        Cutoff = MUIV_Text_Shorten_Cutoff,
        Hide = MUIV_Text_Shorten_Hide,
#ifndef __MORPHOS__
        ElideLeft = MUIV_Text_Shorten_ElideLeft,
        ElideCenter = MUIV_Text_Shorten_ElideCenter,
        ElideRight = MUIV_Text_Shorten_ElideRight
#endif
    };
}
