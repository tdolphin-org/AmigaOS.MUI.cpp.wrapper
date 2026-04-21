//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Title.hpp"

#include <proto/alib.h>

#ifdef MUIC_Title

namespace MUI
{
    const std::string Title::className = MUIC_Title;

    TitleBuilder::TitleBuilder() { }

    bool Title::getClosable() const
    {
        return GetValueAsBool(MUIA_Title_Closable);
    }

    bool Title::getClickable() const
    {
        return GetValueAsBool(MUIA_Title_Clickable);
    }

    long Title::getEventHandlerPriority() const
    {
        return GetValueAsLong(MUIA_Title_EventHandlerPriority);
    }

#ifdef MUIA_Title_Newable
    bool Title::getNewable() const
    {
        return GetValueAsBool(MUIA_Title_Newable);
    }
#endif

    enum Title_OnLastClose Title::getOnLastClose() const
    {
        return (Title_OnLastClose)GetValueAsLong(MUIA_Title_OnLastClose);
    }

    enum Title_Position Title::getPosition() const
    {
        return (Title_Position)GetValueAsLong(MUIA_Title_Position);
    }

    bool Title::getSortable() const
    {
        return GetValueAsBool(MUIA_Title_Sortable);
    }

    Title &Title::setClickable(const bool clickable)
    {
        SetValue(MUIA_Title_Clickable, clickable);
        return *this;
    }

    Title &Title::setClosable(const bool closable)
    {
        SetValue(MUIA_Title_Closable, closable);
        return *this;
    }

    Title &Title::setEventHandlerPriority(const long eventHandlerPriority)
    {
        SetValue(MUIA_Title_EventHandlerPriority, eventHandlerPriority);
        return *this;
    }

#ifdef MUIA_Title_Newable
    Title &Title::setNewable(const bool newable)
    {
        SetValue(MUIA_Title_Newable, newable);
        return *this;
    }
#endif

    Title &Title::setOnLastClose(const enum Title_OnLastClose onLastClose)
    {
        SetValue(MUIA_Title_OnLastClose, (long)onLastClose);
        return *this;
    }

    Title &Title::setPosition(const enum Title_Position position)
    {
        SetValue(MUIA_Title_Position, (long)position);
        return *this;
    }

    Title &Title::setSortable(const bool sortable)
    {
        SetValue(MUIA_Title_Sortable, sortable);
        return *this;
    }

    Title &Title::Close(Object *pTitleObject)
    {
        DoMethod(muiObject(), MUIM_Title_Close, pTitleObject);
        return *this;
    }

#ifdef MUIM_Title_FindPage
    long Title::FindPage(Boopsiobject *pTitleButton)
    {
        return (long)DoMethod(muiObject(), MUIM_Title_FindPage, pTitleButton);
    }

    Title &Title::New()
    {
        DoMethod(muiObject(), MUIM_Title_New);
        return *this;
    }
#endif
}

#endif
