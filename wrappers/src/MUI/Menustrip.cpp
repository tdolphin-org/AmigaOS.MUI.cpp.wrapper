//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Menustrip.hpp"

#include <proto/alib.h>

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

#ifdef MUIM_Menustrip_ExitChange
    Menustrip &Menustrip::ExitChange()
    {
        DoMethod(muiObject(), MUIM_Menustrip_ExitChange);
        return *this;
    }
#endif

#ifdef MUIM_Menustrip_InitChange
    Menustrip &Menustrip::InitChange()
    {
        DoMethod(muiObject(), MUIM_Menustrip_InitChange);
        return *this;
    }
#endif

#ifdef MUIM_Menustrip_Popup
    unsigned long Menustrip::Popup(const Object *parent /* = nullptr */, const unsigned long flags /* = 0 */, const long x /* = 0 */,
                                   const long y /* = 0 */)
    {
        return DoMethod(muiObject(), MUIM_Menustrip_Popup, parent, flags, x, y);
    }

    unsigned long Menustrip::Popup(const Root &parent, const unsigned long flags /* = 0 */, const long x /* = 0 */, const long y /* = 0 */)
    {
        return DoMethod(muiObject(), MUIM_Menustrip_Popup, parent.muiObject(), flags, x, y);
    }
#endif

#ifdef MUIM_Menustrip_WillOpen
    unsigned long Menustrip::WillOpen()
    {
        return DoMethod(muiObject(), MUIM_Menustrip_WillOpen);
    }
#endif

    MenustripBuilder::MenustripBuilder() { }
}
