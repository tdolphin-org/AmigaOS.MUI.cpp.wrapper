//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/Group.hpp"

namespace MUI
{
    class GroupNotifier : public AreaNotifier
    {
        Group mGroup;

      public:
        GroupNotifier() = delete;
        GroupNotifier(const Group &group);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<Group, DestGroupNotifier> onActivePage(const long activePage);
        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<Group, DestGroupNotifier> onActivePage(const enum Group_ActivePage activePage);
    };
}
