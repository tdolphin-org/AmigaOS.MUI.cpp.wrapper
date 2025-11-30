//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/List.hpp"

namespace Components
{
    class HardwareList : public Root<MUI::List>
    {
        MUI::List mComponent;

      public:
        HardwareList();

      protected:
        MUI::List &muiRoot() const
        {
            return (MUI::List &)mComponent;
        }
    };
}
