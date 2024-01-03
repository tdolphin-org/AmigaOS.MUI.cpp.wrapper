//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"
#include "MUI/List.hpp"

namespace MUI
{
    enum class ListActivePage;

    class DestListNotifier : public DestAreaNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestListNotifier() = delete;
        DestListNotifier(const NotifierObject &notifierObject, const List &list);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_List_Active ]
        DestListNotifier &setActive(const long active, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_List_Active = @b MUIV_TriggerValue ]
        DestListNotifier &setActiveTriggerValue(bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_List_TopPixel ]
        DestListNotifier &setTopPixel(const long topPixel, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_List_TopPixel = @b MUIV_TriggerValue ]
        DestListNotifier &setTopPixelTriggerValue(bool notify = true);
    };
}
