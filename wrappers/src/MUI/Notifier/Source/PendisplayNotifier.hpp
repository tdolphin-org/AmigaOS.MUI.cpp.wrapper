//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/Pendisplay.hpp"

namespace MUI
{
    template <typename T = Pendisplay, typename U = DestPendisplayNotifier> class PendisplayNotifier : public AreaNotifier<T, U>
    {
      public:
        PendisplayNotifier() = delete;
        PendisplayNotifier(const T &pendisplay)
          : AreaNotifier<T, U>(pendisplay)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Pendisplay_Reference == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onReference();
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Pendisplay_RGBcolor == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onRGBcolor();
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Pendisplay_Spec == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onSpec();
    };

    template <typename T, typename U> inline SourceNotifier<T, U> PendisplayNotifier<T, U>::onReference()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Pendisplay_Reference, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> PendisplayNotifier<T, U>::onRGBcolor()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Pendisplay_RGBcolor, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> PendisplayNotifier<T, U>::onSpec()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Pendisplay_Spec, (long)MUIV_EveryTime);
    }
}
