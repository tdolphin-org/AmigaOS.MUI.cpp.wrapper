//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_POPLIST_TPP_INCLUDE
#error "Poplist.tpp should only be included by Poplist.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PoplistBuilderTemplate<T, U>::tagArray(const char *array[])
    {
        auto copy = this->StoreStringArray(MUIA_Poplist_Array, array);
        this->PushTag(MUIA_Poplist_Array, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PoplistBuilderTemplate<T, U>::tagArray(const std::vector<std::string> &array)
    {
        auto copy = this->StoreStringArray(MUIA_Poplist_Array, array);
        this->PushTag(MUIA_Poplist_Array, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PoplistBuilderTemplate<T, U>::tagArrayNull()
    {
        this->PushTag(MUIA_Poplist_Array, nullptr);
        return (T &)*this;
    }
}
