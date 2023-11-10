//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "ListNotifier.hpp"

namespace MUI
{
    ListNotifier::ListNotifier(const List &list)
      : AreaNotifier(list)
      , mList(list)
    {
    }

    SourceNotifier<List, DestListNotifier> ListNotifier::onActiveEveryTime()
    {
        return SourceNotifier<List, DestListNotifier>(mList, MUIA_List_Active, (long)MUIV_EveryTime);
    }

    SourceNotifier<List, DestListNotifier> ListNotifier::onDoubleClick(const bool doubleClick)
    {
        return SourceNotifier<List, DestListNotifier>(mList, MUIA_List_DoubleClick, doubleClick);
    }

    SourceNotifier<List, DestListNotifier> ListNotifier::onTotalPixelEveryTime()
    {
        return SourceNotifier<List, DestListNotifier>(mList, MUIA_List_TotalPixel, (long)MUIV_EveryTime);
    }

    SourceNotifier<List, DestListNotifier> ListNotifier::onVisiblePixelEveryTime()
    {
        return SourceNotifier<List, DestListNotifier>(mList, MUIA_List_VisiblePixel, (long)MUIV_EveryTime);
    }

    SourceNotifier<List, DestListNotifier> ListNotifier::onTopPixelEveryTime()
    {
        return SourceNotifier<List, DestListNotifier>(mList, MUIA_List_TopPixel, (long)MUIV_EveryTime);
    }
}
