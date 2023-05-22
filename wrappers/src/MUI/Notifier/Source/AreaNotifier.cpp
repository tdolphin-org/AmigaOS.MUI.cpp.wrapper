//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "AreaNotifier.hpp"

namespace MUI
{
    AreaNotifier::AreaNotifier(const Area &area)
      : NotifyNotifier(area)
      , mArea(area)
    {
    }

    SourceNotifier<Area, DestAreaNotifier> AreaNotifier::onSelected(const bool selected)
    {
        return SourceNotifier<Area, DestAreaNotifier>(mArea, MUIA_Selected, selected);
    }

    SourceNotifier<Area, DestAreaNotifier> AreaNotifier::onPressed(const bool pressed)
    {
        return SourceNotifier<Area, DestAreaNotifier>(mArea, MUIA_Pressed, pressed);
    }
}
