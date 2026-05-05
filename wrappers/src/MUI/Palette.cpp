//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Palette.hpp"

namespace MUI
{
    const std::string Palette::className = MUIC_Palette;

    PaletteBuilder::PaletteBuilder() { }

    struct MUI_Palette_Entry *Palette::getEntries() const
    {
        return GetValueAsPaletteEntryPtr(MUIA_Palette_Entries);
    }

    bool Palette::getGroupable() const
    {
        return GetValueAsBool(MUIA_Palette_Groupable);
    }

    Palette &Palette::setGroupable(const bool groupable)
    {
        SetValue(MUIA_Palette_Groupable, groupable);
        return *this;
    }

    const char **Palette::getNames() const
    {
        return GetValueAsConstCharArrayPtr(MUIA_Palette_Names);
    }

    Palette &Palette::setNames(const char *names[])
    {
        SetValue(MUIA_Palette_Names, names);
        return *this;
    }

    Palette &Palette::setNames(const std::vector<std::string> &names)
    {
        auto copy = StoreStringArray(MUIA_Palette_Names, names);
        SetValue(MUIA_Palette_Names, copy);
        return *this;
    }

    Palette &Palette::setNamesNull()
    {
        ClearStoredString(MUIA_Palette_Names);
        SetValue(MUIA_Palette_Names, nullptr);
        return *this;
    }
}
