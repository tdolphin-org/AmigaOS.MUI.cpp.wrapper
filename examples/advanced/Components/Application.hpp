//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AppWindow.hpp"
#include "MUI/Application.hpp"

namespace Components
{
    class Application
    {
        AppWindow mAppWindow;
        MUI::Application mComponent;

      public:
        Application();
        
        MUI::Application &muiRoot()
        {
            return mComponent;
        }
    };
}
