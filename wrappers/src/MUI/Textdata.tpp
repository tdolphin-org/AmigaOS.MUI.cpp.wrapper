//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_TEXTDATA_TPP_INCLUDE
#error "Textdata.tpp should only be included by Textdata.hpp"
#endif

namespace MUI
{
#ifdef MUIA_Textdata_Contents
    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagContents(const char *contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagContents(const std::string &contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        return (T &)*this;
    }

#ifdef MUIA_Textdata_Encoding
    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagLContents(const char *contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_ISO_10646_UCS_2);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagLContents(const std::string &contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_ISO_10646_UCS_2);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagUContents(const char *contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_UTF_8);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagUContents(const std::string &contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_UTF_8);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagAContents(const char *contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_ISO_8859_1);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagAContents(const std::string &contents)
    {
        this->PushTag(MUIA_Textdata_Contents, contents);
        this->PushTag(MUIA_Textdata_Encoding, MIBENUM_ISO_8859_1);
        return (T &)*this;
    }
#endif
#endif

#ifdef MUIA_Textdata_Encoding
    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagEncoding(const unsigned long encoding)
    {
        this->PushTag(MUIA_Textdata_Encoding, encoding);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Textdata_SourceBytes
    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagSourceBytes(const long sourceBytes)
    {
        this->PushTag(MUIA_Textdata_SourceBytes, sourceBytes);
        return (T &)*this;
    }
#endif

#ifdef MUIA_Textdata_SourceEncoding
    template <typename T, typename U> inline T &TextdataBuilderTemplate<T, U>::tagSourceEncoding(const unsigned long sourceEncoding)
    {
        this->PushTag(MUIA_Textdata_SourceEncoding, sourceEncoding);
        return (T &)*this;
    }
#endif
}
