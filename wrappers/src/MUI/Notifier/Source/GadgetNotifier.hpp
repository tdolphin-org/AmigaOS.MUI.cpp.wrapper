//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/Gadget.hpp"

namespace MUI
{
    class GadgetNotifier : public AreaNotifier
    {
        Gadget mGadget;

      public:
        GadgetNotifier() = delete;
        GadgetNotifier(const Gadget &gadget);
    };
}
