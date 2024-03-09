//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "TabsContainerRegister.hpp"

namespace Components
{
    TabsContainerRegister::TabsContainerRegister(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
      : mPageTitles(tabs.size())
      , mComponent(MUI::RegisterBuilder().object())
    {
        mpPageTitlesArray = new const char *[tabs.size()];
        unsigned int index = 0;
        for (auto &tab : tabs)
        {
            mPageTitles.push_back(tab.first);
            mpPageTitlesArray[index++] = (char *)mPageTitles.back().c_str();
        }
        mpPageTitlesArray[index++] = (char *)nullptr;
        mComponent.setTitles(mpPageTitlesArray);

        for (auto &tab : tabs)
            mComponent.AddTail(tab.second);
    }

    TabsContainerRegister::~TabsContainerRegister()
    {
        delete[] mpPageTitlesArray;
    }
}