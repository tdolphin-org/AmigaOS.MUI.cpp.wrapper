//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Gadget.hpp"
#include "ValueTypes/Prop/UseWinBorder.hpp"

namespace MUI
{
    // Prop class generates the well known proportional gadgets. It offers the same attributes as a usual boopsi gadget of propgclass.
    // However, MUI's prop gadgets allow using any imagery for the knob and for the background.
    class Prop : public Gadget
    {
      public:
        explicit Prop(Object *pMuiObject)
          : Gadget(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Speed factor for keyboard navigation (fast movements multiplied by this).
        long getDeltaFactor() const;
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Total number of entries in the proportional gadget range.
        long getEntries() const;
        /// @brief [ @b MUIA_Prop_First ] Number of the first visible entry.
        long getFirst() const;
        /// @brief [ @b MUIA_Prop_Horiz ] Orientation (true for horizontal, false for vertical).
        bool isHoriz() const;
        /// @brief [ @b MUIA_Prop_Visible ] Number of visible entries.
        long getVisible() const;

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Set speed factor for keyboard navigation.
        Prop &setDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Set total number of entries.
        Prop &setEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First ] Set number of the first visible entry.
        Prop &setFirst(const long first);
        /// @brief [ @b MUIA_Prop_Visible ] Set number of visible entries.
        Prop &setVisible(const long visible);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Prop_Decrease ] Decrease gadget value by specified amount.
        /// @param amount value to subtract from current position.
        Notify &Decrease(const long amount);
        /// @brief [ @b MUIM_Prop_Increase ] Increase gadget value by specified amount.
        /// @param amount value to add to current position.
        Notify &Increase(const long amount);
    };

    template <typename T, typename U> class PropBuilderTemplate : public GadgetBuilderTemplate<T, U>
    {
      public:
        PropBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Prop)
          : GadgetBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Speed factor for keyboard navigation.
        T &tagDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Total number of entries.
        T &tagEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First ] Number of the first visible entry.
        T &tagFirst(const long first);
        /// @brief [ @b MUIA_Prop_Horiz ] Orientation: true for horizontal, false for vertical.
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Prop_UseWinBorder ] Link to window border scroller (None/Left/Right/Bottom).
        T &tagUseWinBorder(const enum Prop_UseWinBorder useWinBorder);
        /// @brief [ @b MUIA_Prop_Visible ] Number of visible entries.
        T &tagVisible(const long visible);
    };

    class PropBuilder : public PropBuilderTemplate<PropBuilder, Prop>
    {
      public:
        PropBuilder();
    };
}

#define MUI_PROP_TPP_INCLUDE
#include "Prop.tpp"
#undef MUI_PROP_TPP_INCLUDE
