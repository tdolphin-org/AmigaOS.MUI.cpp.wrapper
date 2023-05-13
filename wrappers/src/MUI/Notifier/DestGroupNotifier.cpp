//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "DestGroupNotifier.hpp"

#include "MUI/Group.hpp"

namespace MUI
{
    DestGroupNotifier::DestGroupNotifier(const SourceNotifier &sourceNotifier, const Group &group)
      : DestAreaNotifier(sourceNotifier, group)
    {
    }
}
