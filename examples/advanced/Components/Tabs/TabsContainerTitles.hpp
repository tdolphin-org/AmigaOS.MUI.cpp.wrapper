//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Group.hpp"
#include "MUI/Text.hpp"
#include "MUI/Title.hpp"

#include <string>
#include <vector>

namespace Components
{
    /// @brief Tabs/Pages with usage of MUI::Titles
    class TabsContainerTitles : public Root<MUI::Group>
    {
#ifdef MUIC_Title
        MUI::Title mTabsTitle;
#else
        MUI::Text mTitleNotSupportedText;
#endif
        MUI::Group mComponent;

      public:
        TabsContainerTitles(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);

        MUI::Group &muiRoot() const
        {
            return (MUI::Group &)mComponent;
        }
    };
}
