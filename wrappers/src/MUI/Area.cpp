//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Area.hpp"

#include "Notifier/Core/SourceNotifier.hpp"

namespace MUI
{
    bool Area::getSelected() const
    {
        return GetValueAsBool(MUIA_Selected);
    }

    Area &Area::setDisabled(const bool disabled)
    {
        SetValue(MUIA_Disabled, disabled);
        return *this;
    }

    Area &Area::setFont(const enum Font font)
    {
        SetValue(MUIA_Font, (long)font);
        return *this;
    }

#ifndef __MORPHOS__
    Area &Area::setPointerType(const enum PointerType pointerType)
    {
        SetValue(MUIA_PointerType, (long)pointerType);
        return *this;
    }
#endif

    Area &Area::setSelected(const bool selected)
    {
        SetValue(MUIA_Selected, selected);
        return *this;
    }

    Area &Area::setShortHelp(const std::string &shortHelp)
    {
        SetValue(MUIA_ShortHelp, shortHelp);
        return *this;
    }

    Area &Area::Enable()
    {
        setDisabled(false);
        return *this;
    }

    Area &Area::Disable()
    {
        setDisabled(true);
        return *this;
    }

    SourceNotifier Area::onSelected(const bool trigValue)
    {
        return SourceNotifier(*this, MUIA_Selected, trigValue);
    }

    SourceNotifier Area::onPressed(const bool trigValue)
    {
        return SourceNotifier(*this, MUIA_Pressed, trigValue);
    }

    AreaBuilder::AreaBuilder() { }
}