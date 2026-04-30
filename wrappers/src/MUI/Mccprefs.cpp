//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Mccprefs.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Mccprefs::className = MUIC_Mccprefs;

#ifdef MUIM_Mccprefs_ConfigToGadgets
    Mccprefs &Mccprefs::ConfigToGadgets(const Object *configdata)
    {
        DoMethod(muiObject(), MUIM_Mccprefs_ConfigToGadgets, configdata);
        return *this;
    }
#endif

#ifdef MUIM_Mccprefs_GadgetsToConfig
    Mccprefs &Mccprefs::GadgetsToConfig(const Object *configdata, const Object *originator)
    {
        DoMethod(muiObject(), MUIM_Mccprefs_GadgetsToConfig, configdata, originator);
        return *this;
    }
#endif

#ifdef MUIM_Mccprefs_RegisterGadget
    Mccprefs &Mccprefs::RegisterGadget(const Object *gadget, const unsigned long id, const unsigned long params, const std::string &title,
                                       const unsigned long attr, const Object *label)
    {
        DoMethod(muiObject(), MUIM_Mccprefs_RegisterGadget, gadget, id, params, title.c_str(), attr, label);
        return *this;
    }
#endif

    MccprefsBuilder::MccprefsBuilder() { }
}
