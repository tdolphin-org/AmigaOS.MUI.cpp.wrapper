//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"
#include "MUI/Title.hpp"
#include "MUI/Text.hpp"

#include <string>
#include <vector>

namespace Components
{
    /// @brief Tabs/Pages with usage of MUI::Titles
    class TabsContainerTitles : public Root
    {
#ifdef ifdef MUIC_Title
        MUI::Title mTabsTitle;
#else
        MUI::Text mTitleNotSupportedText;
#endif
        MUI::Group mComponent;

      public:
        TabsContainerTitles(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);

        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
