//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Title.hpp"

#ifdef MUIC_Title

namespace MUI
{
    const std::string Title::className = MUIC_Title;

    TitleBuilder::TitleBuilder() { }

    bool Title::getClosable() const
    {
        return GetValueAsBool(MUIA_Title_Closable);
    }

#ifdef MUI_Title_Newable
    bool Title::getNewable() const
    {
        return GetValueAsBool(MUIA_Title_Newable);
    }
#endif

    enum Title_Position Title::getPosition() const
    {
        return (Title_Position)GetValueAsLong(MUIA_Title_Position);
    }

    long Title::getSortable() const
    {
        return GetValueAsLong(MUIA_Title_Sortable);
    }

    Title &Title::setClosable(const bool closable)
    {
        SetValue(MUIA_Title_Closable, closable);
        return *this;
    }

#ifdef MUI_Title_Newable
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
}

#endif
