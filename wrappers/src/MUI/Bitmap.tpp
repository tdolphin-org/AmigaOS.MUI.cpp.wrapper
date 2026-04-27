//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_BITMAP_TPP_INCLUDE
#error "Do not include Bitmap.tpp directly! It is included by Bitmap.hpp."
#endif

namespace MUI
{
    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagBitmap(struct BitMap *pBitMap)
    {
        this->PushTag(MUIA_Bitmap_Bitmap, pBitMap);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagHeight(const long height)
    {
        this->PushTag(MUIA_Bitmap_Height, height);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagMappingTable(unsigned char *pMappingTable)
    {
        this->PushTag(MUIA_Bitmap_MappingTable, pMappingTable);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagPrecision(const long precision)
    {
        this->PushTag(MUIA_Bitmap_Precision, precision);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagSourceColors(unsigned long *pSourceColors)
    {
        this->PushTag(MUIA_Bitmap_SourceColors, pSourceColors);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagTransparent(const long transparent)
    {
        this->PushTag(MUIA_Bitmap_Transparent, transparent);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagUseFriend(const bool useFriend)
    {
        this->PushTag(MUIA_Bitmap_UseFriend, useFriend);
        return (T &)*this;
    }

    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagWidth(const long width)
    {
        this->PushTag(MUIA_Bitmap_Width, width);
        return (T &)*this;
    }

#ifdef MUIA_Bitmap_Alpha
    template <typename T, typename U> T &BitmapBuilderTemplate<T, U>::tagAlpha(const unsigned long alpha)
    {
        this->PushTag(MUIA_Bitmap_Alpha, alpha);
        return (T &)*this;
    }
#endif
}
