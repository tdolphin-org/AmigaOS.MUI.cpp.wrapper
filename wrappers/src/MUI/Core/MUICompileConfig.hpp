//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include <libraries/mui.h>

// detect MUI Version
#ifdef __MORPHOS__
// MorphOS has own MUI 5.0

#ifdef DEBUG
#pragma message("MUI 5.0 for MorphOS detected")
#endif

#define MOS_MUI_VERSION_5
#elif defined(MUIMASTER_VMIN) && defined(MUIMASTER_VLATEST) && (MUIMASTER_VMIN == 19) && (MUIMASTER_VLATEST == 20)
// MUI 3.8 for amigaos3

#ifdef DEBUG
#pragma message("MUI 3.8 detected for AmigaOS3 detected")
#endif

#define AOS_MUI_VERSION_3_8
#elif defined(MUIMASTER_VMIN) && defined(MUIMASTER_VLATEST) && (MUIMASTER_VMIN == 11) && (MUIMASTER_VLATEST == 19)
// MUI 5.0 for amigaos3

#ifdef DEBUG
#pragma message("MUI 5.0 for AmigaOS3 detected")
#endif

#define AOS_MUI_VERSION_5 // MUIMASTER_VMIN == 20 && MUIMASTER_VLATEST == 20
#else
#error "Unknown MUI version, please define MUIMASTER_VMIN and MUIMASTER_VLATEST"
#endif
// end of MUI version detection
