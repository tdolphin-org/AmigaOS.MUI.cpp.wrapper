//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Notify.hpp"

namespace MUI
{
    class Menustrip;
    struct NewMenu;

    class Window : public Notify
    {
      public:
        Window(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        inline bool instanceOf(Object *pMuiObject) const
        {
            return MUI::instanceOf(pMuiObject, MUIC_Window);
        }

        // get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Window_Open ]
        bool isOpen();
        /// @brief [ @b MUIA_Window_RootObject ]
        /// @return a pointer to a MUI object, the contents of window,
        /// The root object is treated as child of a window and will be disposed when the window is disposed. Window can only have one
        /// child.
        Object *getRootObject();
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        std::string getScreenTitle();

        /// @brief [ @b MUIA_Window_RootObject ]
        Window &setRootObject(const Object *rootObject);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        Window &setScreenTitle(const std::string &screenTitle);

        // methods, some can return object reference

        /// @brief [ @b MUIA_Window_Open, @b TRUE ]
        Window &Open();
        /// @brief [ @b MUIA_Window_Open, @b FALSE ]
        Window &Close();
    };

    class WindowBuilder : public NotifyBuilderTemplate<WindowBuilder, Window>
    {
        bool hasRootObject;

      public:
        WindowBuilder();

        /// @brief [ @b MUIA_Window_AltHeight ]
        WindowBuilder &tagAltHeight(const long altHeight);
        /// @brief [ @b MUIA_Window_AltWidth ]
        WindowBuilder &tagAltWidth(const long altWidth);
        /// @brief [ @b MUIA_Window_Height ]
        WindowBuilder &tagHeight(const long height);
        /// @brief [ @b MUIA_Window_ID ]
        WindowBuilder &tagID(const char id[4]);
        /// @brief [ @b MUIA_Window_Menustrip ]
        WindowBuilder &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Window_Menustrip ]
        WindowBuilder &tagMenustrip(const struct NewMenu &newmenu, const unsigned long flags = 0);
        /// @brief [ @b MUIA_Window_NoMenus ]
        WindowBuilder &tagNoMenus(const bool noMenus);
        /// @brief [ @b MUIA_Window_RootObject ]
        WindowBuilder &tagRootObject(const Object *pRootObject);
        /// @brief [ @b MUIA_Window_RootObject ]
        WindowBuilder &tagRootObject(const Root &root);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        WindowBuilder &tagScreenTitle(const char *screenTitle);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        WindowBuilder &tagScreenTitle(const std::string &screenTitle);
        /// @brief [ @b MUIA_Window_Title ]
        WindowBuilder &tagTitle(const char *title);
        /// @brief [ @b MUIA_Window_Title ]
        WindowBuilder &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Window_Width ]
        WindowBuilder &tagWidth(const long width);

        Window object() const;
    };

    class WindowScope
    {
        Window &mWindow;

      public:
        WindowScope(Window &window);
        ~WindowScope();
    };
}
