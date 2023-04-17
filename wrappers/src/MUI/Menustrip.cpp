//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Menustrip.hpp"

namespace MUI
{
    MenustripBuilder::MenustripBuilder() { }

    bool Menustrip::getCaseSensitive() const
    {
        return GetValueAsBool(MUIA_Menustrip_CaseSensitive);
    }

    bool Menustrip::getEnabled() const
    {
        return GetValueAsBool(MUIA_Menustrip_Enabled);
    }

    Menustrip &Menustrip::setEnabled(const bool enabled)
    {
        SetValue(MUIA_Menustrip_Enabled, enabled);
        return *this;
    }
}
