//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "../Core/DestNotifierRoot.hpp"
#include "MUI/Notify.hpp"

namespace MUI
{
    class NotifierObject;

    class DestNotifyNotifier : public DestNotifierRoot
    {
        friend class SourceNotifierRoot;
        template <typename T, typename U> friend class SourceNotifier;

      protected:
        DestNotifyNotifier() = delete;
        DestNotifyNotifier(const NotifierObject &notifierObject, const Notify &notify);

      public:
        /// @brief call any MUI method
        /// @param methodId id method
        DestNotifyNotifier &method(const unsigned long methodId);
        /// @brief [ @b MUIM_CallHook, no parameters ]
        DestNotifyNotifier &callHook(const void *hook);
        /// @brief [ @b MUIM_CallHook, one parameter ]
        DestNotifyNotifier &callHook(const void *hook, const void *arg0);
        /// @brief [ @b MUIM_CallHook, two parameters ]
        DestNotifyNotifier &callHook(const void *hook, const void *arg0, const void *arg1);
        /// @brief [ @b MUIM_CallHook, three parameters ]
        DestNotifyNotifier &callHook(const void *hook, const void *arg0, const void *arg1, const void *arg2);
        /// @brief [ @b MUIM_CallHook, four parameters ]
        DestNotifyNotifier &callHook(const void *hook, const void *arg0, const void *arg1, const void *arg2, const void *arg3);
        /// @brief [ @b MUIM_WriteLong ]
        DestNotifyNotifier &writeLong(const unsigned long val, unsigned long *memory);
        /// @brief [ @b MUIM_WriteLong, @b MUIV_TriggerValue ]
        DestNotifyNotifier &writeLongTriggerValue(unsigned long *memory);
        /// @brief [ @b MUIM_WriteString ]
        DestNotifyNotifier &writeString(const char *str, char *memory);
        /// @brief [ @b MUIM_WriteString, @b MUIV_TriggerValue ]
        DestNotifyNotifier &writeStringTriggerValue(char *memory);
    };
}
