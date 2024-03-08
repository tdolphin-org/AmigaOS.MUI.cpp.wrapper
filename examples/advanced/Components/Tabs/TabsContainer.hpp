//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"

#ifdef __MORPHOS__
#include "MUI/Register.hpp"
#else
#include "MUI/Group.hpp"
#include "MUI/Title.hpp"
#endif

#include <string>
#include <vector>

namespace Components
{
    class TabsContainer : public Root
    {
#ifdef __MORPHOS__
        std::vector<std::string> mPageTitles;
        const char **mpPageTitlesArray;
        MUI::Register mComponent;
#else
        MUI::Title mTabsTitle;
        MUI::Group mComponent;
#endif

      public:
        TabsContainer(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);
        ~TabsContainer();

        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}
