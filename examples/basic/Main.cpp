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

#include "MUI/Application.hpp"
#include "MUI/Core/MakeObject.hpp"
#include "MUI/Core/MuiMasterBaseScope.hpp"
#include "MUI/Group.hpp"
#include "MUI/Notifier/Notifier.hpp"
#include "MUI/Rectangle.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"

using namespace std;

int main(int argc, char **argv)
{
    cout << "basic MUI app example, created with 'AmigaOS MUI C++ wrapper'" << endl;

    MuiMasterBaseScope muiBase;

    char *items[] = { "AmigaOS", "MorphOS", "AROS", (char *)nullptr };
    auto itemsList = MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).object();
    itemsList.InsertTop((const void **)items);

    auto closeButton = MUI::MakeObject::SimpleButton("_Quit Application");

    auto window
        = MUI::WindowBuilder()
              .tagTitle("Window Title")
              .tagScreenTitle("Application Screen Title")
              .tagID("MAIN")
              .tagWidth(600)
              .tagHeight(240)
              .tagAltWidth(1024)
              .tagAltHeight(600)
              .tagRootObject(MUI::GroupBuilder()
                                 .tagChild(MUI::TextBuilder()
                                               .tagShortHelp("help text")
                                               .tagContents(MUIX_C "some centered text in MUI::Text\n\n" MUIX_PH " (c) 2022-2023 TDolphin")
                                               .object())
                                 .tagChild(closeButton)
                                 .tagChild(itemsList)
                                 .tagChild(MUI::GroupBuilder()
                                               .horizontal()
                                               .tagChild(MUI::MakeObject::SimpleButton("_Left Button"))
                                               .tagChild(MUI::RectangleBuilder().object())
                                               .tagChild(MUI::MakeObject::SimpleButton("_Right Button"))
                                               .object())
                                 .object())
              .object();

    auto app = MUI::ApplicationBuilder()
                   .tagAuthor("rz")
                   .tagBase("basic.example.bin")
                   .tagCopyright("(c) 2022-2023 TDolphin")
                   .tagDescription("Very Basic Example of usage MUI C++ wrapper")
                   .tagTitle("Basic Example")
                   .tagVersion("$VER: 1.0")
                   .tagWindow(window)
                   .object();

    // do MUI_DisposeObject(..) on destructor
    MUI::ApplicationScope application(app);

    // events
    MUI::Notifier::from(window).onCloseRequest(true).notifyObject(app).returnIDQuit();
    MUI::Notifier::from(MUI::Area(closeButton)).onPressed(false).notifyObject(app).returnIDQuit();

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
