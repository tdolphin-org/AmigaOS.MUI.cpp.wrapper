//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Menu.hpp"
#include "MUI/Menuitem.hpp"
#include "MUI/Menustrip.hpp"

namespace Components
{
    class MainMenu : public Root<MUI::Menustrip>
    {
        MUI::Menu mCPUMMenu;
        MUI::Menu mSettingsMenu;

        MUI::Menustrip mComponent;

      public:
        MainMenu();

      protected:
        MUI::Menustrip &muiRoot() const
        {
            return (MUI::Menustrip &)mComponent;
        }
    };
}
