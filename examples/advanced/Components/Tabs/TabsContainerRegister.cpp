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
    {
        for (auto &tab : tabs)
        {
#ifdef MUIM_Group_AddTail
            mComponent.AddTail(tab.second);
#else
            mComponent.AddMember(tab.second);
#endif
        }
    }

    TabsContainerRegister::~TabsContainerRegister()
    {
        delete[] mpPageTitlesArray;
    }
}