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
    template <typename T, typename U> inline T &PoppenBuilderTemplate<T, U>::tagWindowTitle(const std::string &title)
    {
        auto copy = this->StoreString(MUIA_ShortHelp, title);
        this->PushTag(MUIA_Window_Title, copy);
        return (T &)*this;
    }
}
