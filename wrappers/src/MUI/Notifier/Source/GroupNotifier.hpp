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
    template <typename T = DestGroupNotifier> class GroupNotifier : public AreaNotifier<T>
    {
        Group mGroup;

      public:
        GroupNotifier() = delete;
        GroupNotifier(const Group &group)
          : AreaNotifier<T>(group)
          , mGroup(group)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<Group, T> onActivePage(const long activePage);
        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<Group, T> onActivePage(const enum Group_ActivePage activePage);
    };

    template <typename T> SourceNotifier<Group, T> inline GroupNotifier<T>::onActivePage(const long activePage)
    {
        return SourceNotifier<Group, T>(mGroup, MUIA_Group_ActivePage, activePage);
    }

    template <typename T> SourceNotifier<Group, T> inline GroupNotifier<T>::onActivePage(const enum Group_ActivePage activePage)
    {
        return SourceNotifier<Group, T>(mGroup, MUIA_Group_ActivePage, (long)activePage);
    }
}
