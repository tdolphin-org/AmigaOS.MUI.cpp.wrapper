//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "HardwareList.hpp"
#include "MUI/Group.hpp"
#include "MUI/Image.hpp"

namespace Components
{
    class ListAndImageTab : public Root<MUI::Group>
    {
        MUI::Image mExampleImage;
        HardwareList mHardwareList;

        MUI::Group mComponent;

      public:
        ListAndImageTab();

        operator MUI::Group &()
        {
            return mComponent;
        }

      protected:
        MUI::Group &muiRoot() const
        {
            return (MUI::Group &)mComponent;
        }
    };
}
