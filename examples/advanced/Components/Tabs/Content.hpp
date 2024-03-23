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
#include "MUI/Text.hpp"
#include "TabsContainerRegister.hpp" // version using MUI::Register for tabs/pages
#include "TabsContainerTitles.hpp" // version using MUI::Titles for tabs/pages

namespace Components
{
    class Content : public Root
    {
        MUI::Text mRegisterInfo;
        ListAndImageTab mListAndImageTab;
        TabsContainerRegister mLeftTabsRegister;

        MUI::Text mTitleInfo;
        CustomClassesTab mCustomClassesTab;
        TabsContainerTitles mRightTabsTitles;

        MUI::Group mComponent;

      public:
        Content();

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
