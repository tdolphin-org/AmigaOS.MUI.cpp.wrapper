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
        /// @brief will hide all text completely if there is not enough space
        Hide = MUIV_Text_Shorten_Hide,
#ifndef __MORPHOS__
        /// @brief will shorten the text by replacing as many characters as necessary by inserting an ellipsis ("...") at the left
        ElideLeft = MUIV_Text_Shorten_ElideLeft,
        /// @brief will shorten the text by replacing as many characters as necessary by inserting an ellipsis ("...") in the center
        ElideCenter = MUIV_Text_Shorten_ElideCenter,
        /// @brief will shorten the text by replacing as many characters as necessary by inserting an ellipsis ("...") at the right
        ElideRight = MUIV_Text_Shorten_ElideRight
#endif
    };
}
