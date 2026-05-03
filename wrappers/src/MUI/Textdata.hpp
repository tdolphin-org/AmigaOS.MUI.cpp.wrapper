//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Notify.hpp"

#ifdef Textdata
#undef Textdata
#endif

#ifdef MUIC_Textdata

namespace MUI
{
    /// @brief MUI Textdata class wrapper.
    /// Textdata allows using text encodings other than ISO-8859-1 by converting source text
    /// to the system charset through codesets.library conversion routines.
    class Textdata : public Notify
    {
      public:
        explicit Textdata(Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Textdata(const Root &root)
          : Notify(root)
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

#ifdef MUIA_Textdata_Contents
        /// @brief [ @b MUIA_Textdata_Contents ]
        /// Returns current source text contents used by this Textdata object.
        std::string getContents() const;
#endif
#ifdef MUIA_Textdata_Encoding
        /// @brief [ @b MUIA_Textdata_Encoding ]
        /// Returns source text encoding as a MIB number.
        unsigned long getEncoding() const;
#endif

        // methods

#ifdef MUIM_Textdata_Convert
        /// @brief [ @b MUIM_Textdata_Convert ]
        /// Converts initially specified text contents to requested destination encoding.
        /// @param encoding destination encoding (MIB number)
        /// @return pointer to converted read-only text, or NULL on failure
        const char *Convert(const unsigned long encoding) const;
#endif
    };

    template <typename T, typename U> class TextdataBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        TextdataBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Textdata)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Textdata_Contents
        /// @brief [ @b MUIA_Textdata_Contents ]
        /// Defines the source text contents to be converted by Textdata.
        T &tagContents(const char *contents);
        /// @brief [ @b MUIA_Textdata_Contents ]
        /// Defines the source text contents to be converted by Textdata.
        T &tagContents(const std::string &contents);
#endif
#ifdef MUIA_Textdata_Encoding
        /// @brief Convenience helper equivalent to SDK @b LTextdata(s).
        /// Sets contents and marks encoding as UCS-2.
        T &tagLContents(const char *contents);
        /// @brief Convenience helper equivalent to SDK @b LTextdata(s).
        /// Sets contents and marks encoding as UCS-2.
        T &tagLContents(const std::string &contents);
        /// @brief Convenience helper equivalent to SDK @b UTextdata(s).
        /// Sets contents and marks encoding as UTF-8.
        T &tagUContents(const char *contents);
        /// @brief Convenience helper equivalent to SDK @b UTextdata(s).
        /// Sets contents and marks encoding as UTF-8.
        T &tagUContents(const std::string &contents);
        /// @brief Convenience helper equivalent to SDK @b ATextdata(s).
        /// Sets contents and marks encoding as ISO-8859-1.
        T &tagAContents(const char *contents);
        /// @brief Convenience helper equivalent to SDK @b ATextdata(s).
        /// Sets contents and marks encoding as ISO-8859-1.
        T &tagAContents(const std::string &contents);
#endif
#ifdef MUIA_Textdata_Encoding
        /// @brief [ @b MUIA_Textdata_Encoding ]
        /// Defines source text encoding as a MIB number.
        T &tagEncoding(const unsigned long encoding);
#endif
#ifdef MUIA_Textdata_SourceBytes
        /// @brief [ @b MUIA_Textdata_SourceBytes ]
        /// Defines number of bytes in the source text.
        T &tagSourceBytes(const long sourceBytes);
#endif
#ifdef MUIA_Textdata_SourceEncoding
        /// @brief [ @b MUIA_Textdata_SourceEncoding ]
        /// Defines source encoding for conversion input as a MIB number.
        T &tagSourceEncoding(const unsigned long sourceEncoding);
#endif
    };

    class TextdataBuilder : public TextdataBuilderTemplate<TextdataBuilder, Textdata>
    {
      public:
        TextdataBuilder();
    };
}

#define MUI_TEXTDATA_TPP_INCLUDE
#include "Textdata.tpp"
#undef MUI_TEXTDATA_TPP_INCLUDE

#endif
