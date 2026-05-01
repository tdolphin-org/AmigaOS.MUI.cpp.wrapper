//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Notify.hpp"

#include "AOS/Identifier.hpp"
#include "Core/MUICompileConfig.hpp"
#include "Menustrip.hpp"
#include "ValueTypes/Window/ActiveObject.hpp"

#include <proto/muimaster.h>

struct DrawInfo;
struct InputEvent;
struct Screen;
struct MUI_EventHandlerNode;

#undef Open
#undef Close
#undef ScreenToBack
#undef ScreenToFront

namespace MUI
{
    struct NewMenu;

    /// @brief Wrapper for MUIC_Window — represents an application window in the MUI object tree.
    ///
    /// Objects of Window class are used to generate windows and supply a place where MUI gadgets
    /// feel well. Window resizing is handled fully automatically. Windows are children of an
    /// application and cannot be used without a parent application object. Creating a window object
    /// does not open it instantly — opening and closing is controlled via MUIA_Window_Open.
    /// Gadgets in a window can be accessed whether the window is open or closed.
    class Window : public Notify
    {
      public:
        explicit Window(Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Window_Activate ]
        /// Returns true when the window is currently active.
        bool isActivate() const;
        /// @brief [ @b MUIA_Window_Open ]
        bool isOpen() const;
        /// @brief [ @b MUIA_Window_CloseRequest ]
        /// Returns true after the user pressed the window close gadget.
        bool isCloseRequest() const;
        /// @brief [ @b MUIA_Window_IsSubWindow ]
        /// Returns true when the window must be disposed manually instead of by the application.
        bool isSubWindow() const;
        /// @brief [ @b MUIA_Window_NoMenus ]
        /// Returns true when the window menu strip is temporarily disabled.
        bool isNoMenus() const;
        /// @brief [ @b MUIA_Window_Sleep ]
        /// Returns true when the window is currently sleeping.
        bool isSleep() const;
        /// @brief [ @b MUIA_Window_UseBottomBorderScroller ]
        /// Returns true when the window provides a bottom border scroller.
        bool isUseBottomBorderScroller() const;
        /// @brief [ @b MUIA_Window_UseLeftBorderScroller ]
        /// Returns true when the window provides a left border scroller.
        bool isUseLeftBorderScroller() const;
        /// @brief [ @b MUIA_Window_UseRightBorderScroller ]
        /// Returns true when the window provides a right border scroller.
        bool isUseRightBorderScroller() const;
#ifdef MUIA_Window_HasAlpha
        /// @brief [ @b MUIA_Window_HasAlpha ]
        /// Returns true when the window supports per-pixel alpha blending.
        bool isHasAlpha() const;
#endif
#ifdef MUIA_Window_TabletMessages
        /// @brief [ @b MUIA_Window_TabletMessages ]
        /// Returns true when the window receives tablet input messages.
        bool isTabletMessages() const;
#endif
#ifdef MUIA_Window_VisibleOnMaximize
        /// @brief [ @b MUIA_Window_VisibleOnMaximize ]
        /// Returns true when the window remains visible when its screen is maximized.
        bool isVisibleOnMaximize() const;
#endif
        /// @brief [ @b MUIA_Window_ActiveObject ]
        /// Returns the object currently active in the window cycle chain.
        Object *getActiveObject() const;
        /// @brief [ @b MUIA_Window_AltHeight ]
        /// Returns the configured alternate zoomed height.
        long getAltHeight() const;
        /// @brief [ @b MUIA_Window_AltLeftEdge ]
        /// Returns the configured alternate zoomed left edge.
        long getAltLeftEdge() const;
        /// @brief [ @b MUIA_Window_AltTopEdge ]
        /// Returns the configured alternate zoomed top edge.
        long getAltTopEdge() const;
        /// @brief [ @b MUIA_Window_AltWidth ]
        /// Returns the configured alternate zoomed width.
        long getAltWidth() const;
        /// @brief [ @b MUIA_Window_DefaultObject ]
        /// Returns the object that receives keyboard input while no other object is active.
        Object *getDefaultObject() const;
#ifdef MUIA_Window_DisableKeys
        /// @brief [ @b MUIA_Window_DisableKeys ]
        /// Returns the mask of internal keys disabled for this window.
        unsigned long getDisableKeys() const;
#endif
#ifdef MUIA_Window_DrawInfo
        /// @brief [ @b MUIA_Window_DrawInfo ]
        /// Returns read-only DrawInfo valid between window setup and cleanup.
        const ::DrawInfo *getDrawInfo() const;
#endif
        /// @brief [ @b MUIA_Window_Height ]
        /// Returns the configured window height.
        long getHeight() const;
        /// @brief [ @b MUIA_Window_ID ]
        AOS::Identifier getID() const;
        /// @brief [ @b MUIA_Window_InputEvent ]
        /// Returns the last input event translated for window notifications.
        ::InputEvent *getInputEvent() const;
        /// @brief [ @b MUIA_Window_LeftEdge ]
        /// Returns the configured left window edge.
        long getLeftEdge() const;
        /// @brief [ @b MUIA_Window_MenuAction ]
        /// Returns the UserData value of the selected menu item.
        unsigned long getMenuAction() const;
        /// @brief [ @b MUIA_Window_Menustrip ]
        /// Returns raw menustrip object pointer.
        Object *getMenustripObject() const;
        /// @brief [ @b MUIA_Window_Menustrip ]
        /// Returns menustrip wrapper owned by this window.
        Menustrip getMenustrip() const;
        /// @brief [ @b MUIA_Window_MouseObject ]
        /// Returns the deepest nested object currently below the mouse pointer.
        Object *getMouseObject() const;
#ifdef MUIA_Window_Opacity
        /// @brief [ @b MUIA_Window_Opacity ]
        /// Returns the configured window opacity.
        long getOpacity() const;
#endif
        /// @brief [ @b MUIA_Window_PublicScreen ]
        /// Returns the public screen name forced for this window.
        std::string getPublicScreen() const;
        /// @brief [ @b MUIA_Window_Screen ]
        /// Returns the parent screen pointer or null while the window is closed.
        ::Screen *getScreen() const;
        /// @brief [ @b MUIA_Window_RootObject ]
        /// @return a pointer to a MUI object, the contents of window,
        /// The root object is treated as child of a window and will be disposed when the window is disposed. Window can only have one
        /// child.
        Object *getRootObject() const;
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        std::string getScreenTitle() const;
        /// @brief [ @b MUIA_Window_Title ]
        /// Returns the window title.
        std::string getTitle() const;
        /// @brief [ @b MUIA_Window_TopEdge ]
        /// Returns the configured top window edge.
        long getTopEdge() const;
        /// @brief [ @b MUIA_Window_Width ]
        /// Returns the configured window width.
        long getWidth() const;
        /// @brief [ @b MUIA_Window_Window ]
        /// Returns the underlying Intuition window pointer when the window is open.
        ::Window *getWindow() const;

#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_AltHeight ]
        /// Sets the alternate zoomed height.
        Window &setAltHeight(const long altHeight);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_AltLeftEdge ]
        /// Sets the alternate zoomed left edge.
        Window &setAltLeftEdge(const long altLeftEdge);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_AltTopEdge ]
        /// Sets the alternate zoomed top edge.
        Window &setAltTopEdge(const long altTopEdge);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_AltWidth ]
        /// Sets the alternate zoomed width.
        Window &setAltWidth(const long altWidth);
#endif
        /// @brief [ @b MUIA_Window_Activate ]
        /// Setting this to true activates the window. Setting false has no effect.
        Window &setActivate(const bool activate);
        /// @brief [ @b MUIA_Window_ActiveObject ]
        /// Sets the active object in the window as if the user activated it with the tab key.
        Window &setActiveObject(const enum Window_ActiveObject activeObject);
        /// @brief [ @b MUIA_Window_ActiveObject ]
        /// Sets the active object in the window as if the user activated it with the tab key.
        Window &setActiveObject(const Object *activeObject);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_CloseRequest ]
        /// Sets or clears the close request state.
        Window &setCloseRequest(const bool closeRequest);
#endif
        /// @brief [ @b MUIA_Window_DefaultObject ]
        /// Sets which object receives keyboard input while no other object is active.
        Window &setDefaultObject(const Object *defaultObject);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_Height ]
        /// Sets the window height.
        Window &setHeight(const long height);
#endif
#ifdef MUIA_Window_DisableKeys
        /// @brief [ @b MUIA_Window_DisableKeys ]
        /// Disables internal handling of selected predefined keys.
        Window &setDisableKeys(const unsigned long disableKeys);
#endif
        /// @brief [ @b MUIA_Window_ID ]
        Window &setID(const AOS::Identifier &id);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_LeftEdge ]
        /// Sets the left edge of the window.
        Window &setLeftEdge(const long leftEdge);
#endif
        /// @brief [ @b MUIA_Window_IsSubWindow ]
        /// Controls whether the application disposes the window automatically.
        Window &setSubWindow(const bool subWindow);
        /// @brief [ @b MUIA_Window_MenuAction ]
        /// Sets the menu action value broadcast for menu item selection.
        Window &setMenuAction(const unsigned long menuAction);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_Menustrip ]
        /// Sets a menustrip object for this window.
        Window &setMenustrip(const Menustrip &menustrip);
#endif
        /// @brief [ @b MUIA_Window_NoMenus ]
        /// Temporarily enables or disables the window menu strip.
        Window &setNoMenus(const bool noMenus);
#ifdef MUIA_Window_Opacity
        /// @brief [ @b MUIA_Window_Opacity ]
        /// Sets the window opacity.
        Window &setOpacity(const long opacity);
#endif
        /// @brief [ @b MUIA_Window_PublicScreen ]
        /// Forces the window to open on the named public screen.
        Window &setPublicScreen(const std::string &publicScreen);
        /// @brief [ @b MUIA_Window_RefWindow ]
        /// Positions the window relative to another window.
        Window &setRefWindow(const Object *refWindow);
        /// @brief [ @b MUIA_Window_RefWindow ]
        /// Positions the window relative to another window wrapper.
        Window &setRefWindow(const Window &refWindow);
        /// @brief [ @b MUIA_Window_RootObject ]
        Window &setRootObject(const Object *rootObject);
        /// @brief [ @b MUIA_Window_Screen ]
        /// Forces the window to open on the specified screen.
        Window &setScreen(::Screen *screen);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        Window &setScreenTitle(const std::string &screenTitle);
        /// @brief [ @b MUIA_Window_Sleep ]
        /// Puts the window to sleep or wakes it up.
        Window &setSleep(const bool sleep);
        /// @brief [ @b MUIA_Window_Title ]
        /// Sets the window title.
        Window &setTitle(const std::string &title);
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_TopEdge ]
        /// Sets the top edge of the window.
        Window &setTopEdge(const long topEdge);
#endif
        /// @brief [ @b MUIA_Window_UseBottomBorderScroller ]
        /// Enables or disables the bottom border scroller for child gadgets that use it.
        Window &setUseBottomBorderScroller(const bool useBottomBorderScroller);
        /// @brief [ @b MUIA_Window_UseLeftBorderScroller ]
        /// Enables or disables the left border scroller for child gadgets that use it.
        Window &setUseLeftBorderScroller(const bool useLeftBorderScroller);
        /// @brief [ @b MUIA_Window_UseRightBorderScroller ]
        /// Enables or disables the right border scroller for child gadgets that use it.
        Window &setUseRightBorderScroller(const bool useRightBorderScroller);
#ifdef MUIA_Window_HasAlpha
        /// @brief [ @b MUIA_Window_HasAlpha ]
        /// Enables or disables per-pixel alpha blending for this window.
        Window &setHasAlpha(const bool hasAlpha);
#endif
#ifdef MUIA_Window_VisibleOnMaximize
        /// @brief [ @b MUIA_Window_VisibleOnMaximize ]
        /// Controls whether the window remains visible when its screen is maximized.
        Window &setVisibleOnMaximize(const bool visibleOnMaximize);
#endif
#if defined(AOS_MUI_VERSION_5) || defined(MOS_MUI_VERSION_5)
        /// @brief [ @b MUIA_Window_Width ]
        /// Sets the window width.
        Window &setWidth(const long width);
#endif

        // methods, some returns object reference

        /// @brief [ @b MUIM_Window_AddEventHandler ]
        /// Adds an initialized event handler node to the window event queue.
        Window &AddEventHandler(::MUI_EventHandlerNode *eventHandlerNode);
#ifdef MUIM_Window_Cleanup
        /// @brief [ @b MUIM_Window_Cleanup ]
        /// Cleans up resources initialized during window setup.
        Window &Cleanup();
#endif
        /// @brief [ @b MUIA_Window_Open, @b TRUE ]
        Window &Open();
        /// @brief [ @b MUIA_Window_Open, @b FALSE ]
        Window &Close();
#ifdef MUIM_Window_Setup
        /// @brief [ @b MUIM_Window_Setup ]
        /// Performs window specific setup before layout and opening.
        Window &Setup();
#endif
        /// @brief [ @b MUIM_Window_ScreenToBack ]
        /// Puts the window's screen to back when the window is open.
        Window &ScreenToBack();
        /// @brief [ @b MUIM_Window_ScreenToFront ]
        /// Puts the window's screen to front when the window is open.
        Window &ScreenToFront();
        /// @brief [ @b MUIM_Window_RemEventHandler ]
        /// Removes a previously added event handler node from the window event queue.
        Window &RemEventHandler(::MUI_EventHandlerNode *eventHandlerNode);
        /// @brief [ @b MUIM_Window_Snapshot ]
        /// Snapshots or unsnapshots the remembered window position and size.
        Window &Snapshot(const long flags);
        /// @brief [ @b MUIM_Window_ToBack ]
        /// Puts the window to back.
        Window &ToBack();
        /// @brief [ @b MUIM_Window_ToFront ]
        Window &ToFront();
    };

    /// @brief Builder template for MUIC_Window.
    template <typename T, typename U> class WindowBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
        bool hasRootObject { false };

      public:
        WindowBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Window)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Window_ActiveObject ] Sets the active object using a predefined value (None/Next/Prev or MUI5 directional).
        T &tagActiveObject(const enum Window_ActiveObject activeObject);
        /// @brief [ @b MUIA_Window_Activate ]
        T &tagActivate(const bool activate);
        /// @brief [ @b MUIA_Window_AltHeight ]
        T &tagAltHeight(const long altHeight);
        /// @brief [ @b MUIA_Window_AltLeftEdge ]
        T &tagAltLeftEdge(const long altLeftEdge);
        /// @brief [ @b MUIA_Window_AltTopEdge ]
        T &tagAltTopEdge(const long altTopEdge);
        /// @brief [ @b MUIA_Window_AltWidth ]
        T &tagAltWidth(const long altWidth);
        /// @brief [ @b MUIA_Window_AppWindow ]
        T &tagAppWindow(const bool appWindow);
        /// @brief [ @b MUIA_Window_Backdrop ]
        T &tagBackdrop(const bool backdrop);
        /// @brief [ @b MUIA_Window_Borderless ]
        T &tagBorderless(const bool borderless);
        /// @brief [ @b MUIA_Window_CloseGadget ]
        T &tagCloseGadget(const bool closeGadget);
        /// @brief [ @b MUIA_Window_DefaultObject ]
        T &tagDefaultObject(const Object *defaultObject);
        /// @brief [ @b MUIA_Window_DefaultObject ]
        T &tagDefaultObject(const Root &defaultObject);
        /// @brief [ @b MUIA_Window_DepthGadget ]
        T &tagDepthGadget(const bool depthGadget);
        /// @brief [ @b MUIA_Window_DragBar ]
        T &tagDragBar(const bool dragBar);
#ifdef MUIA_Window_DisableKeys
        /// @brief [ @b MUIA_Window_DisableKeys ]
        T &tagDisableKeys(const unsigned long disableKeys);
#endif
        /// @brief [ @b MUIA_Window_Height ]
        T &tagHeight(const long height);
        /// @brief [ @b MUIA_Window_ID ]
        T &tagID(const AOS::Identifier &id);
        /// @brief [ @b MUIA_Window_IsSubWindow ]
        T &tagIsSubWindow(const bool subWindow);
        /// @brief [ @b MUIA_Window_LeftEdge ]
        T &tagLeftEdge(const long leftEdge);
        /// @brief [ @b MUIA_Window_Menustrip ]
        T &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Window_Menustrip ]
        T &tagMenustrip(const struct NewMenu &newmenu, const unsigned long flags = 0);
        /// @brief [ @b MUIA_Window_NoMenus ]
        T &tagNoMenus(const bool noMenus);
#ifdef MUIA_Window_Opacity
        /// @brief [ @b MUIA_Window_Opacity ]
        T &tagOpacity(const long opacity);
#endif
        /// @brief [ @b MUIA_Window_PublicScreen ]
        T &tagPublicScreen(const char *publicScreen);
        /// @brief [ @b MUIA_Window_PublicScreen ]
        T &tagPublicScreen(const std::string &publicScreen);
        /// @brief [ @b MUIA_Window_RefWindow ]
        T &tagRefWindow(const Object *refWindow);
        /// @brief [ @b MUIA_Window_RefWindow ]
        T &tagRefWindow(const Window &refWindow);
        /// @brief [ @b MUIA_Window_RootObject ]
        T &tagRootObject(const Object *pRootObject);
        /// @brief [ @b MUIA_Window_RootObject ]
        T &tagRootObject(const Root &root);
        /// @brief [ @b MUIA_Window_Screen ]
        T &tagScreen(const void *screen);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        T &tagScreenTitle(const char *screenTitle);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        T &tagScreenTitle(const std::string &screenTitle);
        /// @brief [ @b MUIA_Window_SizeGadget ]
        T &tagSizeGadget(const bool sizeGadget);
        /// @brief [ @b MUIA_Window_SizeRight ]
        T &tagSizeRight(const bool sizeRight);
        /// @brief [ @b MUIA_Window_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Window_Title ]
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Window_TopEdge ]
        T &tagTopEdge(const long topEdge);
        /// @brief [ @b MUIA_Window_UseBottomBorderScroller ]
        T &tagUseBottomBorderScroller(const bool useBottomBorderScroller);
        /// @brief [ @b MUIA_Window_UseLeftBorderScroller ]
        T &tagUseLeftBorderScroller(const bool useLeftBorderScroller);
        /// @brief [ @b MUIA_Window_UseRightBorderScroller ]
        T &tagUseRightBorderScroller(const bool useRightBorderScroller);
        /// @brief [ @b MUIA_Window_Width ]
        T &tagWidth(const long width);
#ifdef MUIA_Window_HasAlpha
        /// @brief [ @b MUIA_Window_HasAlpha ]
        T &tagHasAlpha(const bool hasAlpha);
#endif
#ifdef MUIA_Window_PanelWindow
        /// @brief [ @b MUIA_Window_PanelWindow ]
        T &tagPanelWindow(const bool panelWindow);
#endif
#ifdef MUIA_Window_TabletMessages
        /// @brief [ @b MUIA_Window_TabletMessages ]
        T &tagTabletMessages(const bool tabletMessages);
#endif
#ifdef MUIA_Window_VisibleOnMaximize
        /// @brief [ @b MUIA_Window_VisibleOnMaximize ]
        T &tagVisibleOnMaximize(const bool visibleOnMaximize);
#endif

      protected:
        bool Validate() const override;
    };

    class WindowBuilder : public WindowBuilderTemplate<WindowBuilder, Window>
    {
      public:
        WindowBuilder();
    };

    class WindowScope
    {
        Window &mWindow;

      public:
        WindowScope(Window &window);
        ~WindowScope();

        // explicitly no copy
        WindowScope(const WindowScope &) = delete;
        WindowScope &operator=(const WindowScope &) = delete;

        // explicitly no move
        WindowScope(WindowScope &&) = delete;
        WindowScope &operator=(WindowScope &&) = delete;
    };
}

#define MUI_WINDOW_TPP_INCLUDE
#include "Window.tpp"
#undef MUI_WINDOW_TPP_INCLUDE
