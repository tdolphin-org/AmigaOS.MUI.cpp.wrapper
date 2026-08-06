//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "mui.hpp"

// detect MUI Version
#ifdef __MORPHOS__
// MorphOS has own MUI 5.0

#ifdef DEBUG
#pragma message("MUI 5.0 for MorphOS detected")
#endif

#define MOS_MUI_VERSION_5
#elif defined(__AROS__)
// AROS Zune - MUI 3.x-compatible API (muimaster.library)
//
// Zune is treated like MUI 3.8 for the existing guards: features guarded by
// AOS_MUI_VERSION_3_8 are available, MUI 5.x-only guards (*_MUI_VERSION_5)
// stay disabled. Verified against the AROS SDK (e.g. struct MUI_RGBcolor).

#ifdef DEBUG
#pragma message("AROS Zune (MUI 3.x compatible) detected")
#endif

#define AROS_ZUNE_VERSION
#define AOS_MUI_VERSION_3_8 // Zune exposes the MUI 3.x feature set
#elif defined(MUIMASTER_VLATEST) && (MUIMASTER_VLATEST == 19)
// MUI 3.8 for amigaos3

#ifdef DEBUG
#pragma message("MUI 3.8 detected for AmigaOS3 detected")
#endif

#define AOS_MUI_VERSION_3_8
#elif defined(MUIMASTER_VLATEST) && (MUIMASTER_VLATEST == 20)
// MUI 5.0 for amigaos3

#ifdef DEBUG
#pragma message("MUI 5.0 for AmigaOS3 detected")
#endif

#define AOS_MUI_VERSION_5 // MUIMASTER_VLATEST == 20
#else
#error "Unknown MUI version, please define MUIMASTER_VLATEST"
#endif
// end of MUI version detection
