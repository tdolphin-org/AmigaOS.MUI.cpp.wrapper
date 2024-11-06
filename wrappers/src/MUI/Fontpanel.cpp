//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Fontpanel.hpp"

#ifdef MUIC_Fontpanel

#include <proto/alib.h>

namespace MUI
{
    const std::string Fontpanel::className = MUIC_Fontpanel;

    FontpanelBuilder::FontpanelBuilder() { }
}

#endif
