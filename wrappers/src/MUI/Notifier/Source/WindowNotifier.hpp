//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "MUI/Window.hpp"
#include "NotifyNotifier.hpp"

namespace MUI
{
    template <typename T = DestWindowNotifier> class WindowNotifier : public NotifyNotifier<T>
    {
        Window mWindow;

      public:
        WindowNotifier() = delete;
        WindowNotifier(const Window &window)
          : NotifyNotifier<T>(window)
          , mWindow(window)
        {
        }

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Activate ]
        SourceNotifier<Window, T> onActivate(const bool activate);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_CloseRequest ]
        SourceNotifier<Window, T> onCloseRequest(const bool closeRequest);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Open ]
        SourceNotifier<Window, T> onOpen(const bool open);
    };

    template <typename T> SourceNotifier<Window, T> inline WindowNotifier<T>::onActivate(const bool activate)
    {
        return SourceNotifier<Window, T>(mWindow, MUIA_Window_Activate, activate);
    }

    template <typename T> SourceNotifier<Window, T> inline WindowNotifier<T>::onCloseRequest(const bool closeRequest)
    {
        return SourceNotifier<Window, T>(mWindow, MUIA_Window_CloseRequest, closeRequest);
    }

    template <typename T> SourceNotifier<Window, T> inline WindowNotifier<T>::onOpen(const bool open)
    {
        return SourceNotifier<Window, T>(mWindow, MUIA_Window_Open, open);
    }

}
