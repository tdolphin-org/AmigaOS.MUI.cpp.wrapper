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

        /// @brief [ @b MUIA_Pixmap_Alpha ] This attribute specifies an additional alpha value to
        /// be applied to the image data being drawn. The default value is 0xffffffff which will draw
        /// the image with full intensity. Alpha blitting won't work on CLUT screens or with CLUT
        /// image data.
        unsigned long getAlpha() const;
        /// @brief [ @b MUIA_Pixmap_CLUT ] Define the color map to be used for CLUT8 raw image data.
        /// If no color map is given an internal default color map will be used instead.
        const unsigned long *getCLUT() const;
        /// @brief [ @b MUIA_Pixmap_CLUTSize ] Define the number of colors in the color map given
        /// by MUIA_Pixmap_CLUT. Defaults to 256.
        unsigned long getCLUTSize() const;
        /// @brief [ @b MUIA_Pixmap_CompressedSize ] This attribute specifies the size of the
        /// compressed raw image data. It is only required if the raw image data are compressed at all.
        unsigned long getCompressedSize() const;
        /// @brief [ @b MUIA_Pixmap_Compression ] This attribute specifies the compression method
        /// being used for the raw image data. Defaults to MUIV_Pixmap_Compression_None.
        Pixmap_Compression getCompression() const;
        /// @brief [ @b MUIA_Pixmap_Data ] This attribute specifies a pointer to an array of the raw
        /// image data. You also need to specify MUIA_Pixmap_Width, MUIA_Pixmap_Height and
        /// MUIA_Pixmap_Format. For color mapped data the palette must be given with MUIA_Pixmap_CLUT.
        const void *getData() const;
        /// @brief [ @b MUIA_Pixmap_Format ] This attribute specifies the format of the raw image
        /// data. It is possible to use color mapped (CLUT8), 24bit RGB and 32bit ARGB image data.
        /// For CLUT8 images the palette can be specified with MUIA_Pixmap_CLUT.
        Pixmap_Format getFormat() const;
        /// @brief [ @b MUIA_Pixmap_Height ] Define the pixel height of the raw image data.
        long getHeight() const;
        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ] Define the transparency threshold when
        /// dithering ARGB data. Pixels with an alpha value larger than the threshold will be treated
        /// as non-transparent. No effect on hi/truecolor screens. Defaults to 0x7f (50%).
        unsigned char getTransparencyThreshold() const;
        /// @brief [ @b MUIA_Pixmap_Width ] Define the pixel width of the raw image data.
        long getWidth() const;
        /// @brief [ @b MUIA_Pixmap_UncompressedData ] A pointer to the uncompressed data is
        /// returned, or NULL if decompression failed. The returned data are strictly read-only!
        const void *getUncompressedData() const;

        /// @brief [ @b MUIA_Pixmap_Alpha ] This attribute specifies an additional alpha value to
        /// be applied to the image data being drawn. The default value is 0xffffffff (full intensity).
        Pixmap &setAlpha(unsigned long value);
        /// @brief [ @b MUIA_Pixmap_CLUT ] Define the color map to be used for CLUT8 raw image data.
        /// If no color map is given an internal default color map will be used instead.
        Pixmap &setCLUT(const unsigned long *clut);
        /// @brief [ @b MUIA_Pixmap_CLUTSize ] Define the number of colors in the color map given
        /// by MUIA_Pixmap_CLUT. Defaults to 256.
        Pixmap &setCLUTSize(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_CompressedSize ] This attribute specifies the size of the
        /// compressed raw image data. It is only required if the raw image data are compressed at all.
        Pixmap &setCompressedSize(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Compression ] This attribute specifies the compression method
        /// being used for the raw image data. Defaults to MUIV_Pixmap_Compression_None.
        Pixmap &setCompression(const Pixmap_Compression value);
        /// @brief [ @b MUIA_Pixmap_Compression ] This attribute specifies the compression method
        /// being used for the raw image data (raw value overload).
        Pixmap &setCompression(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Data ] This attribute specifies a pointer to an array of the raw
        /// image data. Also specify MUIA_Pixmap_Width, MUIA_Pixmap_Height and MUIA_Pixmap_Format.
        Pixmap &setData(const void *data);
        /// @brief [ @b MUIA_Pixmap_Format ] This attribute specifies the format of the raw image
        /// data. It is possible to use color mapped (CLUT8), 24bit RGB and 32bit ARGB image data.
        Pixmap &setFormat(const Pixmap_Format value);
        /// @brief [ @b MUIA_Pixmap_Format ] This attribute specifies the format of the raw image
        /// data (raw value overload).
        Pixmap &setFormat(const unsigned long value);
        /// @brief [ @b MUIA_Pixmap_Height ] Define the pixel height of the raw image data.
        Pixmap &setHeight(const long value);
        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ] Define the transparency threshold when
        /// dithering ARGB data. Pixels with an alpha value larger than the threshold will be treated
        /// as non-transparent. No effect on hi/truecolor screens. Defaults to 0x7f (50%).
        Pixmap &setTransparencyThreshold(const unsigned char value);
        /// @brief [ @b MUIA_Pixmap_Width ] Define the pixel width of the raw image data.
        Pixmap &setWidth(const long value);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Pixmap_DrawSection ] Call this method instead of MUI_Redraw() to draw
        /// just a section of the complete pixmap with a definite alpha transparency which might be
        /// different from the globally set alpha transparency.
        /// @param sx Source left coordinate of the section
        /// @param sy Source top coordinate of the section
        /// @param sw Source width of the section
        /// @param sh Source height of the section
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

        /// @brief [ @b MUIA_Pixmap_Alpha ] Additional alpha value to be applied to the image data
        /// being drawn. The default value is 0xffffffff (full intensity).
        T &tagAlpha(const unsigned long alpha);

        /// @brief [ @b MUIA_Pixmap_CLUT ] Color map to be used for CLUT8 raw image data. If not
        /// given, an internal default color map will be used instead.
        T &tagCLUT(const unsigned long *clut);

        /// @brief [ @b MUIA_Pixmap_CLUTSize ] Number of colors in the color map given by
        /// MUIA_Pixmap_CLUT. Defaults to 256.
        T &tagCLUTSize(const unsigned long clutSize);

        /// @brief [ @b MUIA_Pixmap_CompressedSize ] Size of the compressed raw image data. Only
        /// required if the raw image data are compressed at all.
        T &tagCompressedSize(const unsigned long compressedSize);

        /// @brief [ @b MUIA_Pixmap_Compression ] Compression method being used for the raw image
        /// data. Defaults to MUIV_Pixmap_Compression_None (uncompressed data).
        T &tagCompression(const Pixmap_Compression compression);

        /// @brief [ @b MUIA_Pixmap_Data ] Pointer to an array of the raw image data. Also specify
        /// MUIA_Pixmap_Width, MUIA_Pixmap_Height and MUIA_Pixmap_Format.
        T &tagData(const void *data);

        /// @brief [ @b MUIA_Pixmap_Format ] Format of the raw image data: color mapped (CLUT8),
        /// 24bit RGB or 32bit ARGB. For CLUT8 images specify the palette with MUIA_Pixmap_CLUT.
        T &tagFormat(const Pixmap_Format format);

        /// @brief [ @b MUIA_Pixmap_Height ] Pixel height of the raw image data.
        T &tagHeight(const long height);

        /// @brief [ @b MUIA_Pixmap_TransparencyThreshold ] Transparency threshold when dithering
        /// ARGB data. Pixels with alpha larger than the threshold are non-transparent. Defaults to
        /// 0x7f (50%). No effect on hi/truecolor screens.
        T &tagTransparencyThreshold(const unsigned char transparencyThreshold);

        /// @brief [ @b MUIA_Pixmap_Width ] Pixel width of the raw image data.
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
