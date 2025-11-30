//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Group.hpp"
#include "MUI/MCC/NListview.hpp"

namespace Components
{
    class CustomClassesTab : public Root<MUI::Group>
    {
        MUI::MCC::NList mItemsNList;
        MUI::MCC::NListview mItemsNListview;

        MUI::Group mComponent;

      public:
        CustomClassesTab();

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
