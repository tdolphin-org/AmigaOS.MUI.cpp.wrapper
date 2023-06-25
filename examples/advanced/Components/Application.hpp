//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AppWindow.hpp"
#include "Components/Core/Root.hpp"
#include "MUI/Application.hpp"

namespace Components
{
    class Application : public Root
    {
        AppWindow mAppWindow;
        MUI::Application mComponent;

      public:
        Application();

        void RegisterEvents();

        operator MUI::Application &()
        {
            return mComponent;
        }

        MUI::Application &muiRoot() const
        {
            return (MUI::Application &)mComponent;
        }

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }

    };
}
