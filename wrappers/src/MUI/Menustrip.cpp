//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Menustrip.hpp"

namespace MUI
{
    const std::string Menustrip::className = MUIC_Menustrip;

#ifdef MUIA_Menustrip_CaseSensitive
    bool Menustrip::isCaseSensitive() const
    {
        return GetValueAsBool(MUIA_Menustrip_CaseSensitive);
    }
#endif

    bool Menustrip::isEnabled() const
    {
        return GetValueAsBool(MUIA_Menustrip_Enabled);
    }

    Menustrip &Menustrip::setEnabled(const bool enabled)
    {
        SetValue(MUIA_Menustrip_Enabled, enabled);
        return *this;
    }

    MenustripBuilder::MenustripBuilder() { }
}
