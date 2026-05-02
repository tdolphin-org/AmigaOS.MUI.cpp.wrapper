//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Volumelist.hpp"

#include <libraries/mui.h>
#include <proto/muimaster.h>

namespace MUI
{
    const std::string Volumelist::className = MUIC_Volumelist;

    VolumelistBuilder::VolumelistBuilder() { }
}
