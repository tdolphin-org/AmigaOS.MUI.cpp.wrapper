//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SELECTGROUP_TPP_INCLUDE
#error "Selectgroup.tpp should only be included by Selectgroup.hpp"
#endif

#ifdef AOS_MUI_VERSION_5
namespace MUI
{
    template <typename T, typename U> inline T &SelectgroupBuilderTemplate<T, U>::tagActive(long active)
    {
        this->PushTag(MUIA_Selectgroup_Active, active);
        return (T &)*this;
    }
    template <typename T, typename U> inline T &SelectgroupBuilderTemplate<T, U>::tagActive(ValueTypes::Selectgroup::Active active)
    {
        this->PushTag(MUIA_Selectgroup_Active, static_cast<long>(active));
        return (T &)*this;
    }
    template <typename T, typename U> inline bool SelectgroupBuilderTemplate<T, U>::Validate() const
    {
        return GroupBuilderTemplate<T, U>::Validate();
    }
}
#endif // AOS_MUI_VERSION_5
