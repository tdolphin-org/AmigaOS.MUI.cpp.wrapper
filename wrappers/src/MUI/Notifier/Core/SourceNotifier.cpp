//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "SourceNotifier.hpp"

namespace MUI
{
    SourceNotifierRoot::SourceNotifierRoot(const Root &root, const unsigned long attribute, const AOS::ValueObject &triggerValue)
      : NotifierObject(root, attribute, triggerValue)
    {
    }

    DestApplicationNotifier SourceNotifierRoot::notifyObject(const Application &application)
    {
        return DestApplicationNotifier(*this, application);
    }

    DestAreaNotifier SourceNotifierRoot::notifyObject(const Area &area)
    {
        return DestAreaNotifier(*this, area);
    }

    DestCycleNotifier SourceNotifierRoot::notifyObject(const Cycle &cycle)
    {
        return DestCycleNotifier(*this, cycle);
    }

    DestGroupNotifier SourceNotifierRoot::notifyObject(const Group &group)
    {
        return DestGroupNotifier(*this, group);
    }

    DestListNotifier SourceNotifierRoot::notifyObject(const List &list)
    {
        return DestListNotifier(*this, list);
    }

    DestNotifyNotifier SourceNotifierRoot::notifyObject(const Notify &notify)
    {
        return DestNotifyNotifier(*this, notify);
    }

    DestWindowNotifier SourceNotifierRoot::notifyObject(const Window &window)
    {
        return DestWindowNotifier(*this, window);
    }
}
