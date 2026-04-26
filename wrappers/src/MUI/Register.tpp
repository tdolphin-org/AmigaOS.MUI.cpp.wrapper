//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_REGISTER_TPP_INCLUDE
#error "Register.tpp should only be included by Register.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &RegisterBuilderTemplate<T, U>::tagTitles(const char *titles[])
    {
        auto copy = this->StoreStringArray(MUIA_Register_Titles, titles);
        this->PushTag(MUIA_Register_Titles, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &RegisterBuilderTemplate<T, U>::tagTitles(const std::vector<std::string> &titles)
    {
        auto copy = this->StoreStringArray(MUIA_Register_Titles, titles);
        this->PushTag(MUIA_Register_Titles, copy);
        return (T &)*this;
    }
}
