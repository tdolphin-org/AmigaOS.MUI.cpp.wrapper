//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "BoardsList.hpp"
#include "CustomClassesTab.hpp"
#include "ListAndImageTab.hpp"
#include "TabsContainerRegister.hpp" // version using MUI::Register for tabs/pages
#include "TabsContainerTitles.hpp" // version using MUI::Titles for tabs/pages

namespace Components
{
    class Content : public Root
    {
        MUI::Group mRegisterInfoGroup;
        ListAndImageTab mListAndImageTab;
        TabsContainerRegister mLeftTabsRegister;

        MUI::Group mTitleInfoGroup;
        BoardsList mBoardsList;
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
