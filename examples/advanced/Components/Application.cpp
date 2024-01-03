//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "Application.hpp"

#include "MUI/Notifier/Notifier.hpp"

namespace Components
{
    Application::Application()
      : mComponent(MUI::ApplicationBuilder()
                       .tagAuthor("rz")
                       .tagBase("advanced.example.bin")
                       .tagCopyright("(c) 2022-2024 TDolphin")
                       .tagDescription("Advanced Example of usage MUI C++ wrapper")
                       .tagTitle("Advanced Example")
                       .tagVersion("$VER: 1.0")
                       .tagWindow(mAppWindow)
                       .object())
    {
    }

    void Application::RegisterEvents()
    {
        MUI::Notifier::from(mAppWindow.muiRoot()).onCloseRequest(true).notifyObject(mComponent).returnIDQuit();

        mAppWindow.RegisterEvents();
    }
}
