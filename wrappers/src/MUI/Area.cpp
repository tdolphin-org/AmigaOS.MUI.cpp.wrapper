//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Area.hpp"

#include <proto/alib.h>

#ifdef MUIM_TextDim
#define DIM2WIDTH(dim) (((LONG)(dim)) & 0xffff)
#define DIM2HEIGHT(dim) (((LONG)(dim)) >> 16)
#endif

namespace MUI
{
#ifdef MUIM_TextDim
    Dim::Dim(const unsigned long value)
    {
        width = DIM2WIDTH(value);
        height = DIM2HEIGHT(value);
    }
#endif

    const std::string Area::className = MUIC_Area;

    long Area::getBottomEdge() const
    {
        return GetValueAsLong(MUIA_BottomEdge);
    }

    Object *Area::getContextMenu() const
    {
        return GetValueAsObjectPtr(MUIA_ContextMenu);
    }

#ifdef MUIA_ContextMenuHook
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

    bool Area::isDisabled() const
    {
        return GetValueAsBool(MUIA_Disabled);
    }

#ifdef MUIA_DoubleBuffer
    bool Area::isDoubleBuffer() const
    {
        return GetValueAsBool(MUIA_DoubleBuffer);
    }
#endif

#ifdef MUIA_DoubleClick
    bool Area::isDoubleClick() const
    {
        return GetValueAsBool(MUIA_DoubleClick);
    }
#endif

    bool Area::isDraggable() const
    {
        return GetValueAsBool(MUIA_Draggable);
    }

    bool Area::isDropable() const
    {
        return GetValueAsBool(MUIA_Dropable);
    }

#ifdef MUIA_Floating
    bool Area::isFloating() const
    {
        return GetValueAsBool(MUIA_Floating);
    }
#endif

    TextFont *Area::getFont() const
    {
        return (TextFont *)GetValueAsPtr(MUIA_Font);
    }

#ifdef MUIA_FrameDynamic
    bool Area::isFrameDynamic() const
    {
        return GetValueAsBool(MUIA_FrameDynamic);
    }
#endif

    std::string Area::getFrameTitle() const
    {
        return GetValueAsString(MUIA_FrameTitle);
    }

#ifdef MUIA_FrameVisible
    bool Area::isFrameVisible() const
    {
        return GetValueAsBool(MUIA_FrameVisible);
    }
#endif

    long Area::getHeight() const
    {
        return GetValueAsLong(MUIA_Height);
    }

    long Area::getHorizDisappear() const
    {
        return GetValueAsLong(MUIA_HorizDisappear);
    }

    short Area::getHorizWeight() const
    {
        return GetValueAsLong(MUIA_HorizWeight);
    }

    long Area::getInnerBottom() const
    {
        return GetValueAsLong(MUIA_InnerBottom);
    }

    long Area::getInnerLeft() const
    {
        return GetValueAsLong(MUIA_InnerLeft);
    }

    long Area::getInnerRight() const
    {
        return GetValueAsLong(MUIA_InnerRight);
    }

    long Area::getInnerTop() const
    {
        return GetValueAsLong(MUIA_InnerTop);
    }

#ifdef MUIA_KnowsDisabled
    bool Area::isKnowsDisabled() const
    {
        return GetValueAsBool(MUIA_KnowsDisabled);
    }
#endif

    long Area::getLeftEdge() const
    {
        return GetValueAsLong(MUIA_LeftEdge);
    }

#ifdef MUIA_PointerType
    enum PointerType Area::getPointerType() const
    {
        return (enum PointerType)GetValueAsLong(MUIA_PointerType);
    }
#endif

    bool Area::isPressed() const
    {
        return GetValueAsBool(MUIA_Pressed);
    }

    long Area::getRightEdge() const
    {
        return GetValueAsLong(MUIA_RightEdge);
    }

    bool Area::isSelected() const
    {
        return GetValueAsBool(MUIA_Selected);
    }

    std::string Area::getShortHelp() const
    {
        return GetValueAsString(MUIA_ShortHelp);
    }

    bool Area::isShowMe() const
    {
        return GetValueAsBool(MUIA_ShowMe);
    }

#ifdef MUIA_TextColor
    unsigned long Area::getTextColor() const
    {
        return GetValueAsULong(MUIA_TextColor);
    }
#endif

    long Area::getTimer() const
    {
        return GetValueAsLong(MUIA_Timer);
    }

    long Area::getTopEdge() const
    {
        return GetValueAsLong(MUIA_TopEdge);
    }

    long Area::getVertDisappear() const
    {
        return GetValueAsLong(MUIA_VertDisappear);
    }

    short Area::getVertWeight() const
    {
        return GetValueAsLong(MUIA_VertWeight);
    }

    long Area::getWidth() const
    {
        return GetValueAsLong(MUIA_Width);
    }

    Window *Area::getWindow() const
    {
        return (Window *)GetValueAsPtr(MUIA_Window);
    }

    Object *Area::getWindowObject() const
    {
        return GetValueAsObjectPtr(MUIA_WindowObject);
    }

    Area &Area::setBackground(const enum ImageOrBackground background)
    {
        SetValue(MUIA_Background, (long)background);
        return *this;
    }

    Area &Area::setBackground(const std::string &background)
    {
        SetValue(MUIA_Background, StoreString(MUIA_Background, background));
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

#ifdef MUIA_Floating
    Area &Area::setFloating(const bool floating)
    {
        SetValue(MUIA_Floating, floating);
        return *this;
    }
#endif

    Area &Area::setFont(const enum Font font)
    {
        SetValue(MUIA_Font, (long)font);
        return *this;
    }

    Area &Area::setFrameTitle(const std::string &frameTitle)
    {
        SetValue(MUIA_FrameTitle, StoreString(MUIA_FrameTitle, frameTitle));
        return *this;
    }

    Area &Area::setHorizWeight(const short horizWeight)
    {
        if (horizWeight >= 0)
            SetValue(MUIA_HorizWeight, (long)horizWeight);
        return *this;
    }

#ifdef MUIA_PointerType
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
        SetValue(MUIA_ShortHelp, StoreString(MUIA_ShortHelp, shortHelp));
        return *this;
    }

    Area &Area::setShowMe(const bool showMe)
    {
        SetValue(MUIA_ShowMe, showMe);
        return *this;
    }

    Area &Area::setVertWeight(const short vertWeight)
    {
        if (vertWeight >= 0)
            SetValue(MUIA_VertWeight, (long)vertWeight);
        return *this;
    }

    Area &Area::setWeight(const short weight)
    {
        if (weight >= 0)
            SetValue(MUIA_Weight, (long)weight);
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

    Area &Area::Cleanup()
    {
        DoMethod(muiObject(), MUIM_Cleanup);
        return *this;
    }

    Area &Area::Hide()
    {
        DoMethod(muiObject(), MUIM_Hide);
        return *this;
    }

    Area &Area::Show(struct LongRect *clip)
    {
        DoMethod(muiObject(), MUIM_Show, clip);
        return *this;
    }

#ifdef MUIM_Relayout
    Area &Area::Relayout()
    {
        DoMethod(muiObject(), MUIM_Relayout, 0);
        return *this;
    }
#endif

#ifdef MUIM_Text
    Area &Area::Text(const long left, const long top, const long width, const long height, const std::string &text, const long len,
                     const std::string &preparse, const char ulchar)
    {
        DoMethod(muiObject(), MUIM_Text, left, top, width, height, text.c_str(), len, preparse.empty() ? nullptr : preparse.c_str(),
                 ulchar);
        return *this;
    }
#endif

#ifdef MUIM_TextDim
    Dim Area::TextDim(const std::string &text, const long len, const std::string &preparse, const long flags)
    {
        return Dim(DoMethod(muiObject(), MUIM_TextDim, text.c_str(), len, preparse.empty() ? nullptr : preparse.c_str(), flags));
    }
#endif

    AreaBuilder::AreaBuilder() { }
}