//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#include "MainMenu.hpp"

#include "Events/AppEventType.hpp"
#include "MUI/Menuitem.hpp"

//
// Advanced Example
// +-- About...
// +======
// +-- Quit
//
// Settings
// +-- MUI...
//

namespace Components
{
    MainMenu::MainMenu()
      : mCPUMMenu(MUI::MenuBuilder()
                      .tagTitle("Advanced Example")
                      .tagChild(MUI::MenuitemBuilder()
                                    .tagUserData(static_cast<unsigned long>(AppEventType::OnMenuAbout))
                                    .tagTitle("About...")
                                    .object())
                      .tagChild(MUI::MenuItemFactory().Separator())
                      .tagChild(MUI::MenuitemBuilder().tagUserData(MUIV_Application_ReturnID_Quit).tagTitle("Quit").object())
                      .object())
      , mSettingsMenu(MUI::MenuBuilder()
                          .tagTitle("Settings")
                          .tagChild(MUI::MenuitemBuilder()
                                        .tagUserData(static_cast<unsigned long>(AppEventType::OnMenuMUISettings))
                                        .tagTitle("MUI...")
                                        .object())
                          .object())
      , mComponent(MUI::MenustripBuilder().tagChild(mCPUMMenu).tagChild(mSettingsMenu).object())
    {
    }
}