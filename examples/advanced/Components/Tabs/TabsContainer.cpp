//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "TabsContainer.hpp"

#ifdef __MORPHOS__
#include "MUI/Text.hpp"
#endif

namespace Components
{
    TabsContainer::TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
#ifdef __MORPHOS__
      : mPageTitles(tabs.size())
      , mComponent(MUI::RegisterBuilder().object())
#else
      : mTabsTitle(MUI::TitleBuilder().object())
      , mComponent(MUI::GroupBuilder().tagCycleChain().tagChild(mTabsTitle).object())
#endif
    {
#ifdef __MORPHOS__
        mpPageTitlesArray = new const char *[tabs.size()];
        unsigned int index = 0;
        for (auto &tab : tabs)
        {
            mPageTitles.push_back(tab.first);
            mpPageTitlesArray[index++] = (char *)mPageTitles.back().c_str();
        }
        mpPageTitlesArray[index++] = (char *)nullptr;
        mComponent.setTitles(mpPageTitlesArray);
#else
        for (auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());
#endif

        for (auto &tab : tabs)
            mComponent.AddTail(tab.second);
    }

    TabsContainer::~TabsContainer()
    {
#ifdef __MORPHOS__
        delete[] mpPageTitlesArray;
#endif
    }
}