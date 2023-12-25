//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Area.hpp"

#include <proto/alib.h>

namespace MUI
{
#ifndef __MORPHOS__
    Dim::Dim(const unsigned long value)
    {
        width = DIM2WIDTH(value);
        height = DIM2HEIGHT(value);
    }
#endif

    const std::string Area::className = MUIC_Area;

    bool Area::isSelected() const
    {
        return GetValueAsBool(MUIA_Selected);
    }

    bool Area::isFloating() const
    {
        return GetValueAsBool(MUIA_Floating);
    }

    long Area::getBottomEdge() const
    {
        return GetValueAsLong(MUIA_BottomEdge);
    }

    Object *Area::getContextMenu() const
    {
        return GetValueAsObjectPtr(MUIA_ContextMenu);
    }

#ifndef __MORPHOS__
    Hook *Area::getContextMenuHook() const
    {
        return GetValueAsHookPtr(MUIA_ContextMenuHook);
    }
#endif

    Object *Area::getContextMenuTrigger() const
    {
        return GetValueAsObjectPtr(MUIA_ContextMenuTrigger);
    }

    char Area::getControlChar() const
    {
        return GetValueAsChar(MUIA_ControlChar);
    }

    long Area::getCycleChain() const
    {
        return GetValueAsLong(MUIA_CycleChain);
    }

    Area &Area::setBackground(const enum ImageOrBackground background)
    {
        SetValue(MUIA_Background, (long)background);
        return *this;
    }

    Area &Area::setBackground(const std::string &background)
    {
        SetValue(MUIA_Background, (long)background.c_str());
        return *this;
    }

    Area &Area::setCycleChain(const long cycleChain)
    {
        SetValue(MUIA_CycleChain, cycleChain);
        return *this;
    }

    Area &Area::setDisabled(const bool disabled)
    {
        SetValue(MUIA_Disabled, disabled);
        return *this;
    }

    Area &Area::setFillArea(const bool fillArea)
    {
        SetValue(MUIA_FillArea, fillArea);
        return *this;
    }

    Area &Area::setFloating(const bool floating)
    {
        SetValue(MUIA_Floating, floating);
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
        auto copy = StoreString(shortHelp);
        SetValue(MUIA_ShortHelp, copy);
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

    Area &Area::Relayout()
    {
        DoMethod(muiObject(), MUIM_Relayout, 0);
        return *this;
    }

#ifndef __MORPHOS__
    Area &Area::Text(const long left, const long top, const long width, const long height, const std::string &text, const long len,
                     const std::string &preparse, const char ulchar)
    {
        DoMethod(muiObject(), MUIM_Text, left, top, width, height, text.c_str(), len, preparse.empty() ? nullptr : preparse.c_str(),
                 ulchar);
        return *this;
    }

    Dim Area::TextDim(const std::string &text, const long len, const std::string &preparse, const long flags)
    {
        return Dim(DoMethod(muiObject(), MUIM_TextDim, text.c_str(), len, preparse.empty() ? nullptr : preparse.c_str(), flags));
    }
#endif

    AreaBuilder::AreaBuilder() { }
}