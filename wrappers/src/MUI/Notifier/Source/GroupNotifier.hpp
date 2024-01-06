//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/Group.hpp"

namespace MUI
{
    template <typename T = Group, typename U = DestGroupNotifier> class GroupNotifier : public AreaNotifier<T, U>
    {
      public:
        GroupNotifier() = delete;
        GroupNotifier(const T &group)
          : AreaNotifier<T, U>(group)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<T, U> onActivePage(const long activePage);
        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage ]
        SourceNotifier<T, U> onActivePage(const enum Group_ActivePage activePage);
        /// @brief [ @b MUIM_Notify, @b MUIA_Group_ActivePage == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onActivePageEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline GroupNotifier<T, U>::onActivePage(const long activePage)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Group_ActivePage, activePage);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline GroupNotifier<T, U>::onActivePage(const enum Group_ActivePage activePage)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Group_ActivePage, (long)activePage);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> GroupNotifier<T, U>::onActivePageEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Group_ActivePage, (long)MUIV_EveryTime);
    }
}
