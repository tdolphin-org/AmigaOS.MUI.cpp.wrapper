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

    DestAreaNotifier &DestAreaNotifier::setDisabled(const bool disabled)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3, MUIM_Set, MUIA_Disabled,
                 (ULONG)disabled);

        return *this;
    }

    DestAreaNotifier &DestAreaNotifier::setSelected(const bool selected)
    {
        DoMethod(muiSourceObject(), MUIM_Notify, getAttribute(), getTrigValue(), mObject.muiObject(), 3, MUIM_Set, MUIA_Selected,
                 (ULONG)selected);

        return *this;
    }
}
