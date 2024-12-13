//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"
#include "MUI/Area.hpp"
#include "MUI/ValueTypes/Notify/Trigger.hpp"

namespace MUI
{
    class DestAreaNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestAreaNotifier() = delete;
        DestAreaNotifier(const NotifierObject &notifierObject, const Area &area);
        DestAreaNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Disabled ]
        DestAreaNotifier &setDisabled(const bool disabled, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Disabled = @b MUIV_TriggerValue ]
        DestAreaNotifier &setDisabledTriggerValue(bool notify = true, enum Trigger trigger = Trigger::Value);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Disabled = @b MUIV_NotTriggerValue ]
        DestAreaNotifier &setSelected(const bool selected, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Selected = @b MUIV_TriggerValue ]
        DestAreaNotifier &setSelectedTriggerValue(bool notify = true, enum Trigger trigger = Trigger::Value);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Selected = @b MUIV_NotTriggerValue ]
        DestAreaNotifier &setShowMe(const bool showMe, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_ShowMe = @b MUIV_TriggerValue ]
        DestAreaNotifier &setShowMeTriggerValue(bool notify = true, enum Trigger trigger = Trigger::Value);
    };
}
