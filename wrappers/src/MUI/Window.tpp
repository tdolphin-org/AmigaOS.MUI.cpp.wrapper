//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_WINDOW_TPP_INCLUDE
#error "Window.tpp should only be included by Window.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagActiveObject(const enum Window_ActiveObject activeObject)
    {
        this->PushTag(MUIA_Window_ActiveObject, (long)activeObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagActivate(const bool activate)
    {
        this->PushTag(MUIA_Window_Activate, activate);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltHeight(const long altHeight)
    {
        this->PushTag(MUIA_Window_AltHeight, altHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltLeftEdge(const long altLeftEdge)
    {
        this->PushTag(MUIA_Window_AltLeftEdge, altLeftEdge);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltTopEdge(const long altTopEdge)
    {
        this->PushTag(MUIA_Window_AltTopEdge, altTopEdge);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltWidth(const long altWidth)
    {
        this->PushTag(MUIA_Window_AltWidth, altWidth);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAppWindow(const bool appWindow)
    {
        this->PushTag(MUIA_Window_AppWindow, appWindow);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagBackdrop(const bool backdrop)
    {
        this->PushTag(MUIA_Window_Backdrop, backdrop);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagBorderless(const bool borderless)
    {
        this->PushTag(MUIA_Window_Borderless, borderless);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagCloseGadget(const bool closeGadget)
    {
        this->PushTag(MUIA_Window_CloseGadget, closeGadget);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagDefaultObject(const Object *defaultObject)
    {
        this->PushTag(MUIA_Window_DefaultObject, defaultObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagDefaultObject(const Root &defaultObject)
    {
        this->PushTag(MUIA_Window_DefaultObject, defaultObject.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagDepthGadget(const bool depthGadget)
    {
        this->PushTag(MUIA_Window_DepthGadget, depthGadget);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagDragBar(const bool dragBar)
    {
        this->PushTag(MUIA_Window_DragBar, dragBar);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagHeight(const long height)
    {
        this->PushTag(MUIA_Window_Height, height);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagID(const AOS::Identifier &id)
    {
        this->PushTag(MUIA_Window_ID, id.value());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagIsSubWindow(const bool subWindow)
    {
        this->PushTag(MUIA_Window_IsSubWindow, subWindow);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagLeftEdge(const long leftEdge)
    {
        this->PushTag(MUIA_Window_LeftEdge, leftEdge);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagMenustrip(const Menustrip &menustrip)
    {
        this->PushTag(MUIA_Window_Menustrip, menustrip.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagMenustrip(const NewMenu &newmenu, const unsigned long flags)
    {
        this->PushTag(MUIA_Window_Menustrip, MUI_MakeObject(MUIO_MenustripNM, (unsigned long)&newmenu, flags));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagNoMenus(const bool noMenus)
    {
        this->PushTag(MUIA_Window_NoMenus, noMenus);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagPublicScreen(const char *publicScreen)
    {
        this->PushTag(MUIA_Window_PublicScreen, publicScreen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagPublicScreen(const std::string &publicScreen)
    {
        this->PushTag(MUIA_Window_PublicScreen, publicScreen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRefWindow(const Object *refWindow)
    {
        this->PushTag(MUIA_Window_RefWindow, refWindow);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRefWindow(const Window &refWindow)
    {
        this->PushTag(MUIA_Window_RefWindow, refWindow.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRootObject(const Object *pRootObject)
    {
        hasRootObject = pRootObject != nullptr;
        this->PushTag(MUIA_Window_RootObject, pRootObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRootObject(const Root &root)
    {
        hasRootObject = true;
        this->PushTag(MUIA_Window_RootObject, root.muiObject());
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagScreen(const void *screen)
    {
        this->PushTag(MUIA_Window_Screen, screen);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagScreenTitle(const char *screenTitle)
    {
        this->PushTag(MUIA_Window_ScreenTitle, screenTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagScreenTitle(const std::string &screenTitle)
    {
        this->PushTag(MUIA_Window_ScreenTitle, screenTitle);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagSizeGadget(const bool sizeGadget)
    {
        this->PushTag(MUIA_Window_SizeGadget, sizeGadget);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagSizeRight(const bool sizeRight)
    {
        this->PushTag(MUIA_Window_SizeRight, sizeRight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Window_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_Window_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagTopEdge(const long topEdge)
    {
        this->PushTag(MUIA_Window_TopEdge, topEdge);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagUseBottomBorderScroller(const bool useBottomBorderScroller)
    {
        this->PushTag(MUIA_Window_UseBottomBorderScroller, useBottomBorderScroller);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagUseLeftBorderScroller(const bool useLeftBorderScroller)
    {
        this->PushTag(MUIA_Window_UseLeftBorderScroller, useLeftBorderScroller);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagUseRightBorderScroller(const bool useRightBorderScroller)
    {
        this->PushTag(MUIA_Window_UseRightBorderScroller, useRightBorderScroller);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagWidth(const long width)
    {
        this->PushTag(MUIA_Window_Width, width);
        return (T &)*this;
    }

#ifdef MUIA_Window_DisableKeys
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagDisableKeys(const unsigned long disableKeys)
    {
        this->PushTag(MUIA_Window_DisableKeys, disableKeys);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Window_Opacity
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagOpacity(const long opacity)
    {
        this->PushTag(MUIA_Window_Opacity, opacity);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Window_HasAlpha
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagHasAlpha(const bool hasAlpha)
    {
        this->PushTag(MUIA_Window_HasAlpha, hasAlpha);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Window_PanelWindow
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagPanelWindow(const bool panelWindow)
    {
        this->PushTag(MUIA_Window_PanelWindow, panelWindow);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Window_TabletMessages
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagTabletMessages(const bool tabletMessages)
    {
        this->PushTag(MUIA_Window_TabletMessages, tabletMessages);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Window_VisibleOnMaximize
    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagVisibleOnMaximize(const bool visibleOnMaximize)
    {
        this->PushTag(MUIA_Window_VisibleOnMaximize, visibleOnMaximize);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline bool WindowBuilderTemplate<T, U>::Validate() const
    {
        auto result = NotifyBuilderTemplate<T, U>::Validate();

        // The root object is mandatory during window creation and trying to create a window without a root object will fail.
        // So check if there is tag for RootObject (not null).
        if (!hasRootObject)
        {
            std::cerr << __PRETTY_FUNCTION__ << ", missing RootObject for Window!" << std::endl;
            result = false;
        }

        return result;
    }
}
