//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Listview.hpp"

namespace MUI
{
    bool Listview::isAgainClick() const
    {
        return GetValueAsBool(MUIA_Listview_AgainClick);
    }

    long Listview::getClickColumn() const
    {
        return GetValueAsLong(MUIA_Listview_ClickColumn);
    }

    long Listview::getDefClickColumn() const
    {
        return GetValueAsLong(MUIA_Listview_DefClickColumn);
    }

    bool Listview::isDoubleClick() const
    {
        return GetValueAsBool(MUIA_Listview_DoubleClick);
    }

    Listview_DragType Listview::getDragType() const
    {
        return Listview_DragType(GetValueAsLong(MUIA_Listview_DragType));
    }

    List Listview::getList()
    {
        return List(GetValueAsObjectPtr(MUIA_Listview_List));
    }

    bool Listview::isSelectChange() const
    {
        return GetValueAsBool(MUIA_Listview_SelectChange);
    }

    ListviewBuilder::ListviewBuilder() { }
}
