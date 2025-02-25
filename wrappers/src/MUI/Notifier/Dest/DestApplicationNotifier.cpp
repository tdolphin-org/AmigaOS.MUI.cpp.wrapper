//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "DestApplicationNotifier.hpp"

#include <proto/alib.h>

#include "MUI/Window.hpp"

namespace MUI
{
    DestApplicationNotifier::DestApplicationNotifier(const NotifierObject &notifierObject, const Application &application)
      : DestNotifyNotifier(notifierObject, application)
    {
    }

    DestApplicationNotifier::DestApplicationNotifier(const NotifierObject &notifierObject, const enum NotifyDestType notifyDestType)
      : DestNotifyNotifier(notifierObject, notifyDestType)
    {
    }

    DestApplicationNotifier &DestApplicationNotifier::aboutMUI(const Window &window)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 2, MUIM_Application_AboutMUI,
                 window.muiObject());
        return *this;
    }

    DestApplicationNotifier &DestApplicationNotifier::returnIDQuit()
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 2, MUIM_Application_ReturnID,
                 MUIV_Application_ReturnID_Quit);
        return *this;
    }

    DestApplicationNotifier &DestApplicationNotifier::returnID(const unsigned long returnId)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTriggerValue(), muiDestObject(), 2, MUIM_Application_ReturnID,
                 returnId);
        return *this;
    }
}
