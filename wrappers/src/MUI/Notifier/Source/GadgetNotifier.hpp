//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "AreaNotifier.hpp"
#include "MUI/Gadget.hpp"

namespace MUI
{
    template <typename T = Gadget, typename U = DestGadgetNotifier> class GadgetNotifier : public AreaNotifier<T, U>
    {
      public:
        GadgetNotifier() = delete;
        GadgetNotifier(const T &gadget)
          : AreaNotifier<T, U>(gadget)
        {
        }
    };
}
