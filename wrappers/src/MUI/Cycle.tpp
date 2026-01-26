//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_CYCLE_TPP_INCLUDE
#error "File Cycle.tpp can not be included directly, include file Cycle.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &CycleBuilderTemplate<T, U>::tagActive(const long active)
    {
        this->PushTag(MUIA_Cycle_Active, active);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &CycleBuilderTemplate<T, U>::tagEntries(const char *entries[])
    {
        this->PushTag(MUIA_Cycle_Entries, entries);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &CycleBuilderTemplate<T, U>::tagEntries(const std::vector<std::string> &entries)
    {
        auto copy = this->StoreStringArray(MUIA_Cycle_Entries, entries);
        this->PushTag(MUIA_Cycle_Entries, copy);
        return (T &)*this;
    }
}
