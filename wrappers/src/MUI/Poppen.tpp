//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_POPPEN_TPP_INCLUDE
#error "Poppen.tpp should only be included by Poppen.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PoppenBuilderTemplate<T, U>::tagWindowTitle(const char *title)
    {
        this->PushTag(MUIA_Window_Title, this->StoreString(MUIA_Window_Title, title));
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PoppenBuilderTemplate<T, U>::tagWindowTitle(const std::string &title)
    {
        this->PushTag(MUIA_Window_Title, this->StoreString(MUIA_Window_Title, title));
        return (T &)*this;
    }
}
