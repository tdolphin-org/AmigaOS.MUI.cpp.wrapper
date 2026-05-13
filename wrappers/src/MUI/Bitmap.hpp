//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#include <graphics/gfx.h>

namespace MUI
{
    /// @brief MUI Bitmap class wrapper.
    /// Allows including self-made image data in MUI applications.
    /// In its simplest form it just displays a given BitMap, but it also supports automatic
    /// color remapping to match the current display context and a transparent color.
    class Bitmap : public Area
    {
      public:
        explicit Bitmap(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Bitmap(const Root &root)
          : Area(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Bitmap_Bitmap ]
        /// Returns the pointer to the bitmap currently being displayed.
        struct BitMap *getBitmap() const;
        /// @brief [ @b MUIA_Bitmap_Bitmap ]
        /// Specifies a pointer to a struct BitMap to display.
        /// MUIA_Bitmap_Width and MUIA_Bitmap_Height must also be provided for correct display.
        Bitmap &setBitmap(struct BitMap *pBitMap);

        /// @brief [ @b MUIA_Bitmap_Height ]
        /// Returns the pixel height of the bitmap.
        long getHeight() const;
        /// @brief [ @b MUIA_Bitmap_Height ]
        /// Defines the pixel height of the bitmap. Usually combined with MUIA_FixHeight to make
        /// the object exactly as big as the bitmap.
        Bitmap &setHeight(const long height);

        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        /// Returns the pointer to the pen mapping table used for remapping.
        unsigned char *getMappingTable() const;
        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        /// Address of an array of UBYTEs, one for each color of the source BitMap.
        /// MUI will remap the BitMap according to the contents of the array.
        /// For context-sensitive remapping, prefer MUIA_Bitmap_SourceColors instead.
        Bitmap &setMappingTable(unsigned char *pMappingTable);

        /// @brief [ @b MUIA_Bitmap_Precision ]
        /// Returns the precision value used for remapping images.
        long getPrecision() const;
        /// @brief [ @b MUIA_Bitmap_Precision ]
        /// Specifies the precision value for remapping images.
        /// Use the same predefined values as for ObtainBestPen(), e.g. PRECISION_EXACT,
        /// PRECISION_IMAGE, PRECISION_ICON or PRECISION_GUI.
        Bitmap &setPrecision(const long precision);

        /// @brief [ @b MUIA_Bitmap_RemappedBitmap ]
        /// Returns a pointer to the remapped bitmap. Valid only between MUIM_Setup and MUIM_Cleanup.
        struct BitMap *getRemappedBitmap() const;

        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        /// Returns the pointer to the source color palette used for remapping.
        unsigned long *getSourceColors() const;
        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        /// Defines the color palette of the source BitMap as an array of ULONGs,
        /// three entries per color (32 bits per gun). If specified, MUI will try to locate these colors
        /// on the current screen and remap the BitMap accordingly.
        Bitmap &setSourceColors(unsigned long *pSourceColors);

        /// @brief [ @b MUIA_Bitmap_Transparent ]
        /// Returns the color index that is considered transparent (currently only 0 is supported).
        long getTransparent() const;
        /// @brief [ @b MUIA_Bitmap_Transparent ]
        /// If specified, MUI will consider this color of the BitMap to be transparent.
        /// A mask plane will be generated for blitting so the background shines through.
        /// Currently, only color index 0 is supported.
        Bitmap &setTransparent(const long transparent);

        /// @brief [ @b MUIA_Bitmap_Width ]
        /// Returns the pixel width of the bitmap.
        long getWidth() const;
        /// @brief [ @b MUIA_Bitmap_Width ]
        /// Defines the pixel width of the bitmap. Usually combined with MUIA_FixWidth to make
        /// the object exactly as big as the bitmap.
        Bitmap &setWidth(const long width);

#ifdef MUIA_Bitmap_Alpha
        /// @brief [ @b MUIA_Bitmap_Alpha ]
        /// Returns the global alpha blending intensity applied to the bitmap.
        unsigned long getAlpha() const;
        /// @brief [ @b MUIA_Bitmap_Alpha ]
        /// Sets the alpha blending intensity for the bitmap. The BitMap must be in 32-bit ARGB format.
        /// Specify 0xffffffff for full opacity. Alpha blitting is not supported on CLUT screens.
        Bitmap &setAlpha(const unsigned long alpha);
#endif
    };

    template <typename T, typename U> class BitmapBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        BitmapBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Bitmap)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Bitmap_Bitmap ]
        /// Specifies a pointer to a struct BitMap. tagWidth() and tagHeight() are also required.
        T &tagBitmap(struct BitMap *pBitMap);
        /// @brief [ @b MUIA_Bitmap_Height ]
        /// Defines the pixel height of the bitmap. Usually combined with MUIA_FixHeight.
        T &tagHeight(const long height);
        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        /// Address of an array of UBYTEs, one for each color of the source BitMap, for pen remapping.
        /// For context-sensitive remapping, prefer tagSourceColors() instead.
        T &tagMappingTable(unsigned char *pMappingTable);
        /// @brief [ @b MUIA_Bitmap_Precision ]
        /// Precision for remapping; use PRECISION_EXACT, PRECISION_IMAGE, PRECISION_ICON or PRECISION_GUI.
        T &tagPrecision(const long precision);
        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        /// Color palette of the source BitMap as an array of ULONGs (three entries per color, 32 bits per gun).
        T &tagSourceColors(unsigned long *pSourceColors);
        /// @brief [ @b MUIA_Bitmap_Transparent ]
        /// Color index to make transparent (background shines through). Currently only 0 is supported.
        T &tagTransparent(const long transparent);
        /// @brief [ @b MUIA_Bitmap_UseFriend ]
        /// Makes MUI allocate the remapped bitmap as a "friend" bitmap of the current screen bitmap
        /// for fastest possible displaying.
        T &tagUseFriend(const bool useFriend);
        /// @brief [ @b MUIA_Bitmap_Width ]
        /// Defines the pixel width of the bitmap. Usually combined with MUIA_FixWidth.
        T &tagWidth(const long width);
#ifdef MUIA_Bitmap_Alpha
        /// @brief [ @b MUIA_Bitmap_Alpha ]
        /// Alpha blending intensity for the bitmap (32-bit ARGB format required). 0xffffffff = fully opaque.
        T &tagAlpha(const unsigned long alpha);
#endif
    };

    class BitmapBuilder : public BitmapBuilderTemplate<BitmapBuilder, Bitmap>
    {
      public:
        BitmapBuilder();
    };
}

#define MUI_BITMAP_TPP_INCLUDE
#include "Bitmap.tpp"
#undef MUI_BITMAP_TPP_INCLUDE
