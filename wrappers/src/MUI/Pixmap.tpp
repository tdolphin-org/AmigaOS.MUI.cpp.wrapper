//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PIXMAP_TPP_INCLUDE
#error "Pixmap.tpp should only be included by Pixmap.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagAlpha(const unsigned long alpha)
    {
        this->PushTag(MUIA_Pixmap_Alpha, alpha);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagCLUT(const unsigned long *clut)
    {
        this->PushTag(MUIA_Pixmap_CLUT, clut);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagCLUTSize(const unsigned long clutSize)
    {
        this->PushTag(MUIA_Pixmap_CLUTSize, clutSize);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagCompressedSize(const unsigned long compressedSize)
    {
        this->PushTag(MUIA_Pixmap_CompressedSize, compressedSize);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagCompression(const Pixmap_Compression compression)
    {
        this->PushTag(MUIA_Pixmap_Compression, static_cast<unsigned long>(compression));
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagData(const void *data)
    {
        this->PushTag(MUIA_Pixmap_Data, data);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagFormat(const Pixmap_Format format)
    {
        this->PushTag(MUIA_Pixmap_Format, static_cast<unsigned long>(format));
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagHeight(const long value)
    {
        this->PushTag(MUIA_Pixmap_Height, value);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagTransparencyThreshold(const unsigned char value)
    {
        this->PushTag(MUIA_Pixmap_TransparencyThreshold, value);
        return static_cast<T &>(*this);
    }

    template <typename T, typename U> inline T &PixmapBuilderTemplate<T, U>::tagWidth(const long value)
    {
        this->PushTag(MUIA_Pixmap_Width, value);
        return static_cast<T &>(*this);
    }
}
