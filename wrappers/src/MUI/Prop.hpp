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
    /// @brief Prop class generates the well known proportional gadgets. It offers the same
    /// attributes as a usual boopsi gadget of propgclass. However, MUI's prop gadgets allow
    /// using any imagery for the knob and for the background.
    class Prop : public Gadget
    {
      public:
        explicit Prop(Object *pMuiObject)
          : Gadget(pMuiObject)
        {
        }

        Prop(const Root &root)
          : Gadget(root.muiObject())
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

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Set or get an additional delta factor to speed up
        /// keyboard navigation. All "fast" movements, like "alt+cursor up", will be multiplied by
        /// this factor. Defaults to 1.
        long getDeltaFactor() const;
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Set or get the total number of entries.
        long getEntries() const;
        /// @brief [ @b MUIA_Prop_First ] Set or get the number of the first entry.
        long getFirst() const;
        /// @brief [ @b MUIA_Prop_Horiz ] Determine if you want a horizontal or a vertical prop gadget.
        /// Defaults to false, i.e. vertical.
        bool isHoriz() const;
#ifdef MUIA_Prop_Slider
        /// @brief [ @b MUIA_Prop_Slider ] Indicate that this prop gadget is used in a slider.
        /// MUI might then use different imagery.
        bool isSlider() const;
#endif
        /// @brief [ @b MUIA_Prop_Visible ] Set or get the number of visible entries.
        long getVisible() const;

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Set or get an additional delta factor to speed up
        /// keyboard navigation. All "fast" movements, like "alt+cursor up", will be multiplied by
        /// this factor. Defaults to 1.
        Prop &setDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Set or get the total number of entries.
        Prop &setEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First ] Set or get the number of the first entry.
        Prop &setFirst(const long first);
#ifdef MUIA_Prop_Slider
        /// @brief [ @b MUIA_Prop_Slider ] Indicate that this prop gadget is used in a slider.
        /// MUI might then use different imagery.
        Prop &setSlider(const bool slider);
#endif
        /// @brief [ @b MUIA_Prop_Visible ] Set or get the number of visible entries.
        Prop &setVisible(const long visible);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Prop_Decrease ] Decreases the value of the proportional gadget by the
        /// specified amount. Negative values are ok. Range checking is done automatically.
        /// @param amount amount to subtract from the gadgets current position.
        Prop &Decrease(const long amount);
        /// @brief [ @b MUIM_Prop_Increase ] Increases the value of the proportional gadget by the
        /// specified amount. Negative values are ok. Range checking is done automatically.
        /// @param amount amount to add to the gadgets current position.
        Prop &Increase(const long amount);
    };

    template <typename T, typename U> class PropBuilderTemplate : public GadgetBuilderTemplate<T, U>
    {
      public:
        PropBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Prop)
          : GadgetBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ] Set or get an additional delta factor to speed up
        /// keyboard navigation. All "fast" movements, like "alt+cursor up", will be multiplied by
        /// this factor. Defaults to 1.
        T &tagDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries ] Set or get the total number of entries.
        T &tagEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First ] Set or get the number of the first entry.
        T &tagFirst(const long first);
        /// @brief [ @b MUIA_Prop_Horiz ] Determine if you want a horizontal or a vertical prop gadget.
        /// Defaults to false, i.e. vertical.
        T &tagHoriz(const bool horiz);
#ifdef MUIA_Prop_Slider
        /// @brief [ @b MUIA_Prop_Slider ] Indicate that this prop gadget is used in a slider.
        /// MUI might then use different imagery.
        T &tagSlider(const bool slider);
#endif
        /// @brief [ @b MUIA_Prop_UseWinBorder ] Links this prop gadget to one of the scrollbars
        /// in the window border. The gadget then stays invisible and its control is linked to the
        /// specified border scroller (None/Left/Right/Bottom).
        T &tagUseWinBorder(const enum Prop_UseWinBorder useWinBorder);
        /// @brief [ @b MUIA_Prop_Visible ] Set or get the number of visible entries.
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
