//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "TabsContainerTitles.hpp"

#include "MUI/Text.hpp"

namespace Components
{
    TabsContainerTitles::TabsContainerTitles(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
      : mTabsTitle(MUI::TitleBuilder().object())
      , mComponent(MUI::GroupBuilder().tagCycleChain().tagPageMode().tagChild(mTabsTitle).object())
    {
        for (auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());
        for (auto &tab : tabs)
            mComponent.AddTail(tab.second);
    }
}
