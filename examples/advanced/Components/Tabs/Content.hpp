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

// #include "TabsContainerRegister.hpp" // version using MUI::Register for tabs/pages
#include "TabsContainerTitles.hpp" // version using MUI::Titles for tabs/pages

namespace Components
{
    class Content : public Root
    {
        ListAndImageTab mListAndImageTab;
        CustomClassesTab mCustomClassesTab;
        TabsContainerTitles mComponent;

      public:
        Content();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
