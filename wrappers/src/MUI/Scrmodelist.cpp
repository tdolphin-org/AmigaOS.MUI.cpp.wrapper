//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Scrmodelist.hpp"

#include <libraries/mui.h>
#include <proto/muimaster.h>

namespace MUI
{
    const std::string Scrmodelist::className = MUIC_Scrmodelist;

    ScrmodelistBuilder::ScrmodelistBuilder() { }
}
