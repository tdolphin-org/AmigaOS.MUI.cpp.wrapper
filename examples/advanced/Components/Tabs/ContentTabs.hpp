//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "CustomClassesTab.hpp"
#include "ListAndImageTab.hpp"
#include "MUI/Group.hpp"

namespace Components
{
    class ContentTabs : public Root
    {
        ListAndImageTab mListAndImageTab;
        CustomClassesTab mCustomClassesTab;

        MUI::Group mComponent;

      public:
        ContentTabs();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
