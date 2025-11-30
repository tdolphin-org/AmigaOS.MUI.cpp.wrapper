//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"
#include "Menus/MainMenu.hpp"
#include "Tabs/Content.hpp"

namespace Components
{
    class AppWindow : public Root<MUI::Window>
    {
        MUI::Area mCloseButton;
        Content mContent;
        MUI::Text mInfoText;
        MainMenu mMainMenu;

        MUI::Window mComponent;

      public:
        AppWindow();

        void RegisterEvents();

        operator MUI::Window &() const
        {
            return (MUI::Window &)mComponent;
        }

        MUI::Window &muiRoot() const
        {
            return (MUI::Window &)mComponent;
        }
    };
}
