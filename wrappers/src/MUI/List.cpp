//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
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

    long List::getFirst() const
    {
        return GetValueAsLong(MUIA_List_First);
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    bool List::isQuiet() const
    {
        return GetValueAsBool(MUIA_List_Quiet);
    }
#endif

#ifdef MUIA_List_AutoVisible
    bool List::isAutoVisible() const
    {
        return GetValueAsBool(MUIA_List_AutoVisible);
    }
#endif

#ifdef MUIA_List_AgainClick
    bool List::isAgainClick() const
    {
        return GetValueAsBool(MUIA_List_AgainClick);
    }
#endif

#ifdef MUIA_List_ClickColumn
    long List::getClickColumn() const
    {
        return GetValueAsLong(MUIA_List_ClickColumn);
    }
#endif

#ifdef MUIA_List_DefClickColumn
    long List::getDefClickColumn() const
    {
        return GetValueAsLong(MUIA_List_DefClickColumn);
    }
#endif

#ifdef MUIA_List_DoubleClick
    bool List::isDoubleClick() const
    {
        return GetValueAsBool(MUIA_List_DoubleClick);
    }
#endif

#ifdef MUIA_List_DragSortable
    bool List::isDragSortable() const
    {
        return GetValueAsBool(MUIA_List_DragSortable);
    }
#endif

#ifdef MUIA_List_DragType
    List_DragType List::getDragType() const
    {
        return (List_DragType)GetValueAsLong(MUIA_List_DragType);
    }
#endif

#ifdef MUIA_List_DropMark
    long List::getDropMark() const
    {
        return GetValueAsLong(MUIA_List_DropMark);
    }
#endif

#ifdef MUIA_List_Editable
    bool List::isEditable() const
    {
        return GetValueAsBool(MUIA_List_Editable);
    }
#endif

    std::string List::getFormat() const
    {
        return GetValueAsString(MUIA_List_Format);
    }

#ifdef MUIA_List_InsertPosition
    long List::getInsertPosition() const
    {
        return GetValueAsLong(MUIA_List_InsertPosition);
    }
#endif

#ifdef MUIA_List_LineHeight
    unsigned long List::getLineHeight() const
    {
        return GetValueAsULong(MUIA_List_LineHeight);
    }
#endif

#ifdef MUIA_List_Pool
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    void *List::getPool() const
    {
        return GetValueAsPtr(MUIA_List_Pool);
    }
#endif
#endif

#ifdef MUIA_List_SelectChange
    bool List::isSelectChange() const
    {
        return GetValueAsBool(MUIA_List_SelectChange);
    }
#endif

#ifdef MUIA_List_ShowDropMarks
    bool List::isShowDropMarks() const
    {
        return GetValueAsBool(MUIA_List_ShowDropMarks);
    }
#endif

#ifdef MUIA_List_TopPixel
    long List::getTopPixel() const
    {
        return GetValueAsLong(MUIA_List_TopPixel);
    }
#endif

#ifdef MUIA_List_TotalPixel
    long List::getTotalPixel() const
    {
        return GetValueAsLong(MUIA_List_TotalPixel);
    }
#endif

    long List::getVisible() const
    {
        return GetValueAsLong(MUIA_List_Visible);
    }

#ifdef MUIA_List_VisiblePixel
    long List::getVisiblePixel() const
    {
        return GetValueAsLong(MUIA_List_VisiblePixel);
    }
#endif

#ifdef MUIA_List_Title
    const char *List::getTitlePtr() const
    {
        return GetValueAsConstCharPtr(MUIA_List_Title);
    }
#endif

#ifdef MUIA_List_TitleClick
    long List::getTitleClick() const
    {
        return GetValueAsLong(MUIA_List_TitleClick);
    }
#endif

#ifdef MUIA_List_TitleArray
    const char *const *List::getTitleArrayPtr() const
    {
        return static_cast<const char *const *>(GetValueAsPtr(MUIA_List_TitleArray));
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_SortColumn
    long List::getSortColumn() const
    {
        return GetValueAsLong(MUIA_List_SortColumn);
    }
#endif
#endif

#ifdef MUIA_List_ColumnOrder
    const unsigned char *List::getColumnOrderPtr() const
    {
        return static_cast<const unsigned char *>(GetValueAsPtr(MUIA_List_ColumnOrder));
    }
#endif

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

#ifdef MUIA_List_AutoVisible
    List &List::setAutoVisible(const bool autoVisible)
    {
        SetValue(MUIA_List_AutoVisible, autoVisible);
        return *this;
    }
#endif

#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_AgainClick
    List &List::setAgainClick(const bool againClick)
    {
        SetValue(MUIA_List_AgainClick, againClick);
        return *this;
    }
#endif
#endif

#ifdef MUIA_List_DefClickColumn
    List &List::setDefClickColumn(const long defClickColumn)
    {
        SetValue(MUIA_List_DefClickColumn, defClickColumn);
        return *this;
    }
#endif

#ifdef MUIA_List_CompareHook
    List &List::setCompareHook(const struct Hook *compareHook)
    {
        SetValue(MUIA_List_CompareHook, compareHook);
        return *this;
    }
#endif

#ifdef MUIA_List_ConstructHook
    List &List::setConstructHook(const struct Hook *constructHook)
    {
        SetValue(MUIA_List_ConstructHook, constructHook);
        return *this;
    }
#endif

#ifdef MUIA_List_DestructHook
    List &List::setDestructHook(const struct Hook *destructHook)
    {
        SetValue(MUIA_List_DestructHook, destructHook);
        return *this;
    }
#endif

#ifdef MUIA_List_DisplayHook
    List &List::setDisplayHook(const struct Hook *displayHook)
    {
        SetValue(MUIA_List_DisplayHook, displayHook);
        return *this;
    }
#endif

#ifdef MUIA_List_DragSortable
    List &List::setDragSortable(const bool dragSortable)
    {
        SetValue(MUIA_List_DragSortable, dragSortable);
        return *this;
    }
#endif

#ifdef MUIA_List_DragType
    List &List::setDragType(const enum List_DragType dragType)
    {
        SetValue(MUIA_List_DragType, (long)dragType);
        return *this;
    }
#endif

#ifdef MUIA_List_Editable
    List &List::setEditable(const bool editable)
    {
        SetValue(MUIA_List_Editable, editable);
        return *this;
    }
#endif

#ifdef MUIA_List_HideColumn
    List &List::setHideColumn(const long hideColumn)
    {
        SetValue(MUIA_List_HideColumn, hideColumn);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    List &List::setFirst(const long first)
    {
        SetValue(MUIA_List_First, first);
        return *this;
    }
#endif

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

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_SortColumn
    List &List::setSortColumn(const long sortColumn)
    {
        SetValue(MUIA_List_SortColumn, sortColumn);
        return *this;
    }
#endif
#endif

#ifdef MUIA_List_ShowColumn
    List &List::setShowColumn(const long showColumn)
    {
        SetValue(MUIA_List_ShowColumn, showColumn);
        return *this;
    }
#endif

#ifdef MUIA_List_MultiTestHook
    List &List::setMultiTestHook(const struct Hook *multiTestHook)
    {
        SetValue(MUIA_List_MultiTestHook, multiTestHook);
        return *this;
    }
#endif

#ifdef MUIA_List_ShowDropMarks
    List &List::setShowDropMarks(const bool showDropMarks)
    {
        SetValue(MUIA_List_ShowDropMarks, showDropMarks);
        return *this;
    }
#endif

#ifdef MUIA_List_ColumnOrder
    List &List::setColumnOrder(const unsigned char *columnOrder)
    {
        SetValue(MUIA_List_ColumnOrder, columnOrder);
        return *this;
    }
#endif

#ifdef MUIA_List_TopPixel
#if defined(MOS_MUI_VERSION_5)
    List &List::setTopPixel(const long topPixel)
    {
        SetValue(MUIA_List_TopPixel, topPixel);
        return *this;
    }
#endif
#endif

    List &List::setQuiet(const bool quiet)
    {
        SetValue(MUIA_List_Quiet, quiet);
        return *this;
    }

#ifdef MUIA_List_Title
    List &List::setTitle(const char *title)
    {
        SetValue(MUIA_List_Title, title);
        return *this;
    }

    List &List::setTitle(const std::string &title)
    {
        SetValue(MUIA_List_Title, title);
        return *this;
    }

    List &List::setTitle(const bool title)
    {
        SetValue(MUIA_List_Title, title);
        return *this;
    }
#endif

#ifdef MUIA_List_LineHeight
    List &List::setLineHeight(const unsigned long lineHeight)
    {
        SetValue(MUIA_List_LineHeight, lineHeight);
        return *this;
    }
#endif

#ifdef MUIA_List_MinLineHeight
    List &List::setMinLineHeight(const unsigned long minLineHeight)
    {
        SetValue(MUIA_List_MinLineHeight, minLineHeight);
        return *this;
    }
#endif

#ifdef MUIA_List_Stripes
    List &List::setStripes(const bool stripes)
    {
        SetValue(MUIA_List_Stripes, stripes);
        return *this;
    }
#endif

#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_ClickColumn
    List &List::setClickColumn(const long clickColumn)
    {
        SetValue(MUIA_List_ClickColumn, clickColumn);
        return *this;
    }
#endif
#endif

#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_DoubleClick
    List &List::setDoubleClick(const bool doubleClick)
    {
        SetValue(MUIA_List_DoubleClick, doubleClick);
        return *this;
    }
#endif
#endif

#if defined(MOS_MUI_VERSION_5)
#ifdef MUIA_List_TitleClick
    List &List::setTitleClick(const long titleClick)
    {
        SetValue(MUIA_List_TitleClick, titleClick);
        return *this;
    }
#endif
#endif

#ifdef MUIA_List_TitleArray
    List &List::setTitleArray(const char *const *titleArray)
    {
        SetValue(MUIA_List_TitleArray, titleArray);
        return *this;
    }
#endif

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
        const char *entry = reinterpret_cast<const char *>(GetEntry(position));
        return entry ? std::string(entry) : std::string();
    }

#ifdef MUIM_List_CreateImage
    void *List::CreateImage(Object *imageObject, const unsigned long flags) const
    {
        return reinterpret_cast<void *>(DoMethod(muiObject(), MUIM_List_CreateImage, imageObject, flags));
    }
#endif

#ifdef MUIM_List_DeleteImage
    List &List::DeleteImage(const void *listImage) const
    {
        DoMethod(muiObject(), MUIM_List_DeleteImage, listImage);
        return (List &)*this;
    }
#endif

    List &List::Remove(const long position)
    {
        DoMethod(muiObject(), MUIM_List_Remove, position);
        return *this;
    }

    long List::GetFirstSelected() const
    {
        return GetNextSelected(MUIV_List_NextSelected_Start);
    }

    long List::GetNextSelected(long position) const
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
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry, MUIV_List_Insert_Sorted);
        return *this;
    }

    List &List::InsertSingleTop(const std::string &entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry.c_str(), MUIV_List_Insert_Top);
        return *this;
    }

    List &List::InsertSingleBottom(const std::string &entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry.c_str(), MUIV_List_Insert_Bottom);
        return *this;
    }

    List &List::InsertSingleSorted(const std::string &entry)
    {
        DoMethod(muiObject(), MUIM_List_InsertSingle, (ULONG)entry.c_str(), MUIV_List_Insert_Sorted);
        return *this;
    }

    List &List::InsertTop(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_List_Insert, (ULONG)entries, -1, MUIV_List_Insert_Top);
        return *this;
    }

    List &List::InsertBottom(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_List_Insert, (ULONG)entries, -1, MUIV_List_Insert_Bottom);
        return *this;
    }

    List &List::InsertSorted(const void *entries[])
    {
        DoMethod(muiObject(), MUIM_List_Insert, (ULONG)entries, -1, MUIV_List_Insert_Sorted);
        return *this;
    }

    List &List::InsertTop(const std::vector<const char *> &entries)
    {
        for (auto entry : entries)
            InsertSingleTop(entry);
        return *this;
    }

    List &List::InsertBottom(const std::vector<const char *> &entries)
    {
        for (auto entry : entries)
            InsertSingleBottom(entry);
        return *this;
    }

    List &List::InsertSorted(const std::vector<const char *> &entries)
    {
        for (auto entry : entries)
            InsertSingleSorted(entry);
        return *this;
    }

    List &List::InsertTop(const std::vector<std::string> &entries)
    {
        for (const auto &entry : entries)
            InsertSingleTop(entry.c_str());
        return *this;
    }

    List &List::InsertBottom(const std::vector<std::string> &entries)
    {
        for (const auto &entry : entries)
            InsertSingleBottom(entry.c_str());
        return *this;
    }

    List &List::InsertSorted(const std::vector<std::string> &entries)
    {
        for (const auto &entry : entries)
            InsertSingleSorted(entry.c_str());
        return *this;
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

#ifdef MUIV_List_Redraw_Entry
    List &List::RedrawEntry(const void *entry) const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, MUIV_List_Redraw_Entry, entry);
        return (List &)*this;
    }
#endif

    List &List::RedrawAll() const
    {
        DoMethod(muiObject(), MUIM_List_Redraw, MUIV_List_Redraw_All, NULL);
        return (List &)*this;
    }

    List &List::Exchange(const long pos1, const long pos2)
    {
        DoMethod(muiObject(), MUIM_List_Exchange, pos1, pos2);
        return *this;
    }

    List &List::Move(const long from, const long to)
    {
        DoMethod(muiObject(), MUIM_List_Move, from, to);
        return *this;
    }

    List &List::Select(const long position, const long selectType, long *pState)
    {
        DoMethod(muiObject(), MUIM_List_Select, position, selectType, pState);
        return *this;
    }

    List &List::Sort()
    {
        DoMethod(muiObject(), MUIM_List_Sort);
        return *this;
    }

    bool List::TestPos(const long x, const long y, struct MUI_List_TestPos_Result *pResult) const
    {
        return (bool)DoMethod(muiObject(), MUIM_List_TestPos, x, y, pResult);
    }

#ifdef MUIM_List_QueryColumnWidth
    long List::QueryColumnWidth(const long column) const
    {
        return (long)DoMethod(muiObject(), MUIM_List_QueryColumnWidth, column);
    }
#endif

#ifdef MUIM_List_SortEntries
    bool List::SortEntries(void *entries[]) const
    {
        return (bool)DoMethod(muiObject(), MUIM_List_SortEntries, entries);
    }
#endif

#ifdef MUIM_List_EndEdit
    bool List::EndEdit(const unsigned long mode) const
    {
        return (bool)DoMethod(muiObject(), MUIM_List_EndEdit, mode);
    }
#endif

#ifdef MUIM_List_CreateEditObject
    Object *List::CreateEditObject(const long row, const long column, const void *entry) const
    {
        return reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_List_CreateEditObject, row, column, entry));
    }
#endif

#ifdef MUIM_List_Edit
    bool List::Edit(const long row, const long column) const
    {
        return (bool)DoMethod(muiObject(), MUIM_List_Edit, row, column);
    }
#endif

#ifdef MUIM_List_EditDone
    bool List::EditDone(const long row, const long column, const void *entry, Object *editobj) const
    {
        return (bool)DoMethod(muiObject(), MUIM_List_EditDone, row, column, entry, editobj);
    }
#endif

    ListBuilder::ListBuilder() { }
}
