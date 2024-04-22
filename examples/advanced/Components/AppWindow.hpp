//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/Root.hpp"
#include "MUI/Text.hpp"
#include "MUI/Window.hpp"
#include "Tabs/Content.hpp"

namespace Components
{
    class AppWindow : public Root
    {
        MUI::Area mCloseButton;
        Content mContent;
        MUI::Text mInfoText;
        MUI::Window mComponent;

      public:
        AppWindow();

        void RegisterEvents();

        operator MUI::Window &() const
        {
            return (MUI::Window &)mComponent;
        }

        MUI::Window &muiRoot()
        {
            return mComponent;
        }

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
