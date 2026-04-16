//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2026 TDolphin
//

#include "TabsContainerRegister.hpp"

namespace Components
{
    TabsContainerRegister::TabsContainerRegister(const std::vector<std::pair<std::string, MUI::Area &>> &tabs)
      : mPageTitles()
      , mpPageTitlesArray(new const char *[tabs.size() + 1])
      , mComponent(MUI::RegisterBuilder()
                       .tagTitles([&]() {
                           unsigned int index = 0;
                           mPageTitles.reserve(tabs.size());
                           for (const auto &tab : tabs)
                           {
                               mPageTitles.emplace_back(tab.first);
                               mpPageTitlesArray[index++] = mPageTitles.back().c_str();
                           }
                           mpPageTitlesArray[index] = nullptr;
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