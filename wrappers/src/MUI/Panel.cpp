//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Panel.hpp"

#ifdef MUIC_Panel

#include <proto/alib.h>

namespace MUI
{
    const std::string Panel::className = MUIC_Panel;

    PanelBuilder::PanelBuilder() { }

    Panel &Panel::Run(Object *app, Object *win)
    {
        DoMethod(muiObject(), MUIM_Panel_Run, app, win);
        return *this;
    }
}

#endif
