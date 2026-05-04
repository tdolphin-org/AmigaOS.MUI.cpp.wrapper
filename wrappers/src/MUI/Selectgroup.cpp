//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2026 TDolphin
//


#include "Selectgroup.hpp"

#ifdef MUIC_Selectgroup

namespace MUI
{
    const std::string Selectgroup::className = MUIC_Selectgroup;
    SelectgroupBuilder::SelectgroupBuilder() { }

    long Selectgroup::getActive() const
    {
        return GetValueAsLong(MUIA_Selectgroup_Active);
    }

    Selectgroup &Selectgroup::setActive(const long active)
    {
        SetValue(MUIA_Selectgroup_Active, active);
        return *this;
    }

    Selectgroup &Selectgroup::setActive(const enum Selectgroup_Active active)
    {
        SetValue(MUIA_Selectgroup_Active, (long)active);
        return *this;
    }
}
    
#endif // MUIC_Selectgroup
