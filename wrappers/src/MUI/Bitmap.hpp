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
    /// Displays a raw AmigaOS bitmap. You supply the bitmap pointer, its dimensions, and an optional
    /// color mapping table. MUI handles all rendering and remapping to the current screen's color space.
    class Bitmap : public Area
    {
      public:
        explicit Bitmap(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Bitmap_Bitmap ]
        /// Returns the pointer to the bitmap currently being displayed.
        struct BitMap *getBitmap() const;
        /// @brief [ @b MUIA_Bitmap_Bitmap ]
        /// Sets the bitmap to display. The bitmap must remain valid while the object is alive.
        Bitmap &setBitmap(struct BitMap *pBitMap);

        /// @brief [ @b MUIA_Bitmap_Height ]
        /// Returns the height of the bitmap in pixels.
        long getHeight() const;
        /// @brief [ @b MUIA_Bitmap_Height ]
        /// Sets the height of the bitmap in pixels. Must be specified together with Width.
        Bitmap &setHeight(const long height);

        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        /// Returns the pointer to the current pen mapping table.
        unsigned char *getMappingTable() const;
        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        /// Sets a pen mapping table used to remap bitmap pen indices to actual screen pens.
        /// The array must have 256 entries and remain valid while the object is alive.
        Bitmap &setMappingTable(unsigned char *pMappingTable);

        /// @brief [ @b MUIA_Bitmap_Precision ]
        /// Returns the current color-matching precision used during remapping.
        long getPrecision() const;
        /// @brief [ @b MUIA_Bitmap_Precision ]
        /// Sets the color-matching precision when remapping bitmap colors to the current screen palette.
        /// Use one of the @c PRECISION_* values from @c graphics/rastport.h. Default is @c PRECISION_IMAGE.
        Bitmap &setPrecision(const long precision);

        /// @brief [ @b MUIA_Bitmap_RemappedBitmap ]
        /// Returns a pointer to the internally remapped bitmap. The returned bitmap is owned by MUI;
        /// do not free it. Only valid after the object has been set up and remapping has been performed.
        struct BitMap *getRemappedBitmap() const;

        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        /// Returns the pointer to the source color table used for remapping.
        unsigned long *getSourceColors() const;
        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        /// Sets the source color table for remapping. The array must contain exactly
        /// @c (number_of_pens * 3) ULONG values (RGB triplets, each 0..0xFFFFFFFF) and remain valid
        /// while the object is alive.
        Bitmap &setSourceColors(unsigned long *pSourceColors);

        /// @brief [ @b MUIA_Bitmap_Transparent ]
        /// Returns the index of the transparent pen (or -1 if transparency is disabled).
        long getTransparent() const;
        /// @brief [ @b MUIA_Bitmap_Transparent ]
        /// Sets the pen index used as transparent color. Set to -1 to disable transparency.
        Bitmap &setTransparent(const long transparent);

        /// @brief [ @b MUIA_Bitmap_Width ]
        /// Returns the width of the bitmap in pixels.
        long getWidth() const;
        /// @brief [ @b MUIA_Bitmap_Width ]
        /// Sets the width of the bitmap in pixels. Must be specified together with Height.
        Bitmap &setWidth(const long width);

#ifdef MUIA_Bitmap_Alpha
        /// @brief [ @b MUIA_Bitmap_Alpha ]
        /// Returns the global alpha value applied to the bitmap (0 = fully transparent, 0xFFFFFFFF = fully opaque).
        unsigned long getAlpha() const;
        /// @brief [ @b MUIA_Bitmap_Alpha ]
        /// Sets the global alpha blending value for the bitmap. Requires MUI 5 / V20.
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
        T &tagBitmap(struct BitMap *pBitMap);
        /// @brief [ @b MUIA_Bitmap_Height ]
        T &tagHeight(const long height);
        /// @brief [ @b MUIA_Bitmap_MappingTable ]
        T &tagMappingTable(unsigned char *pMappingTable);
        /// @brief [ @b MUIA_Bitmap_Precision ]
        T &tagPrecision(const long precision);
        /// @brief [ @b MUIA_Bitmap_SourceColors ]
        T &tagSourceColors(unsigned long *pSourceColors);
        /// @brief [ @b MUIA_Bitmap_Transparent ]
        T &tagTransparent(const long transparent);
        /// @brief [ @b MUIA_Bitmap_UseFriend ]
        /// Specifies whether MUI should allocate the remapped bitmap as a "friend" bitmap
        /// of the current screen bitmap for optimized blitting. Default is false.
        T &tagUseFriend(const bool useFriend);
        /// @brief [ @b MUIA_Bitmap_Width ]
        T &tagWidth(const long width);
#ifdef MUIA_Bitmap_Alpha
        /// @brief [ @b MUIA_Bitmap_Alpha ]
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
