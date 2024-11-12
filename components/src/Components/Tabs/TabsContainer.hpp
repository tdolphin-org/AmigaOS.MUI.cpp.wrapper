//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Register.hpp"

#include <string>
#include <vector>

namespace Components
{
    /// @brief Tabs/Pages with usage of MUI::Register
    class TabsContainer : public Root<MUI::Register>
    {
#ifdef MUIC_Title
        MUI::Title mTabsTitle;
        MUI::Group mComponent;
#else
        std::vector<std::string> mPageTitles;
        const char **mpPageTitlesArray;
        MUI::Register mComponent;
#endif

      public:
        TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);
        ~TabsContainer();

        MUI::Register &muiRoot() const
        {
            return (MUI::Register &)mComponent;
        }
    };
}
