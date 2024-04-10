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
      : mTabsTitle(MUI::TitleBuilder().tagClosable(true).tagNewable(true).object())
      , mComponent(MUI::GroupBuilder()
            .tagCycleChain()
            .tagChild(mTabsTitle)
#ifdef __MORPHOS__
            .tagPageMode()
            .tagBackground(MUI::ImageOrBackground::RegisterBack)
            .tagFrame(MUI::Frame::Register)
#endif
            .object())
    {
        for (auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());
        for (auto &tab : tabs)
            mComponent.AddTail(tab.second);
    }
}
