//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Listview.hpp"

namespace MUI
{
    const std::string Listview::className = MUIC_Listview;

#ifdef MUIA_Listview_AgainClick
    bool Listview::isAgainClick() const
    {
        return GetValueAsBool(MUIA_Listview_AgainClick);
    }
#endif

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

    List Listview::getList() const
    {
        return List(GetValueAsObjectPtr(MUIA_Listview_List));
    }

    bool Listview::isSelectChange() const
    {
        return GetValueAsBool(MUIA_Listview_SelectChange);
    }

    Listview &Listview::setDefClickColumn(const long defClickColumn)
    {
        SetValue(MUIA_Listview_DefClickColumn, defClickColumn);
        return *this;
    }

    Listview &Listview::setDragType(const Listview_DragType dragType)
    {
        SetValue(MUIA_Listview_DragType, (long)dragType);
        return *this;
    }

    ListviewBuilder::ListviewBuilder() { }
}
