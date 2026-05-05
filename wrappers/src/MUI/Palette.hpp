//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    /// @brief MUI Palette class wrapper.
    /// Palette class generates a group of objects making up a powerful palette requester,
    /// allowing the user to adjust a defined list of colors via a listview, a coloradjust
    /// gadget and a colorfield. Colors can optionally be concatenated into groups.
    class Palette : public Group
    {
      public:
        explicit Palette(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        Palette(const Root &root)
          : Group(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Palette_Entries ]
        /// Returns the array of palette entries. MUI writes back the adjusted color components
        /// (mpe_Red, mpe_Green, mpe_Blue) directly into this array whenever the user edits a color.
        struct MUI_Palette_Entry *getEntries() const;

        /// @brief [ @b MUIA_Palette_Groupable ]
        /// Returns whether palette color grouping is enabled.
        /// By default it is true.
        bool getGroupable() const;
        /// @brief [ @b MUIA_Palette_Groupable ]
        /// Enables or disables palette color grouping.
        Palette &setGroupable(const bool groupable);

        /// @brief [ @b MUIA_Palette_Names ]
        /// Returns the array of name strings used as labels for each palette color entry in the listview.
        const char **getNames() const;
        /// @brief [ @b MUIA_Palette_Names ]
        /// Set the names of palette color entries from a NULL-terminated C string pointer array.
        Palette &setNames(const char *names[]);
        /// @brief [ @b MUIA_Palette_Names ]
        /// Set the names of palette color entries from a vector of strings.
        /// The string copies are stored internally by this C++ wrapper!
        Palette &setNames(const std::vector<std::string> &names);
        /// @brief [ @b MUIA_Palette_Names ] Clear names by explicitly setting the attribute to nullptr.
        Palette &setNamesNull();
    };

    template <typename T, typename U> class PaletteBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        PaletteBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Palette)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Palette_Entries ]
        /// Specify the colors the user should be able to adjust. Supply a NULL-terminated array of
        /// MUI_Palette_Entry structures (mpe_ID, mpe_Red, mpe_Green, mpe_Blue, mpe_Group).
        /// MUI writes back the adjusted color values directly into the provided array.
        T &tagEntries(const struct MUI_Palette_Entry *entries);

        /// @brief [ @b MUIA_Palette_Groupable ]
        /// Enables or disables palette color grouping. Defaults to true.
        T &tagGroupable(const bool groupable);

        /// @brief [ @b MUIA_Palette_Names ]
        /// Specify the names of the palette color entries displayed in the listview.
        /// Must contain as many entries as the MUI_Palette_Entry array (without its terminator).
        T &tagNames(const char *names[]);

        /// @brief [ @b MUIA_Palette_Names ]
        /// Specify the names of the palette color entries displayed in the listview.
        /// Must contain as many entries as the MUI_Palette_Entry array (without its terminator).
        /// The string copies are stored internally by this C++ wrapper!
        T &tagNames(const std::vector<std::string> &names);

        /// @brief [ @b MUIA_Palette_Names ] Set names to nullptr.
        T &tagNamesNull();
    };

    class PaletteBuilder : public PaletteBuilderTemplate<PaletteBuilder, Palette>
    {
      public:
        PaletteBuilder();
    };
}

#define MUI_PALETTE_TPP_INCLUDE
#include "Palette.tpp"
#undef MUI_PALETTE_TPP_INCLUDE
