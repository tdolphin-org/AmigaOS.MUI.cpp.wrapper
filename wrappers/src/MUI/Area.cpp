//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Area.hpp"

namespace MUI
{
    bool Area::isSelected() const
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

    Area &Area::setShowMe(const bool showMe)
    {
        SetValue(MUIA_ShowMe, showMe);
        return *this;
    }

    Area &Area::Enable()
    {
        return setDisabled(false);
    }

    Area &Area::Disable()
    {
        return setDisabled(true);
    }

    Area &Area::Show()
    {
        return setShowMe(true);
    }

    Area &Area::Hide()
    {
        return setShowMe(false);
    }

    AreaBuilder::AreaBuilder() { }
}