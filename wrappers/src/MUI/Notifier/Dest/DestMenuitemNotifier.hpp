//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestFamilyNotifier.hpp"
#include "MUI/Menuitem.hpp"

namespace MUI
{
    enum class MenuitemActivePage;

    class DestMenuitemNotifier : public DestFamilyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestMenuitemNotifier() = delete;
        DestMenuitemNotifier(const NotifierObject &notifierObject, const Menuitem &menuitem);
        DestMenuitemNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Menuitem_Checked ]
        DestMenuitemNotifier &setChecked(const bool checked, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Menuitem_Checked = @b MUIV_TriggerValue ]
        DestMenuitemNotifier &setCheckedTriggerValue(bool notify = true);
    };
}
