//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

#ifdef MUIC_Pixmap

#include "ValueTypes/Pixmap/Compression.hpp"
#include "ValueTypes/Pixmap/Format.hpp"

namespace MUI
{

    /// @brief The Pixmap class allows including self-made inlined image data in MUI applications.
    /// In its most simple usage, Pixmap class just displays a given inlined array of raw image date of a certain type.
    class Pixmap : public Area
    {
      public:
        explicit Pixmap(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Pixmap(const Root &root)
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

        /// @brief [ @b MUIA_Pixmap_Alpha ]
        /// Specifies an additional alpha value to be applied to the image data being drawn.
        unsigned long getAlpha() const;
        /// @brief [ @b MUIA_Pixmap_CLUT ]
        /// Define the color map to be used for CLUT8 raw image data.
        const unsigned long *getCLUT() const;
        /// @brief [ @b MUIA_Pixmap_CLUTSize ]
        /// Define the number of colors in the color map.
        unsigned long getCLUTSize() const;
        /// @brief [ @b MUIA_Pixmap_CompressedSize ]
        /// Specifies the size of the compressed raw image data.
        unsigned long getCompressedSize() const;
        /// @brief [ @b MUIA_Pixmap_Compression ]
        /// Specifies the compression method being used for the raw image data.
        Pixmap_Compression getCompression() const;
        /// @brief [ @b MUIA_Pixmap_Data ]
        /// Specifies a pointer to an array of the raw image data.
        const void *getData() const;
        /// @brief [ @b MUIA_Pixmap_Format ]
        /// Specifies the format of the raw image data.
        Pixmap_Format getFormat() const;
        /// @brief [ @b MUIA_Pixmap_Height ]
        /// Define the pixel height of the raw image data.
        long getHeight() const;
        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ]
        /// Define the transparency threshold when dithering ARGB data.
        unsigned char getTransparencyThreshold() const;
        /// @brief [ @b MUIA_Pixmap_Width ]
        /// Define the pixel width of the raw image data.
        long getWidth() const;
        /// @brief [ @b MUIA_Pixmap_UncompressedData ]
        /// A pointer to the uncompressed data is returned, or NULL if decompression failed. The returned data are strictly read-only!
        const void *getUncompressedData() const;

        /// @brief [ @b MUIA_Pixmap_Alpha ]
        /// Set additional alpha value to be applied to the image data being drawn.
        Pixmap &setAlpha(unsigned long value);
        /// @brief [ @b MUIA_Pixmap_CLUT ]
        /// Set the color map to be used for CLUT8 raw image data.
        Pixmap &setCLUT(const unsigned long *clut);
        /// @brief [ @b MUIA_Pixmap_CLUTSize ]
        /// Set the number of colors in the color map.
        Pixmap &setCLUTSize(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_CompressedSize ]
        /// Set the size of the compressed raw image data.
        Pixmap &setCompressedSize(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Compression ]
        /// Set the compression method being used for the raw image data.
        Pixmap &setCompression(const Pixmap_Compression value);
        /// @brief [ @b MUIA_Pixmap_Compression ]
        /// Set the compression method using raw value.
        Pixmap &setCompression(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Data ]
        /// Set pointer to an array of the raw image data.
        Pixmap &setData(const void *data);
        /// @brief [ @b MUIA_Pixmap_Format ]
        /// Set the format of the raw image data.
        Pixmap &setFormat(const Pixmap_Format value);
        /// @brief [ @b MUIA_Pixmap_Format ]
        /// Set the format using raw value.
        Pixmap &setFormat(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Height ]
        /// Set the pixel height of the raw image data.
        Pixmap &setHeight(const long value);
        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ]
        /// Set the transparency threshold when dithering ARGB data.
        Pixmap &setTransparencyThreshold(const unsigned char value);
        /// @brief [ @b MUIA_Pixmap_Width ]
        /// Set the pixel width of the raw image data.
        Pixmap &setWidth(const long value);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Pixmap_DrawSection ]
        /// Draw just a section of the complete pixmap with a definite alpha transparency.
        /// @param sx Source left coordinate
        /// @param sy Source top coordinate
        /// @param sw Source width
        /// @param sh Source height
        /// @param mri MUI_RenderInfo structure to draw the pixmap section to
        /// @param dx Destination left coordinate
        /// @param dy Destination top coordinate
        /// @param alpha Transparency
        Pixmap &DrawSection(const long sx, const long sy, const long sw, const long sh, void *mri, const long dx, const long dy,
                            const unsigned long alpha);
    };

    template <typename T, typename U> class PixmapBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        PixmapBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Pixmap)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Pixmap_Alpha ]
        T &tagAlpha(const unsigned long alpha);

        /// @brief [ @b MUIA_Pixmap_CLUT ]
        T &tagCLUT(const unsigned long *clut);

        /// @brief [ @b MUIA_Pixmap_CLUTSize ]
        T &tagCLUTSize(const unsigned long clutSize);

        /// @brief [ @b MUIA_Pixmap_CompressedSize ]
        T &tagCompressedSize(const unsigned long compressedSize);

        /// @brief [ @b MUIA_Pixmap_Compression ]
        T &tagCompression(const Pixmap_Compression compression);

        /// @brief [ @b MUIA_Pixmap_Data ]
        T &tagData(const void *data);

        /// @brief [ @b MUIA_Pixmap_Format ]
        T &tagFormat(const Pixmap_Format format);

        /// @brief [ @b MUIA_Pixmap_Height ]
        T &tagHeight(const long height);

        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ]
        T &tagTransparencyThreshold(const unsigned char transparencyThreshold);

        /// @brief [ @b MUIA_Pixmap_Width ]
        T &tagWidth(const long width);
    };

    class PixmapBuilder : public PixmapBuilderTemplate<PixmapBuilder, Pixmap>
    {
      public:
        PixmapBuilder();
    };
} // namespace MUI

#define MUI_PIXMAP_TPP_INCLUDE
#include "Pixmap.tpp"
#undef MUI_PIXMAP_TPP_INCLUDE

#endif // MUIC_Pixmap
