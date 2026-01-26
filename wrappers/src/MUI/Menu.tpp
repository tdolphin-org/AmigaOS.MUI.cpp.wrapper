//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_MENU_TPP_INCLUDE
#error "Menu.tpp should only be included by Menu.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Menu_CopyStrings
    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagCopyStrings(const bool copyStrings)
    {
        this->PushTag(MUIA_Menu_CopyStrings, copyStrings);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagEnabled(const bool enabled)
    {
        this->PushTag(MUIA_Menu_Enabled, enabled);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagTitle(const char *title)
    {
        this->PushTag(MUIA_Menu_Title, title);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &MenuBuilderTemplate<T, U>::tagTitle(const std::string &title)
    {
        this->PushTag(MUIA_Menu_Title, title);
        return (T &)*this;
    }
}
