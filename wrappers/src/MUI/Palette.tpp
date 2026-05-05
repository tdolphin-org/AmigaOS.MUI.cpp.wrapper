//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PALETTE_TPP_INCLUDE
#error "File Palette.tpp can not be included directly, include file Palette.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PaletteBuilderTemplate<T, U>::tagEntries(const struct MUI_Palette_Entry *entries)
    {
        this->PushTag(MUIA_Palette_Entries, (const void *)entries);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PaletteBuilderTemplate<T, U>::tagGroupable(const bool groupable)
    {
        this->PushTag(MUIA_Palette_Groupable, groupable);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PaletteBuilderTemplate<T, U>::tagNames(const char *names[])
    {
        auto copy = this->StoreStringArray(MUIA_Palette_Names, names);
        this->PushTag(MUIA_Palette_Names, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PaletteBuilderTemplate<T, U>::tagNames(const std::vector<std::string> &names)
    {
        auto copy = this->StoreStringArray(MUIA_Palette_Names, names);
        this->PushTag(MUIA_Palette_Names, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PaletteBuilderTemplate<T, U>::tagNamesNull()
    {
        this->PushTag(MUIA_Palette_Names, nullptr);
        return (T &)*this;
    }
}
