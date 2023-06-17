//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AOS/Identifier.hpp"
#include "Menustrip.hpp"
#include "Notify.hpp"

#include <stdexcept>

#include <proto/muimaster.h>

namespace MUI
{
    struct NewMenu;

    class Window : public Notify
    {
      public:
        Window(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Window(const APTR pMuiObject)
          : Notify(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Window);
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Window_Open ]
        bool isOpen();
        /// @brief [ @b MUIA_Window_ID ]
        AOS::Identifier getID();
        /// @brief [ @b MUIA_Window_RootObject ]
        /// @return a pointer to a MUI object, the contents of window,
        /// The root object is treated as child of a window and will be disposed when the window is disposed. Window can only have one
        /// child.
        Object *getRootObject();
        /// @brief [ @b MUIA_Window_ScreenTitle ]
        std::string getScreenTitle();

        /// @brief [ @b MUIA_Window_ID ]
        Window &setID(const AOS::Identifier &id);
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

    template <typename T, typename U> class WindowBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
        bool hasRootObject;

      public:
        WindowBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Window)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
          , hasRootObject(false)
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

        U object() const;
        U object(const unsigned long dataSize, const void *pDispatcher) const;
    };

    class WindowBuilder : public WindowBuilderTemplate<WindowBuilder, Window>
    {
      public:
        WindowBuilder();
    };

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltHeight(const long altHeight)
    {
        this->PushTag(MUIA_Window_AltHeight, altHeight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagAltWidth(const long altWidth)
    {
        this->PushTag(MUIA_Window_AltWidth, altWidth);
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

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRootObject(const Object *pRootObject)
    {
        this->PushTag(MUIA_Window_RootObject, pRootObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagRootObject(const Root &root)
    {
        hasRootObject = true;
        this->PushTag(MUIA_Window_RootObject, root.muiObject());
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

    template <typename T, typename U> inline T &WindowBuilderTemplate<T, U>::tagWidth(const long width)
    {
        this->PushTag(MUIA_Window_Width, width);
        return (T &)*this;
    }

    template <typename T, typename U> inline U WindowBuilderTemplate<T, U>::object() const
    {
        // The root object is mandatory during window creation and trying to create a window without a root object will fail.
        // So check if there is tag for RootObject.
        if (!hasRootObject)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + ", missing RootObject for Window!";
            throw std::runtime_error(error);
        }

        return NotifyBuilderTemplate<T, U>::object();
    }

    template <typename T, typename U>
    inline U WindowBuilderTemplate<T, U>::object(const unsigned long dataSize, const void *pDispatcher) const
    {
        // The root object is mandatory during window creation and trying to create a window without a root object will fail.
        // So check if there is tag for RootObject.
        if (!hasRootObject)
        {
            std::string error = (std::string) __PRETTY_FUNCTION__ + ", missing RootObject for Window!";
            throw std::runtime_error(error);
        }

        return NotifyBuilderTemplate<T, U>::object(dataSize, pDispatcher);
    }

    class WindowScope
    {
        Window &mWindow;

      public:
        WindowScope(Window &window);
        ~WindowScope();
    };
}
