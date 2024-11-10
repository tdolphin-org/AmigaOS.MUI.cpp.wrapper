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
#ifdef MUIC_Title
      : mTabsTitle(MUI::TitleBuilder().tagClosable(true).tagNewable(true).object())
#else
      : mTitleNotSupportedText(MUI::TextBuilder().tagContents("MUI::Title not supported (compiled) by this MUI version").object())
#endif
      , mComponent(MUI::GroupBuilder()
                       .tagCycleChain()
#ifdef MUIC_Title
                       .tagChild(mTabsTitle)
#else
                       .tagChild(mTitleNotSupportedText)
#endif
#ifdef __MORPHOS__
                       .tagPageMode()
                       .tagBackground(MUI::ImageOrBackground::RegisterBack)
                       .tagFrame(MUI::Frame::Register)
#endif
                       .object())
    {
#ifdef MUIC_Title
        for (auto &tab : tabs)
            mTabsTitle.AddTail(MUI::TextBuilder().tagContents(tab.first).object());
#endif
        for (auto &tab : tabs)
        {
#ifdef MUIM_Group_AddTail
            mComponent.AddTail(tab.second);
#else
            mComponent.AddMember(tab.second);
#endif
        }
    }
}
