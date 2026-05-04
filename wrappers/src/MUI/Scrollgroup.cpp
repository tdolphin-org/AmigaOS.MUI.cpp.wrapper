//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Scrollgroup.hpp"
#include "Scrollbar.hpp"

namespace MUI
{
    const std::string Scrollgroup::className = MUIC_Scrollgroup;

    ScrollgroupBuilder::ScrollgroupBuilder() { }

    Optional<Virtgroup> Scrollgroup::getContents() const
    {
        Object *obj = GetValueAsObjectPtr(MUIA_Scrollgroup_Contents);
        if (!obj)
            return { };
        return Virtgroup(obj);
    }

    Object *Scrollgroup::getContentsObject() const
    {
        return GetValueAsObjectPtr(MUIA_Scrollgroup_Contents);
    }

    Optional<Scrollbar> Scrollgroup::getHorizBar() const
    {
        Object *obj = GetValueAsObjectPtr(MUIA_Scrollgroup_HorizBar);
        if (!obj)
            return { };
        return Scrollbar(obj);
    }

    Object *Scrollgroup::getHorizBarObject() const
    {
        return GetValueAsObjectPtr(MUIA_Scrollgroup_HorizBar);
    }

    Optional<Scrollbar> Scrollgroup::getVertBar() const
    {
        Object *obj = GetValueAsObjectPtr(MUIA_Scrollgroup_VertBar);
        if (!obj)
            return { };
        return Scrollbar(obj);
    }

    Object *Scrollgroup::getVertBarObject() const
    {
        return GetValueAsObjectPtr(MUIA_Scrollgroup_VertBar);
    }

#ifdef MUIA_Scrollgroup_AutoBars
    bool Scrollgroup::getAutoBars() const
    {
        return GetValueAsBool(MUIA_Scrollgroup_AutoBars);
    }

    Scrollgroup &Scrollgroup::setAutoBars(const bool autoBars)
    {
        SetValue(MUIA_Scrollgroup_AutoBars, autoBars);
        return *this;
    }
#endif

#ifdef MUIA_Scrollgroup_NoHorizBar
    bool Scrollgroup::getNoHorizBar() const
    {
        return GetValueAsBool(MUIA_Scrollgroup_NoHorizBar);
    }

    Scrollgroup &Scrollgroup::setNoHorizBar(const bool noHorizBar)
    {
        SetValue(MUIA_Scrollgroup_NoHorizBar, noHorizBar);
        return *this;
    }
#endif

#ifdef MUIA_Scrollgroup_NoVertBar
    bool Scrollgroup::getNoVertBar() const
    {
        return GetValueAsBool(MUIA_Scrollgroup_NoVertBar);
    }

    Scrollgroup &Scrollgroup::setNoVertBar(const bool noVertBar)
    {
        SetValue(MUIA_Scrollgroup_NoVertBar, noVertBar);
        return *this;
    }
#endif
}
