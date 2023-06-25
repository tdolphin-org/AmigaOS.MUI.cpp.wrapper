//
//  AmigaOS MUI C++ wrapper
//
//  Application Template Example
//
//  (c) 2022-2023 TDolphin
//

#include "App.hpp"

#include "MUI/Balance.hpp"
#include "MUI/Context/ApplicationContext.hpp"

#include <iostream>
#include <proto/alib.h>
#include <proto/exec.h>

using namespace std;

AppCore::AppCore() { }

void AppCore::Run()
{
    // application scope
    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(mApplication);

    mApplication.RegisterEvents();

    // list of application windows
    for (auto window : mApplication.muiRoot().getWindowList())
        std::cout << "muiObjectPtr = " << window.muiObject() << " id=" << window.getID().toString() << std::endl;

    auto appWindow = MUI::ApplicationContext::instance().getAppWindow();
    // open window on constructor, close on destructor
    MUI::WindowScope window(appWindow);

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
