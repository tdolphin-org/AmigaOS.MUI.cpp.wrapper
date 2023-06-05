//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "WindowNotifier.hpp"

namespace MUI
{
    WindowNotifier::WindowNotifier(const Window &window)
      : NotifyNotifier(window)
      , mWindow(window)
    {
    }

    SourceNotifier<Window, DestWindowNotifier> WindowNotifier::onActivate(const bool activate)
    {
        return SourceNotifier<Window, DestWindowNotifier>(mWindow, MUIA_Window_Activate, activate);
    }

    SourceNotifier<Window, DestWindowNotifier> WindowNotifier::onCloseRequest(const bool closeRequest)
    {
        return SourceNotifier<Window, DestWindowNotifier>(mWindow, MUIA_Window_CloseRequest, closeRequest);
    }

    SourceNotifier<Window, DestWindowNotifier> WindowNotifier::onOpen(const bool open)
    {
        return SourceNotifier<Window, DestWindowNotifier>(mWindow, MUIA_Window_Open, open);
    }
}
