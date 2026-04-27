//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Bitmap.hpp"

#include <libraries/mui.h>
#include <proto/muimaster.h>

namespace MUI
{
    const std::string Bitmap::className = MUIC_Bitmap;

    BitmapBuilder::BitmapBuilder() { }

    struct BitMap *Bitmap::getBitmap() const
    {
        return static_cast<struct BitMap *>(GetValueAsPtr(MUIA_Bitmap_Bitmap));
    }

    Bitmap &Bitmap::setBitmap(struct BitMap *pBitMap)
    {
        SetValue(MUIA_Bitmap_Bitmap, pBitMap);
        return *this;
    }

    long Bitmap::getHeight() const
    {
        return GetValueAsLong(MUIA_Bitmap_Height);
    }

    Bitmap &Bitmap::setHeight(const long height)
    {
        SetValue(MUIA_Bitmap_Height, height);
        return *this;
    }

    unsigned char *Bitmap::getMappingTable() const
    {
        return static_cast<unsigned char *>(GetValueAsPtr(MUIA_Bitmap_MappingTable));
    }

    Bitmap &Bitmap::setMappingTable(unsigned char *pMappingTable)
    {
        SetValue(MUIA_Bitmap_MappingTable, pMappingTable);
        return *this;
    }

    long Bitmap::getPrecision() const
    {
        return GetValueAsLong(MUIA_Bitmap_Precision);
    }

    Bitmap &Bitmap::setPrecision(const long precision)
    {
        SetValue(MUIA_Bitmap_Precision, precision);
        return *this;
    }

    struct BitMap *Bitmap::getRemappedBitmap() const
    {
        return static_cast<struct BitMap *>(GetValueAsPtr(MUIA_Bitmap_RemappedBitmap));
    }

    unsigned long *Bitmap::getSourceColors() const
    {
        return static_cast<unsigned long *>(GetValueAsPtr(MUIA_Bitmap_SourceColors));
    }

    Bitmap &Bitmap::setSourceColors(unsigned long *pSourceColors)
    {
        SetValue(MUIA_Bitmap_SourceColors, pSourceColors);
        return *this;
    }

    long Bitmap::getTransparent() const
    {
        return GetValueAsLong(MUIA_Bitmap_Transparent);
    }

    Bitmap &Bitmap::setTransparent(const long transparent)
    {
        SetValue(MUIA_Bitmap_Transparent, transparent);
        return *this;
    }

    long Bitmap::getWidth() const
    {
        return GetValueAsLong(MUIA_Bitmap_Width);
    }

    Bitmap &Bitmap::setWidth(const long width)
    {
        SetValue(MUIA_Bitmap_Width, width);
        return *this;
    }

#ifdef MUIA_Bitmap_Alpha
    unsigned long Bitmap::getAlpha() const
    {
        return GetValueAsULong(MUIA_Bitmap_Alpha);
    }

    Bitmap &Bitmap::setAlpha(const unsigned long alpha)
    {
        SetValue(MUIA_Bitmap_Alpha, alpha);
        return *this;
    }
#endif
}
