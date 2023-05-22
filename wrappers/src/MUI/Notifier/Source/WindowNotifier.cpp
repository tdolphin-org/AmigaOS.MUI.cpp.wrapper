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

    SourceNotifier<Window, DestWindowNotifier> WindowNotifier::onCloseRequest(const bool closeRequest)
    {
        return SourceNotifier<Window, DestWindowNotifier>(mWindow, MUIA_Window_CloseRequest, closeRequest);
    }

}
