//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include "MUI/List.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class AppWindow
    {
        MUI::List mItemsList;
        MUI::Area closeButton;
        MUI::Window mComponent;
    
      public:
        AppWindow();
        
        MUI::Window &muiRoot()
        {
            return mComponent;
        }
    };
}
