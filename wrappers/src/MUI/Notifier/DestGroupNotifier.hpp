//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"

namespace MUI
{
     enum class GroupActivePage;

    class DestGroupNotifier : public DestAreaNotifier
    {
        friend class SourceNotifier;

      protected:
        DestGroupNotifier(const SourceNotifier &sourceNotifier, const Group &group);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Group_ActivePage ]
        DestGroupNotifier &setActivePage(const long activePage, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Group_ActivePage ]
        DestGroupNotifier &setActivePage(const enum GroupActivePage activePage, bool notify = true);
    };
}
