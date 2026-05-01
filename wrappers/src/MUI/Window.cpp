//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
//

#include "Window.hpp"

#include <libraries/gadtools.h>
#include <libraries/iffparse.h>
#include <proto/alib.h>
#include <proto/intuition.h>

#undef ScreenToBack
#undef ScreenToFront

namespace MUI
{
    const std::string Window::className = MUIC_Window;

    bool Window::isActivate() const
    {
        return GetValueAsBool(MUIA_Window_Activate);
    }

    bool Window::isOpen() const
    {
        return GetValueAsBool(MUIA_Window_Open);
    }

    bool Window::isCloseRequest() const
    {
        return GetValueAsBool(MUIA_Window_CloseRequest);
    }

    bool Window::isSubWindow() const
    {
        return GetValueAsBool(MUIA_Window_IsSubWindow);
    }

    bool Window::isNoMenus() const
    {
        return GetValueAsBool(MUIA_Window_NoMenus);
    }

    bool Window::isSleep() const
    {
        return GetValueAsBool(MUIA_Window_Sleep);
    }

    bool Window::isUseBottomBorderScroller() const
    {
        return GetValueAsBool(MUIA_Window_UseBottomBorderScroller);
    }

    bool Window::isUseLeftBorderScroller() const
    {
        return GetValueAsBool(MUIA_Window_UseLeftBorderScroller);
    }

    bool Window::isUseRightBorderScroller() const
    {
        return GetValueAsBool(MUIA_Window_UseRightBorderScroller);
    }

#ifdef MUIA_Window_HasAlpha
    bool Window::isHasAlpha() const
    {
        return GetValueAsBool(MUIA_Window_HasAlpha);
    }
#endif

#ifdef MUIA_Window_TabletMessages
    bool Window::isTabletMessages() const
    {
        return GetValueAsBool(MUIA_Window_TabletMessages);
    }
#endif

#ifdef MUIA_Window_VisibleOnMaximize
    bool Window::isVisibleOnMaximize() const
    {
        return GetValueAsBool(MUIA_Window_VisibleOnMaximize);
    }
#endif

    Object *Window::getActiveObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_ActiveObject);
    }

    long Window::getAltHeight() const
    {
        return GetValueAsLong(MUIA_Window_AltHeight);
    }

    long Window::getAltLeftEdge() const
    {
        return GetValueAsLong(MUIA_Window_AltLeftEdge);
    }

    long Window::getAltTopEdge() const
    {
        return GetValueAsLong(MUIA_Window_AltTopEdge);
    }

    long Window::getAltWidth() const
    {
        return GetValueAsLong(MUIA_Window_AltWidth);
    }

    Object *Window::getDefaultObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_DefaultObject);
    }

#ifdef MUIA_Window_DisableKeys
    unsigned long Window::getDisableKeys() const
    {
        return GetValueAsULong(MUIA_Window_DisableKeys);
    }
#endif

#ifdef MUIA_Window_DrawInfo
    const ::DrawInfo *Window::getDrawInfo() const
    {
        return GetValueAsDrawInfoPtr(MUIA_Window_DrawInfo);
    }
#endif

    long Window::getHeight() const
    {
        return GetValueAsLong(MUIA_Window_Height);
    }

    AOS::Identifier Window::getID() const
    {
        return AOS::Identifier(GetValueAsULong(MUIA_Window_ID));
    }

    ::InputEvent *Window::getInputEvent() const
    {
        return GetValueAsInputEventPtr(MUIA_Window_InputEvent);
    }

    long Window::getLeftEdge() const
    {
        return GetValueAsLong(MUIA_Window_LeftEdge);
    }

    unsigned long Window::getMenuAction() const
    {
        return GetValueAsULong(MUIA_Window_MenuAction);
    }

    Object *Window::getMenustripObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_Menustrip);
    }

    Menustrip Window::getMenustrip() const
    {
        return Menustrip(GetValueAsObjectPtr(MUIA_Window_Menustrip));
    }

    Object *Window::getMouseObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_MouseObject);
    }

#ifdef MUIA_Window_Opacity
    long Window::getOpacity() const
    {
        return GetValueAsLong(MUIA_Window_Opacity);
    }
#endif

    std::string Window::getPublicScreen() const
    {
        return GetValueAsString(MUIA_Window_PublicScreen);
    }

    ::Screen *Window::getScreen() const
    {
        return GetValueAsScreenPtr(MUIA_Window_Screen);
    }

    Object *Window::getRootObject() const
    {
        return GetValueAsObjectPtr(MUIA_Window_RootObject);
    }

    std::string Window::getScreenTitle() const
    {
        return GetValueAsString(MUIA_Window_ScreenTitle);
    }

    std::string Window::getTitle() const
    {
        return GetValueAsString(MUIA_Window_Title);
    }

    long Window::getTopEdge() const
    {
        return GetValueAsLong(MUIA_Window_TopEdge);
    }

    long Window::getWidth() const
    {
        return GetValueAsLong(MUIA_Window_Width);
    }

    ::Window *Window::getWindow() const
    {
        return GetValueAsWindowPtr(MUIA_Window_Window);
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setAltHeight(const long altHeight)
    {
        SetValue(MUIA_Window_AltHeight, altHeight);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setAltLeftEdge(const long altLeftEdge)
    {
        SetValue(MUIA_Window_AltLeftEdge, altLeftEdge);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setAltTopEdge(const long altTopEdge)
    {
        SetValue(MUIA_Window_AltTopEdge, altTopEdge);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setAltWidth(const long altWidth)
    {
        SetValue(MUIA_Window_AltWidth, altWidth);
        return *this;
    }
#endif

    Window &Window::setActivate(const bool activate)
    {
        SetValue(MUIA_Window_Activate, activate);
        return *this;
    }

    Window &Window::setActiveObject(const enum Window_ActiveObject activeObject)
    {
        SetValue(MUIA_Window_ActiveObject, (long)activeObject);
        return *this;
    }

    Window &Window::setActiveObject(const Object *activeObject)
    {
        SetValue(MUIA_Window_ActiveObject, activeObject);
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setCloseRequest(const bool closeRequest)
    {
        SetValue(MUIA_Window_CloseRequest, closeRequest);
        return *this;
    }
#endif

    Window &Window::setDefaultObject(const Object *defaultObject)
    {
        SetValue(MUIA_Window_DefaultObject, defaultObject);
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setHeight(const long height)
    {
        SetValue(MUIA_Window_Height, height);
        return *this;
    }
#endif

#ifdef MUIA_Window_DisableKeys
    Window &Window::setDisableKeys(const unsigned long disableKeys)
    {
        SetValue(MUIA_Window_DisableKeys, disableKeys);
        return *this;
    }
#endif

    Window &Window::setID(const AOS::Identifier &id)
    {
        SetValue(MUIA_Window_ID, id.value());
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setLeftEdge(const long leftEdge)
    {
        SetValue(MUIA_Window_LeftEdge, leftEdge);
        return *this;
    }
#endif

    Window &Window::setSubWindow(const bool subWindow)
    {
        SetValue(MUIA_Window_IsSubWindow, subWindow);
        return *this;
    }

    Window &Window::setMenuAction(const unsigned long menuAction)
    {
        SetValue(MUIA_Window_MenuAction, menuAction);
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setMenustrip(const Menustrip &menustrip)
    {
        SetValue(MUIA_Window_Menustrip, menustrip.muiObject());
        return *this;
    }
#endif

    Window &Window::setNoMenus(const bool noMenus)
    {
        SetValue(MUIA_Window_NoMenus, noMenus);
        return *this;
    }

#ifdef MUIA_Window_Opacity
    Window &Window::setOpacity(const long opacity)
    {
        SetValue(MUIA_Window_Opacity, opacity);
        return *this;
    }
#endif

    Window &Window::setPublicScreen(const std::string &publicScreen)
    {
        SetValue(MUIA_Window_PublicScreen, publicScreen);
        return *this;
    }

    Window &Window::setRefWindow(const Object *refWindow)
    {
        SetValue(MUIA_Window_RefWindow, refWindow);
        return *this;
    }

    Window &Window::setRefWindow(const Window &refWindow)
    {
        SetValue(MUIA_Window_RefWindow, refWindow.muiObject());
        return *this;
    }

    Window &Window::setRootObject(const Object *rootObject)
    {
        SetValue(MUIA_Window_RootObject, rootObject);
        return *this;
    }

    Window &Window::setScreen(::Screen *screen)
    {
        SetValue(MUIA_Window_Screen, screen);
        return *this;
    }

    Window &Window::setScreenTitle(const std::string &screenTitle)
    {
        SetValue(MUIA_Window_ScreenTitle, screenTitle);
        return *this;
    }

    Window &Window::setSleep(const bool sleep)
    {
        SetValue(MUIA_Window_Sleep, sleep);
        return *this;
    }

    Window &Window::setTitle(const std::string &title)
    {
        SetValue(MUIA_Window_Title, title);
        return *this;
    }

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setTopEdge(const long topEdge)
    {
        SetValue(MUIA_Window_TopEdge, topEdge);
        return *this;
    }
#endif

    Window &Window::setUseBottomBorderScroller(const bool useBottomBorderScroller)
    {
        SetValue(MUIA_Window_UseBottomBorderScroller, useBottomBorderScroller);
        return *this;
    }

    Window &Window::setUseLeftBorderScroller(const bool useLeftBorderScroller)
    {
        SetValue(MUIA_Window_UseLeftBorderScroller, useLeftBorderScroller);
        return *this;
    }

    Window &Window::setUseRightBorderScroller(const bool useRightBorderScroller)
    {
        SetValue(MUIA_Window_UseRightBorderScroller, useRightBorderScroller);
        return *this;
    }

#ifdef MUIA_Window_HasAlpha
    Window &Window::setHasAlpha(const bool hasAlpha)
    {
        SetValue(MUIA_Window_HasAlpha, hasAlpha);
        return *this;
    }
#endif

#ifdef MUIA_Window_VisibleOnMaximize
    Window &Window::setVisibleOnMaximize(const bool visibleOnMaximize)
    {
        SetValue(MUIA_Window_VisibleOnMaximize, visibleOnMaximize);
        return *this;
    }
#endif

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
    Window &Window::setWidth(const long width)
    {
        SetValue(MUIA_Window_Width, width);
        return *this;
    }
#endif

    Window &Window::AddEventHandler(::MUI_EventHandlerNode *eventHandlerNode)
    {
        DoMethod(muiObject(), MUIM_Window_AddEventHandler, eventHandlerNode);
        return *this;
    }

#ifdef MUIM_Window_Cleanup
    Window &Window::Cleanup()
    {
        DoMethod(muiObject(), MUIM_Window_Cleanup);
        return *this;
    }
#endif

    Window &Window::Open()
    {
        SetValue(MUIA_Window_Open, true);
        return *this;
    }

    Window &Window::Close()
    {
        SetValue(MUIA_Window_Open, false);
        return *this;
    }

#ifdef MUIM_Window_Setup
    Window &Window::Setup()
    {
        DoMethod(muiObject(), MUIM_Window_Setup);
        return *this;
    }
#endif

    Window &Window::ScreenToBack()
    {
        DoMethod(muiObject(), MUIM_Window_ScreenToBack);
        return *this;
    }

    Window &Window::ScreenToFront()
    {
        DoMethod(muiObject(), MUIM_Window_ScreenToFront);
        return *this;
    }

    Window &Window::RemEventHandler(::MUI_EventHandlerNode *eventHandlerNode)
    {
        DoMethod(muiObject(), MUIM_Window_RemEventHandler, eventHandlerNode);
        return *this;
    }

    Window &Window::Snapshot(const long flags)
    {
        DoMethod(muiObject(), MUIM_Window_Snapshot, flags);
        return *this;
    }

    Window &Window::ToBack()
    {
        DoMethod(muiObject(), MUIM_Window_ToBack);
        return *this;
    }

    Window &Window::ToFront()
    {
        DoMethod(muiObject(), MUIM_Window_ToFront);
        return *this;
    }

    WindowBuilder::WindowBuilder() { }

    WindowScope::WindowScope(Window &window)
      : mWindow(window)
    {
        if (!mWindow.Open().isOpen())
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + ", failed to open window!";
            throw std::runtime_error(error);
        }
    }

    WindowScope::~WindowScope()
    {
        mWindow.Close();
    }
}
