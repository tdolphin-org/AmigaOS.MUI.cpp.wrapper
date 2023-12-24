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
    template <typename T = DestGadgetNotifier> class GadgetNotifier : public AreaNotifier<T>
    {
        Gadget mGadget;

      public:
        GadgetNotifier() = delete;
        GadgetNotifier(const Gadget &gadget)
          : AreaNotifier<T>(gadget)
          , mGadget(gadget)
        {
        }
    };
}
