//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_MENUITEM_TPP_INCLUDE
#error "Menuitem.tpp should only be included by Menuitem.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Menuitem_AISSName
    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagAISSName(const std::string &aissName)
    {
        this->PushTag(MUIA_Menuitem_AISSName, aissName);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagChecked(const bool checked)
    {
        this->PushTag(MUIA_Menuitem_Checked, checked);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCheckit(const bool checkit)
    {
        this->PushTag(MUIA_Menuitem_Checkit, checkit);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCommandString(const long commandString)
    {
        this->PushTag(MUIA_Menuitem_CommandString, commandString);
        return (T &)*this;
    }

#ifdef MUIA_Menuitem_CopyStrings
    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagCopyStrings(const bool copyStrings)
    {
        this->PushTag(MUIA_Menuitem_CopyStrings, copyStrings);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menuitem_Enabled, enabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagExclude(const long exclude)
    {
        this->PushTag(MUIA_Menuitem_Exclude, exclude);
        return (T &)*this;
    }

#ifdef MUIA_Menuitem_FreeImage
    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagFreeImage(const bool freeImage)
    {
        this->PushTag(MUIA_Menuitem_FreeImage, freeImage);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Menuitem_Image
    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagImage(const Image *image)
    {
        this->PushTag(MUIA_Menuitem_Image, image);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Menuitem_Menuitem
    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagMenuitem(const Object *menuitem)
    {
        this->PushTag(MUIA_Menuitem_Menuitem, menuitem);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagShortcut(const std::string &shortcut)
    {
        this->PushTag(MUIA_Menuitem_Shortcut, shortcut);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagShortcut(const enum Menuitem_Shortcut shortcut)
    {
        this->PushTag(MUIA_Menuitem_Shortcut, shortcut);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Menuitem_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        auto copy = this->StoreString(MUIA_Menuitem_Title, title);
        this->PushTag(MUIA_Menuitem_Title, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuitemBuilderTemplate<T, U>::tagToggle(const bool toggle)
    {
        this->PushTag(MUIA_Menuitem_Toggle, toggle);
        return (T &)*this;
    }
}
