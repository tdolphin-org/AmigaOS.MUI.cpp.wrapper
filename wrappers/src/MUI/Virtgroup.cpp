//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Virtgroup.hpp"

namespace MUI
{
    const std::string Virtgroup::className = MUIC_Virtgroup;

    VirtgroupBuilder::VirtgroupBuilder() { }

    long Virtgroup::getHeight() const
    {
        return GetValueAsLong(MUIA_Virtgroup_Height);
    }

    long Virtgroup::getLeft() const
    {
        return GetValueAsLong(MUIA_Virtgroup_Left);
    }

    Virtgroup &Virtgroup::setLeft(const long left)
    {
        SetValue(MUIA_Virtgroup_Left, left);
        return *this;
    }

    long Virtgroup::getTop() const
    {
        return GetValueAsLong(MUIA_Virtgroup_Top);
    }

    Virtgroup &Virtgroup::setTop(const long top)
    {
        SetValue(MUIA_Virtgroup_Top, top);
        return *this;
    }

    long Virtgroup::getWidth() const
    {
        return GetValueAsLong(MUIA_Virtgroup_Width);
    }

#ifdef MUIA_Virtgroup_TryFit
    bool Virtgroup::getTryFit() const
    {
        return GetValueAsBool(MUIA_Virtgroup_TryFit);
    }

    Virtgroup &Virtgroup::setTryFit(const bool tryFit)
    {
        SetValue(MUIA_Virtgroup_TryFit, tryFit);
        return *this;
    }
#endif
}
