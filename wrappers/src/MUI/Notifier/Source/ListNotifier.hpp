//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/List.hpp"

namespace MUI
{
    template <typename T = List, typename U = DestListNotifier> class ListNotifier : public AreaNotifier<T, U>
    {
      public:
        ListNotifier() = delete;
        ListNotifier(const T &list)
          : AreaNotifier<T, U>(list)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_List_Active == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onActiveEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_DoubleClick ]
        SourceNotifier<T, U> onDoubleClick(const bool doubleClick);
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TotalPixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onTotalPixelEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_VisiblePixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onVisiblePixelEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TopPixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onTopPixelEveryTime();
    };

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onActiveEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_Active, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onDoubleClick(const bool doubleClick)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_DoubleClick, doubleClick);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onTotalPixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_TotalPixel, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onVisiblePixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_VisiblePixel, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onTopPixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_TopPixel, (long)MUIV_EveryTime);
    }
}
