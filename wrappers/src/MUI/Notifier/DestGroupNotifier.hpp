//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "DestAreaNotifier.hpp"

namespace MUI
{
    class DestGroupNotifier : public DestAreaNotifier
    {
        friend class SourceNotifier;

      protected:
        DestGroupNotifier(const SourceNotifier &sourceNotifier, const Group &group);
    };
}
