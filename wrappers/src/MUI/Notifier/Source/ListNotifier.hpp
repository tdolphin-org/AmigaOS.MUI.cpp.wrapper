//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/List.hpp"

namespace MUI
{
    template <typename T = DestListNotifier> class ListNotifier : public AreaNotifier<T>
    {
        List mList;

      public:
        ListNotifier() = delete;
        ListNotifier(const List &list)
          : AreaNotifier<T>(list)
          , mList(list)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_List_Active == @b MUIV_EveryTime ]
        SourceNotifier<List, T> onActiveEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_DoubleClick ]
        SourceNotifier<List, T> onDoubleClick(const bool doubleClick);
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TotalPixel == @b MUIV_EveryTime ]
        SourceNotifier<List, T> onTotalPixelEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_VisiblePixel == @b MUIV_EveryTime ]
        SourceNotifier<List, T> onVisiblePixelEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_TopPixel == @b MUIV_EveryTime ]
        SourceNotifier<List, T> onTopPixelEveryTime();
    };

    template <typename T> SourceNotifier<List, T> inline ListNotifier<T>::onActiveEveryTime()
    {
        return SourceNotifier<List, T>(mList, MUIA_List_Active, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<List, T> inline ListNotifier<T>::onDoubleClick(const bool doubleClick)
    {
        return SourceNotifier<List, T>(mList, MUIA_List_DoubleClick, doubleClick);
    }

    template <typename T> SourceNotifier<List, T> inline ListNotifier<T>::onTotalPixelEveryTime()
    {
        return SourceNotifier<List, T>(mList, MUIA_List_TotalPixel, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<List, T> inline ListNotifier<T>::onVisiblePixelEveryTime()
    {
        return SourceNotifier<List, T>(mList, MUIA_List_VisiblePixel, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<List, T> inline ListNotifier<T>::onTopPixelEveryTime()
    {
        return SourceNotifier<List, T>(mList, MUIA_List_TopPixel, (long)MUIV_EveryTime);
    }
}
