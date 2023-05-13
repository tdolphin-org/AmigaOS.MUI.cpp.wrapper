//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "SourceNotifier.hpp"

#include "../DestAreaNotifier.hpp"
#include "../DestGroupNotifier.hpp"
#include "../DestNotifyNotifier.hpp"

namespace MUI
{
    SourceNotifier::SourceNotifier(const Root &root, unsigned long attribute, unsigned long trigValue)
      : mObject(root)
      , mAttribute(attribute)
      , mTrigValue(trigValue)
    {
    }

    DestNotifyNotifier SourceNotifier::destObject(const Notify &notify)
    {
        return DestNotifyNotifier(*this, notify);
    }

    DestAreaNotifier SourceNotifier::destObject(const Area &area)
    {
        return DestAreaNotifier(*this, area);
    }

    DestGroupNotifier SourceNotifier::destObject(const Group &group)
    {
        return DestGroupNotifier(*this, group);
    }
}
