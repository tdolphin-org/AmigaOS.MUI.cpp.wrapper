//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#include "Application.hpp"

namespace Components
{
    Application::Application()
    : mComponent(MUI::ApplicationBuilder()
                   .tagAuthor("rz")
                   .tagBase("advanced.example.bin")
                   .tagCopyright("(c) 2022-2023 TDolphin")
                   .tagDescription("More Advanced Example of usage MUI C++ wrapper")
                   .tagTitle("Advanced Example")
                   .tagVersion("$VER: 1.0")
                   .tagWindow(mAppWindow)
                   .object())
    {
    }

    void Application::RegisterEvents()
    {
        MUI::Notifier::from(mAppWindow).onCloseRequest(true).notifyObject(mComponent).returnIDQuit();

        mAppWindow.RegisterEvents();
    }
}
