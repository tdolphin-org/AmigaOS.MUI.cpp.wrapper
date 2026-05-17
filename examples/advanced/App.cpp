//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2026 TDolphin
//

#include "App.hpp"

#include "MUI/Context/ApplicationContext.hpp"
#include "MUI/Core/CustomClassManager.hpp"

#include <cstdio>
#include <proto/alib.h>
#include <proto/exec.h>

using namespace std;

AppCore::AppCore() { }

void AppCore::Run()
{
    MUI::CustomClassesLifeTimeScope customClassesLifeTimeScope;

    // application scope
    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(mApplication);

    mApplication.RegisterEvents();

    // list of application windows
    for (auto window : mApplication.muiRoot().getWindowList())
        std::fprintf(stderr, "muiObjectPtr = %p id=%s\n", (void *)window.muiObject(), window.getID().toString().c_str());

    auto appWindow = MUI::ApplicationContext::instance().getAppWindow();
    // open window on constructor, close on destructor
    MUI::WindowScope window(appWindow);

    // appWindow.setScreenTitle();

    // main application loop
    ULONG signals = 0;
    while (DoMethod(mApplication.muiObject(), MUIM_Application_NewInput, &signals) != MUIV_Application_ReturnID_Quit)
    {
        if (signals)
        {
            signals = Wait(signals | SIGBREAKF_CTRL_C);
            if (signals & SIGBREAKF_CTRL_C)
                break;
        }
    }
}
