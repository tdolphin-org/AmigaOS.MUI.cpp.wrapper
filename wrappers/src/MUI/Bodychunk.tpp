//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_BODYCHUNK_TPP_INCLUDE
#error "Do not include Bodychunk.tpp directly! It is included by Bodychunk.hpp."
#endif

namespace MUI
{
    template <typename T, typename U> T &BodychunkBuilderTemplate<T, U>::tagBody(unsigned char *pBody)
    {
        this->PushTag(MUIA_Bodychunk_Body, pBody);
        return (T &)*this;
    }

    template <typename T, typename U> T &BodychunkBuilderTemplate<T, U>::tagCompression(const unsigned char compression)
    {
        this->PushTag(MUIA_Bodychunk_Compression, static_cast<unsigned long>(compression));
        return (T &)*this;
    }

    template <typename T, typename U> T &BodychunkBuilderTemplate<T, U>::tagDepth(const long depth)
    {
        this->PushTag(MUIA_Bodychunk_Depth, depth);
        return (T &)*this;
    }

    template <typename T, typename U> T &BodychunkBuilderTemplate<T, U>::tagMasking(const unsigned char masking)
    {
        this->PushTag(MUIA_Bodychunk_Masking, static_cast<unsigned long>(masking));
        return (T &)*this;
    }
}