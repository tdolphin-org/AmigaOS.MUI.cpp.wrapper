//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Bitmap.hpp"

namespace MUI
{
    /// @brief MUI Bodychunk class wrapper.
    /// Displays ILBM image data from a raw BODY chunk using the base bitmap infrastructure.
    class Bodychunk : public Bitmap
    {
      public:
        explicit Bodychunk(Object *pMuiObject)
          : Bitmap(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Bodychunk_Body ]
        /// Returns the pointer to the raw ILBM BODY chunk data.
        unsigned char *getBody() const;
        /// @brief [ @b MUIA_Bodychunk_Body ]
        /// Sets the raw ILBM BODY chunk data pointer. The buffer must remain valid while the object is alive.
        Bodychunk &setBody(unsigned char *pBody);

        /// @brief [ @b MUIA_Bodychunk_Compression ]
        /// Returns the BODY chunk compression mode.
        unsigned char getCompression() const;
        /// @brief [ @b MUIA_Bodychunk_Compression ]
        /// Sets the BODY chunk compression mode, usually one of the ILBM compression constants.
        Bodychunk &setCompression(const unsigned char compression);

        /// @brief [ @b MUIA_Bodychunk_Depth ]
        /// Returns the number of bitplanes in the ILBM data.
        long getDepth() const;
        /// @brief [ @b MUIA_Bodychunk_Depth ]
        /// Sets the number of bitplanes in the ILBM data.
        Bodychunk &setDepth(const long depth);

        /// @brief [ @b MUIA_Bodychunk_Masking ]
        /// Returns the ILBM masking mode.
        unsigned char getMasking() const;
        /// @brief [ @b MUIA_Bodychunk_Masking ]
        /// Sets the ILBM masking mode, usually one of the ILBM masking constants.
        Bodychunk &setMasking(const unsigned char masking);
    };

    template <typename T, typename U> class BodychunkBuilderTemplate : public BitmapBuilderTemplate<T, U>
    {
      public:
        BodychunkBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Bodychunk)
          : BitmapBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Bodychunk_Body ]
        T &tagBody(unsigned char *pBody);
        /// @brief [ @b MUIA_Bodychunk_Compression ]
        T &tagCompression(const unsigned char compression);
        /// @brief [ @b MUIA_Bodychunk_Depth ]
        T &tagDepth(const long depth);
        /// @brief [ @b MUIA_Bodychunk_Masking ]
        T &tagMasking(const unsigned char masking);
    };

    class BodychunkBuilder : public BodychunkBuilderTemplate<BodychunkBuilder, Bodychunk>
    {
      public:
        BodychunkBuilder();
    };
}

#define MUI_BODYCHUNK_TPP_INCLUDE
#include "Bodychunk.tpp"
#undef MUI_BODYCHUNK_TPP_INCLUDE