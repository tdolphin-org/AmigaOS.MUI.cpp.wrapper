//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestNotifyNotifier.hpp"

namespace MUI
{
    class DestAreaNotifier : public DestNotifyNotifier
    {
        friend class SourceNotifier;

      protected:
        DestAreaNotifier(const SourceNotifier &sourceNotifier, const Area &area);

      public:
        DestAreaNotifier &setDisabled(const bool disabled);
        DestAreaNotifier &setSelected(const bool selected);
    };
}
