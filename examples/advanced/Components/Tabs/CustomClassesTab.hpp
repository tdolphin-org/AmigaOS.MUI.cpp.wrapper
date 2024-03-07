//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Group.hpp"
#include "MUI/MCC/NListview.hpp"

namespace Components
{
    class CustomClassesTab : public Root
    {
        MUI::MCC::NList mItemsNList;
        MUI::MCC::NListview mItemsNListview;

        MUI::Group mComponent;

      public:
        CustomClassesTab();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
