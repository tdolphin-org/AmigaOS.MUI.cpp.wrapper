//
//  AmigaOS MUI C++ wrapper
//
//  Basic Example
//
//  (c) 2022-2023 TDolphin
//

#include "Main.hpp"

#include <iostream>
#include <proto/alib.h>
#include <proto/exec.h>

#include "AOS/TagsScope.hpp"
#include "Core/ToString.hpp"
#include "MUI/Application.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"
#include "MUI/Group.hpp"
#include "MUI/Notifier/Core/Notifier.hpp"
#include "MUI/Rectangle.hpp"
#include "MUI/Window.hpp"

using namespace std;

int main(int argc, char **argv)
{
    cout << "basic MUI app example, created width 'AmigaOS MUI C++ wrapper'" << endl;

    MuiMasterBaseScope muiBase;

    auto window = MUI::WindowBuilder()
                      .tagTitle("Window Title")
                      .tagScreenTitle("Application Screen Name")
                      .tagID("MAIN")
                      .tagWidth(640)
                      .tagHeight(200)
                      .tagAltWidth(1024)
                      .tagAltHeight(600)
                      .tagRootObject(MUI::GroupBuilder()
                                         .tagChild(MUI::RectangleBuilder().object())
                                         .tagChild(MUI::MakeObject::SimpleButton("button"))
                                         .tagChild(MUI::RectangleBuilder().object())
                                         .object())
                      .object();

    auto app = MUI::ApplicationBuilder()
                   .tagAuthor("AUTHORS")
                   .tagBase("CMD_NAME")
                   .tagCopyright("APP_TDOLPHIN_COPYRIGHTS")
                   .tagDescription("APP_NAME")
                   .tagTitle("APP_NAME")
                   .tagVersion("$VER: 1.0")
                   .tagWindow(window)
                   .object();

    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(app);

    // events
    MUI::Notifier::from(window).onCloseRequest(true).destObject(app).returnIDQuit();

    // open window on constructor, close on destructor
    MUI::WindowScope windowScope(window);

    // main application loop
    ULONG signals = 0;
    while (DoMethod(app.muiObject(), MUIM_Application_NewInput, &signals) != MUIV_Application_ReturnID_Quit)
    {
        if (signals)
        {
            signals = Wait(signals | SIGBREAKF_CTRL_C);
            if (signals & SIGBREAKF_CTRL_C)
                break;
        }
    }

    return 0;
}