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
        /// @brief [ @b MUIA_Prop_DeltaFactor ]
        long getDeltaFactor() const;
#endif
        /// @brief [ @b MUIA_Prop_Entries ]
        long getEntries() const;
        /// @brief [ @b MUIA_Prop_First ]
        long getFirst() const;
        /// @brief [ @b MUIA_Prop_Horiz ]
        bool isHoriz() const;
        /// @brief [ @b MUIA_Prop_Visible ]
        long getVisible() const;

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIA_Prop_DeltaFactor ]
        Prop &setDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries ]
        Prop &setEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First ]
        Prop &setFirst(const long first);
        /// @brief [ @b MUIA_Prop_Visible ]
        Prop &setVisible(const long visible);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Prop_Decrease ]
        Notify &Decrease(const long amount);
        /// @brief [ @b MUIM_Prop_Increase ]
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
        /// @brief [ @b MUIA_Prop_DeltaFactor additional delta factor to speed up keyboard navigation.
        // All "fast" movements, like "alt+cursor up", will be multiplied by this factor. Default is 1.]
        T &tagDeltaFactor(const long deltaFactor);
#endif
        /// @brief [ @b MUIA_Prop_Entries total number of entries ]
        T &tagEntries(const long entries);
        /// @brief [ @b MUIA_Prop_First the number of the first entry ]
        T &tagFirst(const long first);
        /// @brief [ @b MUIA_Prop_Horiz horizontal or a vertical prop gadget, default is false]
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Prop_UseWinBorder ]
        T &tagUseWinBorder(const enum Prop_UseWinBorder useWinBorder);
        /// @brief [ @b MUIA_Prop_Visible number of visible entries ]
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
