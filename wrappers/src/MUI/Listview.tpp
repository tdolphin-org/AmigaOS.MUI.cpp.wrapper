//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_LISTVIEW_TPP_INCLUDE
#error "Listview.tpp should only be included by Listview.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Listview_AgainClick
    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagAgainClick(const bool againClick)
    {
        this->PushTag(MUIA_Listview_AgainClick, againClick);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDefClickColumn(const long defClickColumn)
    {
        this->PushTag(MUIA_Listview_DefClickColumn, defClickColumn);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDoubleClick(const bool doubleClick)
    {
        this->PushTag(MUIA_Listview_DoubleClick, doubleClick);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagDragType(const enum Listview_DragType dragType)
    {
        this->PushTag(MUIA_Listview_DragType, (long)dragType);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_Listview_Input, input);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagList(const MUI::List &list)
    {
        hasListObject = true;
        this->PushTag(MUIA_Listview_List, list.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagList(const Object *pList)
    {
        hasListObject = pList != nullptr;
        this->PushTag(MUIA_Listview_List, pList);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagMultiSelect(const enum Listview_MultiSelect multiSelect)
    {
        this->PushTag(MUIA_Listview_MultiSelect, (long)multiSelect);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ListviewBuilderTemplate<T, U>::tagScrollerPos(const enum Listview_ScrollerPos scrollerPos)
    {
        this->PushTag(MUIA_Listview_ScrollerPos, (long)scrollerPos);
        return (T &)*this;
    }

    template <typename T, typename U> inline bool ListviewBuilderTemplate<T, U>::Validate() const
    {
        auto result = GroupBuilderTemplate<T, U>::Validate();

        // Each listview needs a list object as child. The list object is mandatory for listview, without it object will fail on creation.
        // So check if there is tag for List (not null).
        if (!hasListObject)
        {
            std::cerr << __PRETTY_FUNCTION__ << ", missing List object for Listview!" << std::endl;
            result = false;
        }

        return result;
    }
}
