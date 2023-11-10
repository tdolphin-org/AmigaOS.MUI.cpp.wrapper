//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "GadgetNotifier.hpp"

namespace MUI
{
    GadgetNotifier::GadgetNotifier(const Gadget &gadget)
      : mGadget(gadget)
      , AreaNotifier(gadget)
    {
    }
}
