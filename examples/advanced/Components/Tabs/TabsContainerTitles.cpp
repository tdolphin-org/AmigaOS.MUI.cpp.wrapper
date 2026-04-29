//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2026 TDolphin
//

#include "TabsContainerTitles.hpp"

#include "MUI/Core/MUICompileConfig.hpp"
#include "MUI/Text.hpp"

namespace Components
{
    TabsContainerTitles::TabsContainerTitles(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
#ifdef AOS_MUI_VERSION_5
      : mTabsTitle(MUI::TitleBuilder().tagClosable(true).tagNewable(true).object())
#else
      : mTitleNotSupportedText(MUI::TextBuilder().tagContents("MUI::Title not supported (compiled) by this MUI version").object())
#endif
      , mComponent(MUI::GroupBuilder()
                       .tagCycleChain()
#ifdef AOS_MUI_VERSION_5
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
#ifdef AOS_MUI_VERSION_5
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
