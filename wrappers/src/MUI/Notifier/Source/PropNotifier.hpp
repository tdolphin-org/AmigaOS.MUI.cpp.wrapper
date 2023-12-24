//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "GadgetNotifier.hpp"
#include "MUI/Prop.hpp"

namespace MUI
{
    template <typename T = DestPropNotifier> class PropNotifier : public GadgetNotifier<T>
    {
        Prop mProp;

      public:
        inline PropNotifier() = delete;
        inline PropNotifier(const Prop &prop)
          : GadgetNotifier<T>(prop)
          , mProp(prop)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor ]
        SourceNotifier<Prop, T> onDeltaFactor(const long deltaFactor);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor == @b MUIV_EveryTime ]
        SourceNotifier<Prop, T> onDeltaFactorEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries ]
        SourceNotifier<Prop, T> onEntries(const long entries);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries == @b MUIV_EveryTime ]
        SourceNotifier<Prop, T> onEntriesEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First ]
        SourceNotifier<Prop, T> onFirst(const long first);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First == @b MUIV_EveryTime ]
        SourceNotifier<Prop, T> onFirstEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible ]
        SourceNotifier<Prop, T> onVisible(const long visible);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible == @b MUIV_EveryTime ]
        SourceNotifier<Prop, T> onVisibleEveryTime();
    };

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onDeltaFactor(const long deltaFactor)
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_DeltaFactor, deltaFactor);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onDeltaFactorEveryTime()
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_DeltaFactor, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onEntries(const long entries)
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_Entries, entries);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onEntriesEveryTime()
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_Entries, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onFirst(const long first)
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_First, first);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onFirstEveryTime()
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_First, (long)MUIV_EveryTime);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onVisible(const long visible)
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_Visible, visible);
    }

    template <typename T> SourceNotifier<Prop, T> inline PropNotifier<T>::onVisibleEveryTime()
    {
        return SourceNotifier<Prop, T>(mProp, MUIA_Prop_Visible, (long)MUIV_EveryTime);
    }
}
