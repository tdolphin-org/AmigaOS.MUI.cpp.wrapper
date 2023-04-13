//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Notify.hpp"

namespace MUI
{
    class Menustrip;

    class Window : public Notify
    {
      public:
        Window(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // get/set (attributes), all setters return object reference

        // methods, some can return object reference

        /// @brief [ @b MUIA_Window_Open, TRUE ]
        Window &Open();
        /// @brief [ @b MUIA_Window_Open, FALSE ]
        Window &Close();
    };

    class WindowBuilder : public NotifyBuilderTemplate<WindowBuilder, Window>
    {
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
        /// @brief [ @b MUIA_Window_NoMenus ]
        WindowBuilder &tagNoMenus(const bool noMenus);
        /// @brief [ @b MUIA_Window_RootObject ]
        WindowBuilder &tagRootObject(const Object *pRootObject);
        /// @brief [ @b MUIA_Window_RootObject ]
        WindowBuilder &tagRootObject(const Root &root);
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        WindowBuilder &tagScreenTitle(const char *screenTitle);
        /// @brief [ @b MUIA_Window_Title ]
        WindowBuilder &tagTitle(const char *title);
        /// @brief [ @b MUIA_Window_Width ]
        WindowBuilder &tagWidth(const long width);
    };

    class WindowScope
    {
        Window &mWindow;

      public:
        WindowScope(Window &window)
          : mWindow(window)
        {
            mWindow.Open();
        }
        ~WindowScope()
        {
            mWindow.Close();
        }
    };
}
