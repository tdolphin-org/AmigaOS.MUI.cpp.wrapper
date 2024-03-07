//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "HardwareList.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"

namespace Components
{
    class ListAndImageTab : public Root
    {
        MUI::Image mExampleImage;
        HardwareList mHardwareList;
        MUI::Group mComponent;

      public:
        ListAndImageTab();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
