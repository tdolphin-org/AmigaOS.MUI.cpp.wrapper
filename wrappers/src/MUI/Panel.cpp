//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Panel.hpp"

#ifdef MUIC_Panel

#include "Application.hpp"
#include "Window.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Panel::className = MUIC_Panel;

    PanelBuilder::PanelBuilder() { }

#ifdef MUIM_Panel_Run
    Panel &Panel::Run(Application &app, Window &win)
    {
        DoMethod(muiObject(), MUIM_Panel_Run, app.muiObject(), win.muiObject());
        return *this;
    }
#endif
}

#endif
