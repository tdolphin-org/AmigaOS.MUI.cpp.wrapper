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
