//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#include "Application.hpp"

#include "MUI/Notifier/Notifier.hpp"
#include "Events/AppEventType.hpp"

namespace Components
{
    Application::Application()
      : mComponent(MUI::ApplicationBuilder()
                       .tagAuthor("rz")
                       .tagBase("advanced.example.bin")
                       .tagCopyright("(c) 2022-2025 TDolphin")
                       .tagDescription("Advanced Example of usage MUI C++ wrapper")
                       .tagTitle("Advanced Example")
                       .tagVersion("$VER: 1.1")
                       .tagWindow(mAppWindow)
                       .object())
    {
    }

    void Application::RegisterEvents()
    {
        MUI::Notifier::from(mAppWindow).onCloseRequest(true).notifyObject(mComponent).returnIDQuit();

        // open MUI settings on action (OnMenuMUISettings) from main menu
        MUI::Notifier::from(mAppWindow)
            .onMenuAction(static_cast<unsigned long>(AppEventType::OnMenuMUISettings))
            .notifyObject(mComponent)
            .openConfigWindow();

        mAppWindow.RegisterEvents();
    }
}
