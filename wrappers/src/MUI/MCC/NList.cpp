//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "NList.hpp"

#include <proto/alib.h>

namespace MUI::MCC
{
    const std::string NList::className = MUIC_NList;

    NList &NList::InsertTop(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, entries, -1, MUIV_NList_Insert_Top, 0);
        return *this;
    }

    NList &NList::InsertActive(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, entries, -1, MUIV_NList_Insert_Active, 0);
        return *this;
    }

    NList &NList::InsertSorted(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, entries, -1, MUIV_NList_Insert_Sorted, 0);
        return *this;
    }

    NList &NList::InsertBottom(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_NList_Insert, entries, -1, MUIV_NList_Insert_Bottom, 0);
        return *this;
    }

    NList &NList::InsertWrapActive(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertWrap, entries, -1, MUIV_NList_Insert_Active, wrapcol, align, 0);
        return *this;
    }

    NList &NList::InsertWrapTop(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertWrap, entries, -1, MUIV_NList_Insert_Top, wrapcol, align, 0);
        return *this;
    }

    NList &NList::InsertWrapSorted(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertWrap, entries, -1, MUIV_NList_Insert_Sorted, wrapcol, align, 0);
        return *this;
    }

    NList &NList::InsertWrapBottom(const void *entries[], const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertWrap, entries, -1, MUIV_NList_Insert_Bottom, wrapcol, align, 0);
        return *this;
    }

    NList &NList::InsertSingleTop(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Top);
        return *this;
    }

    NList &NList::InsertSingleActive(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Active);
        return *this;
    }

    NList &NList::InsertSingleSorted(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Sorted);
        return *this;
    }

    NList &NList::InsertSingleBottom(const void *entry)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingle, entry, MUIV_NList_Insert_Bottom);
        return *this;
    }

    NList &NList::InsertSingleWrapTop(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Top, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapActive(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Active, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapSorted(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Sorted, wrapcol, align);
        return *this;
    }

    NList &NList::InsertSingleWrapBottom(const void *entry, const enum NList_WrapCol wrapcol, const enum NList_Align align)
    {
        DoMethod(muiObject(), MUIM_NList_InsertSingleWrap, entry, MUIV_NList_Insert_Bottom, wrapcol, align);
        return *this;
    }

    NList &NList::Clear()
    {
        DoMethod(muiObject(), MUIM_NList_Clear);
        return *this;
    }

    NList &NList::Redraw(long pos) const
    {
        DoMethod(muiObject(), MUIM_NList_Redraw, pos);
        return (NList &)*this;
    }

    NList &NList::RedrawActive() const
    {
        DoMethod(muiObject(), MUIM_NList_Redraw, MUIV_NList_Redraw_Active);
        return (NList &)*this;
    }

    NList &NList::RedrawAll(const void *entry) const
    {
        DoMethod(muiObject(), MUIM_NList_Redraw, MUIV_NList_Redraw_All);
        return (NList &)*this;
    }

    NList &NList::RedrawTitle() const
    {
        DoMethod(muiObject(), MUIM_NList_Redraw, MUIV_NList_Redraw_Title);
        return (NList &)*this;
    }

    NListBuilder::NListBuilder() { }
}
