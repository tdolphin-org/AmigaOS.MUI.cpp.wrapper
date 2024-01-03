//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/Group.hpp"

namespace MUI
{
    enum class Group_ActivePage;

    class DestGroupNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestGroupNotifier() = delete;
        DestGroupNotifier(const NotifierObject &notifierObject, const Group &group);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Group_ActivePage ]
        /// @param activePage index of page to activate (unsigned long to prevent pass #define < 0)
        DestGroupNotifier &setActivePage(const unsigned long activePage, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Group_ActivePage ]
        DestGroupNotifier &setActivePage(const enum Group_ActivePage activePage, bool notify = true);
    };
}
