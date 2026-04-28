//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#ifdef AOS_MUI_VERSION_5
namespace MUI
{
    namespace ValueTypes
    {
        /// @brief Compression method for raw image data (MUIA_Pixmap_Compression)
        enum class Pixmap_Compression : unsigned long
        {
            None = MUIV_Pixmap_Compression_None,
            RLE = MUIV_Pixmap_Compression_RLE,
            BZip2 = MUIV_Pixmap_Compression_BZip2,
            Z = MUIV_Pixmap_Compression_Z,
            LZMA = MUIV_Pixmap_Compression_LZMA
        };
    }
}
#endif // AOS_MUI_VERSION_5
