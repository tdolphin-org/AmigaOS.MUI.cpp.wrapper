//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "List.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string List::className = MUIC_List;

    long List::getActive() const
    {
        return GetValueAsLong(MUIA_List_Active);
    }

    bool List::isActiveOff() const
    {
        return GetValueAsLong(MUIA_List_Active) == MUIV_List_Active_Off;
    }

    long List::getEntries() const
    {
        return GetValueAsLong(MUIA_List_Entries);
    }

    bool List::isQuiet() const
    {
        return GetValueAsBool(MUIA_List_Quiet);
    }

    List &List::setActive(const long active)
    {
        SetValue(MUIA_List_Active, active);
        return *this;
    }

    List &List::setActive(const enum List_Active active)
    {
        SetValue(MUIA_List_Active, (long)active);
        return *this;
    }

    List &List::setActiveOff()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_Off);
        return *this;
    }

    List &List::setActiveTop()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_Top);
        return *this;
    }

    List &List::setActiveBottom()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_Bottom);
        return *this;
    }

    List &List::setActiveUp()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_Up);
        return *this;
    }

    List &List::setActiveDown()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_Down);
        return *this;
    }

    List &List::setActivePageUp()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_PageUp);
        return *this;
    }

    List &List::setActivePageDown()
    {
        SetValue(MUIA_List_Active, (long)MUIV_List_Active_PageDown);
        return *this;
    }

    List &List::setFormat(const char *format)
    {
        SetValue(MUIA_List_Format, format);
        return *this;
    }

    List &List::setFormat(const std::string &format)
    {
        SetValue(MUIA_List_Format, format);
        return *this;
    }

    List &List::setSortColumn(const long sortColumn)
    {
        SetValue(MUIA_List_SortColumn, sortColumn);
        return *this;
    }

    List &List::setQuiet(const bool quiet)
    {
        SetValue(MUIA_List_Quiet, quiet);
        return *this;
    }

    List &List::Jump(const enum List_Jump position)
    {
        DoMethod(muiObject(), MUIM_List_Jump, (long)position);
        return *this;
    }

    List &List::Jump(const long position)
    {
        DoMethod(muiObject(), MUIM_List_Jump, position);
        return *this;
    }

    void *List::GetEntry(const long position) const
    {
        void *entry;
        DoMethod(muiObject(), MUIM_List_GetEntry, position, &entry);
        return entry;
    }

    std::string List::GetEntryAsString(const long position) const
    {
        return std::string((char *)GetEntry(position));
    }

    List &List::Remove(const long position)
    {
        DoMethod(muiObject(), MUIM_List_Remove, position);
        return *this;
    }

    long List::GetFirstSelected() const
    {
        return GetNextSelected(MUIM_List_NextSelected);
    }

    long List::GetNextSelected(const long position) const
    {
        DoMethod(muiObject(), MUIM_List_NextSelected, &position);
        return position;
    }

    std::vector<long> List::GetAllSelected() const
    {
        std::vector<long> result;

        long position = MUIV_List_NextSelected_Start;
        while (true)
        {
            position = GetNextSelected(position);
            if (position == MUIV_List_NextSelected_End)
                break;
            result.push_back(position);
        }

        return result;
    }

    List &List::InsertSingleTop(const void *entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry, MUIV_List_Insert_Top);
        return *this;
    }

    List &List::InsertSingleBottom(const void *entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry, MUIV_List_Insert_Bottom);
        return *this;
    }

    List &List::InsertSingleSorted(const void *entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry, MUIV_List_Insert_Top);
        return *this;
    }

    List &List::InsertTop(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_List_Insert, (ULONG)entries, -1, MUIV_List_Insert_Bottom);
        return *this;
    }

    List &List::InsertBottom(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_List_Insert, (ULONG)entries, -1, MUIV_List_Insert_Bottom);
        return *this;
    }

    List &List::InsertBottom(const char *entries[])
    {
        return InsertBottom((const void **)entries);
    }

    List &List::Clear()
    {
        DoMethod(muiObject(), MUIM_List_Clear);
        return *this;
    }

    List &List::Redraw(long pos) const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, pos, NULL);
        return (List &)*this;
    }

    List &List::RedrawActive() const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, MUIV_List_Redraw_Active, NULL);
        return (List &)*this;
    }

    List &List::RedrawEntry(const void *entry) const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, MUIV_List_Redraw_Entry, entry);
        return (List &)*this;
    }

    List &List::RedrawAll() const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, MUIV_List_Redraw_All, NULL);
        return (List &)*this;
    }

    ListBuilder::ListBuilder() { }
}
