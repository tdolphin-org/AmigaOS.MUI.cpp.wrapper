//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/Root.hpp"
#include "MUI/Area.hpp"
#include "MUI/Image.hpp"
#include "MUI/Window.hpp"
#include "Tabs/ContentTabs.hpp"

namespace Components
{
    class AppWindow : public Root
    {
        MUI::Area mCloseButton;
        ContentTabs mContentTabs;
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
