//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "GadgetNotifier.hpp"
#include "MUI/Prop.hpp"

namespace MUI
{
    template <typename T = Prop, typename U = DestPropNotifier> class PropNotifier : public GadgetNotifier<T, U>
    {
      public:
        inline PropNotifier() = delete;
        inline PropNotifier(const T &prop)
          : GadgetNotifier<T, U>(prop)
        {
        }

        // notification methods

#ifdef MUIA_Prop_DeltaFactor
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor ]
        SourceNotifier<T, U> onDeltaFactor(const long deltaFactor);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_DeltaFactor == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onDeltaFactorEveryTime();
#endif
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries ]
        SourceNotifier<T, U> onEntries(const long entries);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Entries == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onEntriesEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First ]
        SourceNotifier<T, U> onFirst(const long first);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_First == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onFirstEveryTime();
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible ]
        SourceNotifier<T, U> onVisible(const long visible);
        /// @brief [ @b MUIM_Notify, @b MUIA_Prop_Visible == @b MUIV_EveryTime ]
        SourceNotifier<T, U> onVisibleEveryTime();
    };

#ifdef MUIA_Prop_DeltaFactor
    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onDeltaFactor(const long deltaFactor)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_DeltaFactor, deltaFactor);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onDeltaFactorEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_DeltaFactor, (long)MUIV_EveryTime);
    }
#endif

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onEntries(const long entries)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_Entries, entries);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onEntriesEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_Entries, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onFirst(const long first)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_First, first);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onFirstEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_First, (long)MUIV_EveryTime);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onVisible(const long visible)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_Visible, visible);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline PropNotifier<T, U>::onVisibleEveryTime()
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Prop_Visible, (long)MUIV_EveryTime);
    }
}
