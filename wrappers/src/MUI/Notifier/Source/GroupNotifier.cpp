//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "GroupNotifier.hpp"

namespace MUI
{
    GroupNotifier::GroupNotifier(const Group &group)
      : mGroup(group)
      , AreaNotifier(group)
    {
    }

    SourceNotifier<Group, DestGroupNotifier> GroupNotifier::onActivePage(const long activePage)
    {
        return SourceNotifier<Group, DestGroupNotifier>(mGroup, MUIA_Group_ActivePage, activePage);
    }

    SourceNotifier<Group, DestGroupNotifier> GroupNotifier::onActivePage(const enum Group_ActivePage activePage)
    {
        return SourceNotifier<Group, DestGroupNotifier>(mGroup, MUIA_Group_ActivePage, (long)activePage);
    }
}
