//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Mccprefs.hpp"

#include <proto/alib.h>

namespace MUI
{
    // Salt for per-gadget title storage tags ("Mcc\0" in ASCII).
    constexpr unsigned long RegisterGadgetTitleTagSalt = 0x4d636300UL;

    static unsigned long RegisterGadgetTitleStorageTag(const Object *gadget)
    {
        const auto gadgetKey = static_cast<unsigned long>(reinterpret_cast<uintptr_t>(gadget));
        return RegisterGadgetTitleTagSalt ^ gadgetKey;
    }

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
    Mccprefs &Mccprefs::RegisterGadget(const Object *gadget, const unsigned long id, const unsigned long params, const char *title,
                                       const unsigned long attr, const Object *label)
    {
        ClearStoredString(RegisterGadgetTitleStorageTag(gadget));
        DoMethod(muiObject(), MUIM_Mccprefs_RegisterGadget, gadget, id, params, title, attr, label);
        return *this;
    }

    Mccprefs &Mccprefs::RegisterGadget(const Object *gadget, const unsigned long id, const unsigned long params, const std::string &title,
                                       const unsigned long attr, const Object *label)
    {
        const auto titleTag = RegisterGadgetTitleStorageTag(gadget);
        const char *titleCopy = StoreString(titleTag, title);
        DoMethod(muiObject(), MUIM_Mccprefs_RegisterGadget, gadget, id, params, titleCopy, attr, label);
        return *this;
    }
#endif

    MccprefsBuilder::MccprefsBuilder() { }
}
