//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "SourceNotifier.hpp"

#include "../DestApplicationNotifier.hpp"
#include "../DestAreaNotifier.hpp"
#include "../DestGroupNotifier.hpp"
#include "../DestNotifyNotifier.hpp"

namespace MUI
{
    SourceNotifier::SourceNotifier(const Root &root, const unsigned long attribute, const void *trigValue)
      : NotifierObject(root, attribute, trigValue)
    {
    }

    SourceNotifier::SourceNotifier(const Root &root, const unsigned long attribute, const unsigned long trigValue)
      : NotifierObject(root, attribute, trigValue)
    {
    }

    SourceNotifier::SourceNotifier(const Root &root, const unsigned long attribute, const long trigValue)
      : NotifierObject(root, attribute, trigValue)
    {
    }

    SourceNotifier::SourceNotifier(const Root &root, const unsigned long attribute, const void **trigValue)
      : NotifierObject(root, attribute, trigValue)
    {
    }

    SourceNotifier::SourceNotifier(const Root &root, const unsigned long attribute, const bool trigValue)
      : NotifierObject(root, attribute, (unsigned long)trigValue)
    {
    }

    DestNotifyNotifier SourceNotifier::destObject(const Notify &notify)
    {
        return DestNotifyNotifier((NotifierObject &)*this, notify);
    }

    DestApplicationNotifier SourceNotifier::destObject(const Application &application)
    {
        return DestApplicationNotifier((NotifierObject &)*this, application);
    }

    DestAreaNotifier SourceNotifier::destObject(const Area &area)
    {
        return DestAreaNotifier((NotifierObject &)*this, area);
    }

    DestGroupNotifier SourceNotifier::destObject(const Group &group)
    {
        return DestGroupNotifier((NotifierObject &)*this, group);
    }
}
