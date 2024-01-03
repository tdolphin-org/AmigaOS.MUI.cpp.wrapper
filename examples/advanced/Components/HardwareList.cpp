//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2024 TDolphin
//

#include "HardwareList.hpp"

const char *hardwareItems[] = { "Amiga 1000", "Amiga 500", "Amiga 2000", "Amiga 3000", "Amiga 600", "Amiga 1200", "Amiga 4000", nullptr };

namespace Components
{
    HardwareList::HardwareList()
      : mComponent(MUI::ListBuilder().tagFrame(MUI::Frame::ReadList).tagSourceArray(hardwareItems).tagWeight(50).object())
    {
        mComponent.InsertSingleBottom("Walker");
    }
}
