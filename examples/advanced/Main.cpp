//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#include "Main.hpp

#include "Components/Application.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"

#include <iostream>
#include <proto/alib.h>
#include <proto/exec.h>

using namespace std;

int main(int argc, char **argv)
{
    cout << "advanced MUI application example, created with 'AmigaOS MUI C++ wrapper'" << endl;

    try
    {
        // open MUI library, close on destructor 
        MuiMasterBaseScope muiBase;

        Components::Application application;

        // application scope
        // do MUI_DisposeObject(..) on destructor
        MUI::ApplicationScope appScope(application);

        // register events
        application.RegisterEvents():

        // list of application windows
        for (auto window : application.getWindowList())
            std::cout << "muiObjectPtr = " << window.muiObject() << " id=" << window.getID().toString() << std::endl;

        auto mainWindow = MUI::ApplicationContext::getAppWindow();

        // open window on constructor, close on destructor
        MUI::WindowScope windowScope(mainWindow);

        // main application loop
        ULONG signals = 0;
        while (DoMethod(application.muiObject(), MUIM_Application_NewInput, &signals) != MUIV_Application_ReturnID_Quit)
        {
            if (signals)
            {
                signals = Wait(signals | SIGBREAKF_CTRL_C);
                if (signals & SIGBREAKF_CTRL_C)
                    break;
            }
        }
    }
    catch(...)
    {
        cerr << "exception" << endl;
        return -1;
    }

    return 0;
}
