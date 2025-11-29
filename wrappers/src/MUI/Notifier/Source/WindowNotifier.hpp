//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "MUI/Window.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    template <typename T = Window, typename U = DestWindowNotifier> class WindowNotifier : public NotifyNotifier<T, U>
    {
      public:
        WindowNotifier() = delete;
        WindowNotifier(const T &window)
          : NotifyNotifier<T, U>(window)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Activate ]
        SourceNotifier<T, U> onActivate(const bool activate);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_CloseRequest ]
        SourceNotifier<T, U> onCloseRequest(const bool closeRequest);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_MenuAction ]
        SourceNotifier<T, U> onMenuAction(const unsigned long menuAction);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_NoMenus ]
        SourceNotifier<T, U> onNoMenus(const bool noMenus);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Opacity ]
        SourceNotifier<T, U> onOpacity(const long opacity);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Open ]
        SourceNotifier<T, U> onOpen(const bool open);
    };

    template <typename T, typename U> SourceNotifier<T, U> inline WindowNotifier<T, U>::onActivate(const bool activate)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_Activate, activate);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline WindowNotifier<T, U>::onCloseRequest(const bool closeRequest)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_CloseRequest, closeRequest);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> WindowNotifier<T, U>::onMenuAction(const unsigned long menuAction)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_MenuAction, menuAction);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> WindowNotifier<T, U>::onNoMenus(const bool noMenus)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_NoMenus, noMenus);
    }

    template <typename T, typename U> inline SourceNotifier<T, U> WindowNotifier<T, U>::onOpacity(const long opacity)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_Opacity, opacity);
    }

    template <typename T, typename U> SourceNotifier<T, U> inline WindowNotifier<T, U>::onOpen(const bool open)
    {
        return SourceNotifier<T, U>(NotifyNotifier<T, U>::mObject, MUIA_Window_Open, open);
    }
}
