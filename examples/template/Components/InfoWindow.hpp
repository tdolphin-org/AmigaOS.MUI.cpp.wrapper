//
//  AmigaOS MUI C++ wrapper
//
//  Application Template
//
//  (c) 20xx XXXXX
//

#pragma once

#include "Core/Root.hpp"
#include "MUI/Window.hpp"

namespace Components
{
    class InfoWindow : public Root
    {
        MUI::Window mComponent;

      public:
        InfoWindow(const MUI::Root &rootObject);

        operator MUI::Window &() const
        {
            return (MUI::Window &)mComponent;
        }

        MUI::Window &muiRoot() const
        {
            return (MUI::Window &)mComponent;
        }

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
