//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Core/Root.hpp"

#include "MUI/List.hpp"

namespace Components
{
    class HardwareList : public Root
    {
        MUI::List mComponent;

      public:
        HardwareList();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
