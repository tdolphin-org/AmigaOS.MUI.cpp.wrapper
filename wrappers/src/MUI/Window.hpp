//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "AOS/Identifier.hpp"
#include "Menustrip.hpp"
#include "Notify.hpp"

#include <proto/muimaster.h>

#undef Open
#undef Close

namespace MUI
{
    struct NewMenu;

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

        /// @brief [ @b MUIA_Window_Open ]
        bool isOpen() const;
        /// @brief [ @b MUIA_Window_ID ]
        AOS::Identifier getID() const;
        /// @brief [ @b MUIA_Window_RootObject ]
        /// @return a pointer to a MUI object, the contents of window,
        /// The root object is treated as child of a window and will be disposed when the window is disposed. Window can only have one
        /// child.
        Object *getRootObject() const;
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        std::string getScreenTitle() const;

        /// @brief [ @b MUIA_Window_ID ]
        Window &setID(const AOS::Identifier &id);
        /// @brief [ @b MUIA_Window_RootObject ]
        Window &setRootObject(const Object *rootObject);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        Window &setScreenTitle(const std::string &screenTitle);

        // methods, some returns object reference

        /// @brief [ @b MUIA_Window_Open, @b TRUE ]
        Window &Open();
        /// @brief [ @b MUIA_Window_Open, @b FALSE ]
        Window &Close();
        /// @brief [ @b MUIM_Window_ToFront ]
        Window &ToFront();
    };

    template <typename T, typename U> class WindowBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
        bool hasRootObject { false };

      public:
        WindowBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Window)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Window_AltHeight ]
        T &tagAltHeight(const long altHeight);
        /// @brief [ @b MUIA_Window_AltWidth ]
        T &tagAltWidth(const long altWidth);
        /// @brief [ @b MUIA_Window_Height ]
        T &tagHeight(const long height);
        /// @brief [ @b MUIA_Window_ID ]
        T &tagID(const AOS::Identifier &id);
        /// @brief [ @b MUIA_Window_Menustrip ]
        T &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Window_Menustrip ]
        T &tagMenustrip(const struct NewMenu &newmenu, const unsigned long flags = 0);
        /// @brief [ @b MUIA_Window_NoMenus ]
        T &tagNoMenus(const bool noMenus);
        /// @brief [ @b MUIA_Window_RootObject ]
        T &tagRootObject(const Object *pRootObject);
        /// @brief [ @b MUIA_Window_RootObject ]
        T &tagRootObject(const Root &root);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        T &tagScreenTitle(const char *screenTitle);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        T &tagScreenTitle(const std::string &screenTitle);
        /// @brief [ @b MUIA_Window_Title ]
        T &tagTitle(const char *title);
        /// @brief [ @b MUIA_Window_Title ]
        T &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Window_Width ]
        T &tagWidth(const long width);

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
