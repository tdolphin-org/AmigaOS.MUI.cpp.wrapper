//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Area.hpp"
#include "Menuitem.hpp"
#include "Menustrip.hpp"

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

    Optional<Menustrip> Area::getContextMenu() const
    {
        Object *obj = GetValueAsObjectPtr(MUIA_ContextMenu);
        if (!obj)
            return { };
        return Menustrip(obj);
    }

    Area &Area::setContextMenu(const Menustrip &contextMenu)
    {
        SetValue(MUIA_ContextMenu, contextMenu.muiObject());
        return *this;
    }

#ifdef MUIA_ContextMenuHook
    Hook *Area::getContextMenuHook() const
    {
        return GetValueAsHookPtr(MUIA_ContextMenuHook);
    }

    Area &Area::setContextMenuHook(const Hook *contextMenuHook)
    {
        SetValue(MUIA_ContextMenuHook, contextMenuHook);
        return *this;
    }
#endif

    Optional<Menuitem> Area::getContextMenuTrigger() const
    {
        Object *obj = GetValueAsObjectPtr(MUIA_ContextMenuTrigger);
        if (!obj)
            return { };
        return Menuitem(obj);
    }

    char Area::getControlChar() const
    {
        return GetValueAsChar(MUIA_ControlChar);
    }

    Area &Area::setControlChar(const char controlChar)
    {
        SetValue(MUIA_ControlChar, (long)controlChar);
        return *this;
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

    Area &Area::setDoubleBuffer(const bool doubleBuffer)
    {
        SetValue(MUIA_DoubleBuffer, doubleBuffer);
        return *this;
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

    Area &Area::setDraggable(const bool draggable)
    {
        SetValue(MUIA_Draggable, draggable);
        return *this;
    }

    bool Area::isDropable() const
    {
        return GetValueAsBool(MUIA_Dropable);
    }

    Area &Area::setDropable(const bool dropable)
    {
        SetValue(MUIA_Dropable, dropable);
        return *this;
    }

#ifdef MUIA_Floating
    bool Area::isFloating() const
    {
        return GetValueAsBool(MUIA_Floating);
    }
#endif

    TextFont *Area::getFont() const
    {
        return GetValueAsTextFontPtr(MUIA_Font);
    }

#ifdef MUIA_FrameDynamic
    bool Area::isFrameDynamic() const
    {
        return GetValueAsBool(MUIA_FrameDynamic);
    }

    Area &Area::setFrameDynamic(const bool frameDynamic)
    {
        SetValue(MUIA_FrameDynamic, frameDynamic);
        return *this;
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

    Area &Area::setFrameVisible(const bool frameVisible)
    {
        SetValue(MUIA_FrameVisible, frameVisible);
        return *this;
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

    Area &Area::setHorizDisappear(const long horizDisappear)
    {
        SetValue(MUIA_HorizDisappear, horizDisappear);
        return *this;
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

    Area &Area::setKnowsDisabled(const bool knowsDisabled)
    {
        SetValue(MUIA_KnowsDisabled, knowsDisabled);
        return *this;
    }
#endif

    long Area::getLeftEdge() const
    {
        return GetValueAsLong(MUIA_LeftEdge);
    }

#ifdef MUIA_PointerType
    enum PointerType Area::getPointerType() const
    {
        return static_cast<enum PointerType>(GetValueAsLong(MUIA_PointerType));
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

    Area &Area::setTextColor(const struct MUI_PenSpec *textColor)
    {
        SetValue(MUIA_TextColor, textColor);
        return *this;
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

    Area &Area::setVertDisappear(const long vertDisappear)
    {
        SetValue(MUIA_VertDisappear, vertDisappear);
        return *this;
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
        return GetValueAsWindowPtr(MUIA_Window);
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

#ifdef MUIM_ContextMenuBuild
    Optional<Menustrip> Area::ContextMenuBuild(const long mx, const long my)
    {
        Object *obj = reinterpret_cast<Object *>(DoMethod(muiObject(), MUIM_ContextMenuBuild, mx, my));
        if (!obj)
            return { };
        return Menustrip(obj);
    }
#endif

#ifdef MUIM_ContextMenuAdd
    unsigned long Area::ContextMenuAdd(const Menustrip &menustrip, const long mx, const long my, long *mxp, long *myp)
    {
        return DoMethod(muiObject(), MUIM_ContextMenuAdd, menustrip.muiObject(), mx, my, mxp, myp);
    }
#endif

#ifdef MUIM_ContextMenuChoice
    unsigned long Area::ContextMenuChoice(const Menuitem &item)
    {
        return DoMethod(muiObject(), MUIM_ContextMenuChoice, item.muiObject());
    }
#endif

#ifdef MUIM_CreateBubble
    APTR Area::CreateBubble(const long x, const long y, const char *txt, const unsigned long flags)
    {
        return reinterpret_cast<APTR>(DoMethod(muiObject(), MUIM_CreateBubble, x, y, txt, flags));
    }
#endif

#ifdef MUIM_CreateDragImage
    struct MUI_DragImage *Area::CreateDragImage(const long touchx, const long touchy, const unsigned long flags)
    {
        return reinterpret_cast<struct MUI_DragImage *>(DoMethod(muiObject(), MUIM_CreateDragImage, touchx, touchy, flags));
    }
#endif

#ifdef MUIM_CreateShortHelp
    char *Area::CreateShortHelp(const long mx, const long my)
    {
        return reinterpret_cast<char *>(DoMethod(muiObject(), MUIM_CreateShortHelp, mx, my));
    }
#endif

#ifdef MUIM_DeleteBubble
    Area &Area::DeleteBubble(APTR bubble)
    {
        DoMethod(muiObject(), MUIM_DeleteBubble, bubble);
        return *this;
    }
#endif

#ifdef MUIM_DeleteDragImage
    Area &Area::DeleteDragImage(struct MUI_DragImage *di)
    {
        DoMethod(muiObject(), MUIM_DeleteDragImage, di);
        return *this;
    }
#endif

#ifdef MUIM_DeleteShortHelp
    Area &Area::DeleteShortHelp(char *help)
    {
        DoMethod(muiObject(), MUIM_DeleteShortHelp, help);
        return *this;
    }
#endif

#ifdef MUIM_DoDrag
    unsigned long Area::DoDrag(const long touchx, const long touchy, const unsigned long flags)
    {
        return DoMethod(muiObject(), MUIM_DoDrag, touchx, touchy, flags);
    }
#endif

#ifdef MUIM_DragQuery
    unsigned long Area::DragQuery(const Object *obj)
    {
        return DoMethod(muiObject(), MUIM_DragQuery, obj);
    }

    unsigned long Area::DragQuery(const Root &obj)
    {
        return DragQuery(obj.muiObject());
    }
#endif

#ifdef MUIM_DragBegin
    unsigned long Area::DragBegin(const Object *obj)
    {
        return DoMethod(muiObject(), MUIM_DragBegin, obj);
    }

    unsigned long Area::DragBegin(const Root &obj)
    {
        return DragBegin(obj.muiObject());
    }
#endif

#ifdef MUIM_DragDrop
    unsigned long Area::DragDrop(const Object *obj, const long x, const long y, const unsigned long qualifier)
    {
        return DoMethod(muiObject(), MUIM_DragDrop, obj, x, y, qualifier);
    }

    unsigned long Area::DragDrop(const Root &obj, const long x, const long y, const unsigned long qualifier)
    {
        return DragDrop(obj.muiObject(), x, y, qualifier);
    }
#endif

#ifdef MUIM_DragFinish
    unsigned long Area::DragFinish(const Object *obj, const long dropfollows)
    {
        return DoMethod(muiObject(), MUIM_DragFinish, obj, dropfollows);
    }

    unsigned long Area::DragFinish(const Root &obj, const long dropfollows)
    {
        return DragFinish(obj.muiObject(), dropfollows);
    }
#endif

#ifdef MUIM_DragReport
    unsigned long Area::DragReport(const Object *obj, const long x, const long y, const long update, const unsigned long qualifier)
    {
        return DoMethod(muiObject(), MUIM_DragReport, obj, x, y, update, qualifier);
    }

    unsigned long Area::DragReport(const Root &obj, const long x, const long y, const long update, const unsigned long qualifier)
    {
        return DragReport(obj.muiObject(), x, y, update, qualifier);
    }
#endif

#ifdef MUIM_DrawBackground
    Area &Area::DrawBackground(const long left, const long top, const long width, const long height, const long xoffset, const long yoffset,
                               const long flags)
    {
        DoMethod(muiObject(), MUIM_DrawBackground, left, top, width, height, xoffset, yoffset, flags);
        return *this;
    }
#endif

#ifdef MUIM_DrawBackgroundParent
    Area &Area::DrawBackgroundParent(const long left, const long top, const long width, const long height, const long brightness,
                                     const long xoffset, const long yoffset, const long flags)
    {
        DoMethod(muiObject(), MUIM_DrawBackgroundParent, left, top, width, height, brightness, xoffset, yoffset, flags);
        return *this;
    }
#endif

#ifdef MUIM_Relayout
    Area &Area::Relayout()
    {
        DoMethod(muiObject(), MUIM_Relayout, 0);
        return *this;
    }
#endif

#ifdef MUIM_WhichPointerType
    enum PointerType Area::WhichPointerType(const long mx, const long my)
    {
        return static_cast<enum PointerType>(DoMethod(muiObject(), MUIM_WhichPointerType, mx, my));
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