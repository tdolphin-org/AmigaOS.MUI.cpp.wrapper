//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    template <typename T = Area, typename U = DestAreaNotifier> class AreaNotifier : public NotifyNotifier<T, U>
    {
      public:
        AreaNotifier() = delete;
        AreaNotifier(const T &area)
          : NotifyNotifier<T, U>(area)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Selected ]
        SourceNotifier<T, U> onSelected(const bool selected);
        /// @brief [ @b MUIM_Notify, @b MUIA_Selected == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onSelectedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed ]
        SourceNotifier<T, U> onPressed(const bool pressed);
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed  == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onPressedEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline AreaNotifier<T, U>::onSelected(const bool selected)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Selected, selected);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline AreaNotifier<T, U>::onSelectedEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Selected, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline AreaNotifier<T, U>::onPressed(const bool pressed)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Pressed, pressed);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline AreaNotifier<T, U>::onPressedEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Pressed, (long)MUIV_EveryTime);
    }
}
