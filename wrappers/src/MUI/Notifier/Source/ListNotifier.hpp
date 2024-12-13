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

        /// @brief [ @b MUIM_Notify, @b MUIA_List_Active ]
        SourceNotifier<T, U> onActive(const enum List_Active active);
        /// @brief [ @b MUIM_Notify, @b MUIA_List_Active == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onActiveEveryTime();
#ifdef MUIA_List_DoubleClick
        /// @brief [ @b MUIM_Notify, @b MUIA_List_DoubleClick ]
        SourceNotifier<T, U> onDoubleClick(const bool doubleClick);
#endif
#ifdef MUIA_List_TotalPixel
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TotalPixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onTotalPixelEveryTime();
#endif
#ifdef MUIA_List_VisiblePixel
        /// @brief [ @b MUIM_Notify, @b MUIA_List_VisiblePixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onVisiblePixelEveryTime();
#endif
#ifdef MUIA_List_TopPixel
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TopPixel == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onTopPixelEveryTime();
#endif
    };

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onActive(const enum List_Active active)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_Active, (long)active);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onActiveEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_Active, (long)MUIV_EveryTime);
    }

#ifdef MUIA_List_DoubleClick
    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onDoubleClick(const bool doubleClick)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_DoubleClick, doubleClick);
    }
#endif

#ifdef MUIA_List_TotalPixel
    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onTotalPixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_TotalPixel, (long)MUIV_EveryTime);
    }
#endif

#ifdef MUIA_List_VisiblePixel
    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onVisiblePixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_VisiblePixel, (long)MUIV_EveryTime);
    }
#endif

#ifdef MUIA_List_TopPixel
    template <typename T, typename U> SourceNotifier<T, U> inline ListNotifier<T, U>::onTopPixelEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_List_TopPixel, (long)MUIV_EveryTime);
    }
#endif
}
