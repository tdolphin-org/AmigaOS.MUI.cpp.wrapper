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

    DestApplicationNotifier SourceNotifierRoot::destObject(const Application &application)
    {
        return DestApplicationNotifier(*this, application);
    }

    DestAreaNotifier SourceNotifierRoot::destObject(const Area &area)
    {
        return DestAreaNotifier(*this, area);
    }

    DestCycleNotifier SourceNotifierRoot::destObject(const Cycle &cycle)
    {
        return DestCycleNotifier(*this, cycle);
    }

    DestGroupNotifier SourceNotifierRoot::destObject(const Group &group)
    {
        return DestGroupNotifier(*this, group);
    }

    DestListNotifier SourceNotifierRoot::destObject(const List &list)
    {
        return DestListNotifier(*this, list);
    }

    DestNotifyNotifier SourceNotifierRoot::destObject(const Notify &notify)
    {
        return DestNotifyNotifier(*this, notify);
    }

    DestWindowNotifier SourceNotifierRoot::destObject(const Window &window)
    {
        return DestWindowNotifier(*this, window);
    }
}
