//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Gadget.hpp"
#include "ValueTypes/Prop/UseWinBorder.hpp"

namespace MUI
{
    class Prop : public Gadget
    {
      public:
        Prop(const Object *pMuiObject)
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

        /// @brief [ @b MUIA_Prop_DeltaFactor ]
        long getDeltaFactor() const;
        /// @brief [ @b MUIA_Prop_Entries ]
        long getEntries() const;
        /// @brief [ @b MUIA_Prop_First ]
        long getFirst() const;
        /// @brief [ @b MUIA_Prop_Horiz ]
        bool isHoriz() const;
        /// @brief [ @b MUIA_Prop_Visible ]
        long getVisible() const;

        /// @brief [ @b MUIA_Prop_DeltaFactor ]
        Prop &setDeltaFactor(const long deltaFactor);
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

        /// @brief [ @b MUIA_Prop_DeltaFactor additional delta factor to speed up keyboard navigation.
        // All "fast" movements, like "alt+cursor up", will be multiplied by this factor. Default is 1.]
        T &tagDeltaFactor(const long deltaFactor);
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

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagDeltaFactor(const long deltaFactor)
    {
        this->PushTag(MUIA_Prop_DeltaFactor, deltaFactor);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagEntries(const long entries)
    {
        this->PushTag(MUIA_Prop_Entries, entries);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagFirst(const long first)
    {
        this->PushTag(MUIA_Prop_First, first);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Prop_Horiz, horiz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagUseWinBorder(const enum Prop_UseWinBorder useWinBorder)
    {
        this->PushTag(MUIA_Prop_UseWinBorder, useWinBorder);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PropBuilderTemplate<T, U>::tagVisible(const long visible)
    {
        this->PushTag(MUIA_Prop_Visible, visible);
        return (T &)*this;
    }
}
