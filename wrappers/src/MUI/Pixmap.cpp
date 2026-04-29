//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Pixmap.hpp"

#ifdef MUIC_Pixmap

#include <proto/alib.h>

namespace MUI
{
    const std::string Pixmap::className = MUIC_Pixmap;

    unsigned long Pixmap::getAlpha() const
    {
        return GetValueAsLong(MUIA_Pixmap_Alpha);
    }

    const unsigned long *Pixmap::getCLUT() const
    {
        return reinterpret_cast<const unsigned long *>(GetValueAsPtr(MUIA_Pixmap_CLUT));
    }

    unsigned long Pixmap::getCLUTSize() const
    {
        return GetValueAsLong(MUIA_Pixmap_CLUTSize);
    }

    unsigned long Pixmap::getCompressedSize() const
    {
        return GetValueAsLong(MUIA_Pixmap_CompressedSize);
    }

    Pixmap_Compression Pixmap::getCompression() const
    {
        return static_cast<Pixmap_Compression>(GetValueAsLong(MUIA_Pixmap_Compression));
    }

    const void *Pixmap::getData() const
    {
        return GetValueAsPtr(MUIA_Pixmap_Data);
    }

    Pixmap_Format Pixmap::getFormat() const
    {
        return static_cast<Pixmap_Format>(GetValueAsLong(MUIA_Pixmap_Format));
    }

    long Pixmap::getHeight() const
    {
        return GetValueAsLong(MUIA_Pixmap_Height);
    }

    unsigned char Pixmap::getTransparencyThreshold() const
    {
        return static_cast<unsigned char>(GetValueAsLong(MUIA_Pixmap_TransparencyThreshold));
    }

    long Pixmap::getWidth() const
    {
        return GetValueAsLong(MUIA_Pixmap_Width);
    }

    const void *Pixmap::getUncompressedData() const
    {
        return GetValueAsPtr(MUIA_Pixmap_UncompressedData);
    }

    Pixmap &Pixmap::setAlpha(const unsigned long value)
    {
        SetValue(MUIA_Pixmap_Alpha, value);
        return *this;
    }

    Pixmap &Pixmap::setCLUT(const unsigned long *clut)
    {
        SetValue(MUIA_Pixmap_CLUT, clut);
        return *this;
    }

    Pixmap &Pixmap::setCLUTSize(const unsigned long value)
    {
        SetValue(MUIA_Pixmap_CLUTSize, value);
        return *this;
    }

    Pixmap &Pixmap::setCompressedSize(const unsigned long value)
    {
        SetValue(MUIA_Pixmap_CompressedSize, value);
        return *this;
    }

    Pixmap &Pixmap::setCompression(const Pixmap_Compression value)
    {
        SetValue(MUIA_Pixmap_Compression, static_cast<unsigned long>(value));
        return *this;
    }

    Pixmap &Pixmap::setCompression(const unsigned long value)
    {
        SetValue(MUIA_Pixmap_Compression, value);
        return *this;
    }

    Pixmap &Pixmap::setData(const void *data)
    {
        SetValue(MUIA_Pixmap_Data, data);
        return *this;
    }

    Pixmap &Pixmap::setFormat(const Pixmap_Format value)
    {
        SetValue(MUIA_Pixmap_Format, static_cast<unsigned long>(value));
        return *this;
    }

    Pixmap &Pixmap::setFormat(const unsigned long value)
    {
        SetValue(MUIA_Pixmap_Format, value);
        return *this;
    }

    Pixmap &Pixmap::setHeight(const long value)
    {
        SetValue(MUIA_Pixmap_Height, value);
        return *this;
    }

    Pixmap &Pixmap::setTransparencyThreshold(const unsigned char value)
    {
        SetValue(MUIA_Pixmap_TransparencyThreshold, static_cast<unsigned long>(value));
        return *this;
    }

    Pixmap &Pixmap::setWidth(const long value)
    {
        SetValue(MUIA_Pixmap_Width, value);
        return *this;
    }

    Pixmap &Pixmap::DrawSection(const long sx, const long sy, const long sw, const long sh, void *mri, const long dx, const long dy,
                                const unsigned long alpha)
    {
        DoMethod(muiObject(), MUIM_Pixmap_DrawSection, sx, sy, sw, sh, mri, dx, dy, alpha);
        return *this;
    }
}

#endif // MUIC_Pixmap
