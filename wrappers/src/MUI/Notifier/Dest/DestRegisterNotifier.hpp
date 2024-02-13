//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "DestGroupNotifier.hpp"
#include "MUI/Register.hpp"

namespace MUI
{
    class DestRegisterNotifier : public DestGroupNotifier
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestRegisterNotifier() = delete;
        DestRegisterNotifier(const NotifierObject &notifierObject, const Register &registerObject);

      public:
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Register_Titles ]
        DestRegisterNotifier &setTitles(const char *titles[], bool notify = true);
        /// @brief [ @b MUIM_Set / @b MUIM_NoNotifySet, @b MUIA_Register_Titles = @b MUIV_TriggerValue ]
        DestRegisterNotifier &setTitlesTriggerValue(bool notify = true);
    };
}
