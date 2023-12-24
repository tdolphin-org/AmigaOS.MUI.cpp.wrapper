//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    template <typename T = DestAreaNotifier> class AreaNotifier : public NotifyNotifier<T>
    {
        Area mArea;

      public:
        AreaNotifier() = delete;
        AreaNotifier(const Area &area)
          : NotifyNotifier<T>(area)
          , mArea(area)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Selected ]
        SourceNotifier<Area, T> onSelected(const bool selected);
        /// @brief [ @b MUIM_Notify, @b MUIA_Selected == @b MUIV_EveryTime ]
        SourceNotifier<Area, T> onSelectedEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed ]
        SourceNotifier<Area, T> onPressed(const bool pressed);
        /// @brief [ @b MUIM_Notify, @b MUIA_Pressed  == @b MUIV_EveryTime ]
        SourceNotifier<Area, T> onPressedEveryTime();
    };

    template <typename T> SourceNotifier<Area, T> inline AreaNotifier<T>::onSelected(const bool selected)
    {
        return SourceNotifier<Area, T>(mArea, MUIA_Selected, selected);
    }

    template <typename T> SourceNotifier<Area, T> inline AreaNotifier<T>::onSelectedEveryTime()
    {
        return SourceNotifier<Area, T>(mArea, MUIA_Selected, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Area, T> inline AreaNotifier<T>::onPressed(const bool pressed)
    {
        return SourceNotifier<Area, T>(mArea, MUIA_Pressed, pressed);
    }

    template <typename T> SourceNotifier<Area, T> inline AreaNotifier<T>::onPressedEveryTime()
    {
        return SourceNotifier<Area, T>(mArea, MUIA_Pressed, (long)MUIV_EveryTime);
    }
}
