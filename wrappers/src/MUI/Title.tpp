//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_TITLE_TPP_INCLUDE
#error "Title.tpp should only be included by Title.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagClickable(const bool clickable)
    {
        this->PushTag(MUIA_Title_Clickable, clickable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagClosable(const bool closable)
    {
        this->PushTag(MUIA_Title_Closable, closable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagEventHandlerPriority(const long eventHandlerPriority)
    {
        this->PushTag(MUIA_Title_EventHandlerPriority, eventHandlerPriority);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagNewable(const bool newable)
    {
        this->PushTag(MUIA_Title_Newable, newable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagOnLastClose(const enum Title_OnLastClose onLastClose)
    {
        this->PushTag(MUIA_Title_OnLastClose, (long)onLastClose);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagPosition(const enum Title_Position position)
    {
        this->PushTag(MUIA_Title_Position, (long)position);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TitleBuilderTemplate<T, U>::tagSortable(const bool sortable)
    {
        this->PushTag(MUIA_Title_Sortable, sortable);
        return (T &)*this;
    }
}
