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

#ifdef MUIA_Title_Closable
    bool Title::getClosable() const
    {
        return GetValueAsBool(MUIA_Title_Closable);
    }
#endif

#ifdef MUIA_Title_Newable
    bool Title::getNewable() const
    {
        return GetValueAsBool(MUIA_Title_Newable);
    }
#endif

#ifdef MUIA_Title_Position
    enum Title_Position Title::getPosition() const
    {
        return (Title_Position)GetValueAsLong(MUIA_Title_Position);
    }
#endif

#ifdef MUIA_Title_Sortable
    bool Title::getSortable() const
    {
        return GetValueAsBool(MUIA_Title_Sortable);
    }
#endif

#ifdef MUIA_Title_Closable
    Title &Title::setClosable(const bool closable)
    {
        SetValue(MUIA_Title_Closable, closable);
        return *this;
    }
#endif

#ifdef MUIA_Title_Newable
    Title &Title::setNewable(const bool newable)
    {
        SetValue(MUIA_Title_Newable, newable);
        return *this;
    }
#endif

#ifdef MUIA_Title_OnLastClose
    Title &Title::setOnLastClose(const enum Title_OnLastClose onLastClose)
    {
        SetValue(MUIA_Title_OnLastClose, (long)onLastClose);
        return *this;
    }
#endif

#ifdef MUIA_Title_Position
    Title &Title::setPosition(const enum Title_Position position)
    {
        SetValue(MUIA_Title_Position, (long)position);
        return *this;
    }
#endif

#ifdef MUIA_Title_Sortable
    Title &Title::setSortable(const bool sortable)
    {
        SetValue(MUIA_Title_Sortable, sortable);
        return *this;
    }
#endif

#ifdef MUIM_Title_Close
    Title &Title::Close(Object *pTitleObject)
    {
        DoMethod(muiObject(), MUIM_Title_Close, pTitleObject);
        return *this;
    }
#endif

#ifdef MUIM_Title_FindPage
    Object *Title::FindPage(Boopsiobject *pTitleButton)
    {
        return reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_Title_FindPage, pTitleButton));
    }

    Title &Title::New()
    {
        DoMethod(muiObject(), MUIM_Title_New);
        return *this;
    }
#endif
}

#endif
