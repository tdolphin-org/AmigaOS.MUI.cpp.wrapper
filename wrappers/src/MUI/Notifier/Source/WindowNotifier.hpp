//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "NotifyNotifier.hpp"
#include "MUI/Window.hpp"

namespace MUI
{
    class WindowNotifier : public NotifyNotifier
    {
        Window mWindow;

      public:
        WindowNotifier() = delete;
        WindowNotifier(const Window &window);

        // notification methods

        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Activate ]
        SourceNotifier<Window, DestWindowNotifier> onActivate(const bool activate);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_CloseRequest ]
        SourceNotifier<Window, DestWindowNotifier> onCloseRequest(const bool closeRequest);
        /// @brief [ @b MUIM_Notify, @b MUIA_Window_Open ]
        SourceNotifier<Window, DestWindowNotifier> onOpen(const bool open);
    };
}
