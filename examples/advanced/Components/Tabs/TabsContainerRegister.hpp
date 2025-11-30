//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"
#include "MUI/Register.hpp"

#include <string>
#include <vector>

namespace Components
{
    /// @brief Tabs/Pages with usage of MUI::Register
    class TabsContainerRegister : public Root<MUI::Register>
    {
        std::vector<std::string> mPageTitles;
        const char **mpPageTitlesArray;
        MUI::Register mComponent;

      public:
        TabsContainerRegister(const std::vector<std::pair<std::string, MUI::Area &>> &tabs);
        ~TabsContainerRegister();

        MUI::Register &muiRoot() const
        {
            return (MUI::Register &)mComponent;
        }
    };
}
