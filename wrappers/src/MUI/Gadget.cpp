//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Gadget.hpp"

namespace MUI
{
    const std::string Gadget::className = MUIC_Gadget;

    GadgetBuilder::GadgetBuilder() { }

    Gadget *Gadget::getGadget() const
    {
        return (Gadget *)GetValueAsPtr(MUIA_Gadget_Gadget);
    }
}
