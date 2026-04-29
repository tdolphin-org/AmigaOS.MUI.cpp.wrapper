//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#ifdef MUIA_Pixmap_Format

namespace MUI
{
    /// @brief Format of raw image data (MUIA_Pixmap_Format)
    enum class Pixmap_Format : unsigned long
    {
        CLUT8 = MUIV_Pixmap_Format_CLUT8,
        RGB24 = MUIV_Pixmap_Format_RGB24,
        ARGB32 = MUIV_Pixmap_Format_ARGB32
    };
}

#endif // MUIA_Pixmap_Format
