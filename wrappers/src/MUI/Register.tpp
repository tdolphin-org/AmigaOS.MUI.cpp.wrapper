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
        this->PushTag(MUIA_Register_Titles, (const char **)titles);
        return (T &)*this;
    }
}
