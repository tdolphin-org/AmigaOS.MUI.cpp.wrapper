//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestAreaNotifier.hpp"

#include <proto/alib.h>

#include "MUI/Area.hpp"

namespace MUI
{
    DestAreaNotifier::DestAreaNotifier(const SourceNotifier &sourceNotifier, const Area &area)
      : DestNotifyNotifier(sourceNotifier, area)
    {
    }

    DestAreaNotifier &DestAreaNotifier::setDisabled(const bool disabled, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Disabled, (unsigned long)disabled);

        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setSelected(const bool selected, bool notify)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3,
                 notify ? MUIM_Set : MUIM_NoNotifySet, MUIA_Selected, (unsigned long)selected);

        return *this;
    }
}
