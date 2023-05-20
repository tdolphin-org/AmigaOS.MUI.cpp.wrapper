//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"
#include "MUI/Area.hpp"

namespace MUI
{
    class DestAreaNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestAreaNotifier() = delete;
        DestAreaNotifier(const NotifierObject &notifierObject, const Area &area);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Disabled ]
        DestAreaNotifier &setDisabled(const bool disabled, bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Selected ]
        DestAreaNotifier &setSelected(const bool selected, bool notify = true);
    };
}
