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
    class ListNotifier : public AreaNotifier
    {
        List mList;

      public:
        ListNotifier() = delete;
        ListNotifier(const List &list);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_List_Active == @b MUIV_EveryTime ]
        SourceNotifier<List, DestListNotifier> onActiveEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_List_DoubleClick ]
        SourceNotifier<List, DestListNotifier> onDoubleClick(const bool doubleClick);
    };
}
