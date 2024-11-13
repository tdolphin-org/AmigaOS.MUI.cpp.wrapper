//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#include "TabsContainer.hpp"

#include "MUI/Text.hpp"

namespace Components
{
    TabsContainer::TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
#ifdef MUIC_Title
      : mTabsTitle(MUI::TitleBuilder().object())
      , mComponent(MUI::GroupBuilder()
                       .tagCycleChain()
                       .tagChild(mTabsTitle)
#ifdef __MORPHOS__
                       .tagPageMode()
                       .tagBackground(MUI::ImageOrBackground::RegisterBack)
                       .tagFrame(MUI::Frame::Register)
#endif
                       .object())
#else
      : mPageTitles(tabs.size())
      , mpPageTitlesArray(new const char *[tabs.size()])
      , mComponent(MUI::RegisterBuilder()
                       .tagTitles([&]() {
                           unsigned int index = 0;
                           for (auto &tab : tabs)
                           {
                               mPageTitles.push_back(tab.first);
                               mpPageTitlesArray[index++] = (char *)mPageTitles.back().c_str();
                           }
                           mpPageTitlesArray[index++] = (char *)nullptr;
                           return mpPageTitlesArray;
                       }())
                       .object())
#endif
    {
#ifdef MUIC_Title
        for (auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());
        for (auto &tab : tabs)
        {
#ifdef MUIM_Group_AddTail
            mComponent.AddTail(tab.second);
#else
            mComponent.AddMember(tab.second);
#endif
        }
#else
        for (auto &tab : tabs)
        {
#ifdef MUIM_Group_AddTail
            mComponent.AddTail(tab.second);
#else
            mComponent.AddMember(tab.second);
#endif
        }
#endif
    }

    TabsContainer::~TabsContainer()
    {
#ifndef MUIC_Title
        delete[] mpPageTitlesArray;
#endif
    }
}
