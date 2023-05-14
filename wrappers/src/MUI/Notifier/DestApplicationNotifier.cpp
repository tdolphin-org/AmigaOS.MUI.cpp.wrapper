//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestApplicationNotifier.hpp"

#include <proto/alib.h>

#include "MUI/Application.hpp"

namespace MUI
{
    DestApplicationNotifier::DestApplicationNotifier(const SourceNotifier &sourceNotifier, const Application &application)
      : DestNotifyNotifier(sourceNotifier, application)
    {
    }

    DestApplicationNotifier &DestApplicationNotifier::returnIDQuit()
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 2, MUIM_Application_ReturnID,
                 MUIV_Application_ReturnID_Quit);

        return *this;
    }

    DestApplicationNotifier &DestApplicationNotifier::returnID(const unsigned long returnId)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 2, MUIM_Application_ReturnID,
                 returnId);

        return *this;
    }
}
