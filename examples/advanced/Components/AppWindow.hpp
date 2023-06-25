//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Area.hpp"
#include "MUI/List.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class AppWindow : public MUI::Root
    {
        MUI::List mItemsList;
        MUI::Area mCloseButton;
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
