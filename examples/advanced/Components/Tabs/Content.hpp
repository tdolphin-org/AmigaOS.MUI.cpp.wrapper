//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "CustomClassesTab.hpp"
#include "ListAndImageTab.hpp"
#include "TabsContainer.hpp"

namespace Components
{
    class Content : public Root
    {
        ListAndImageTab mListAndImageTab;
        CustomClassesTab mCustomClassesTab;
        TabsContainer mComponent;

      public:
        Content();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
