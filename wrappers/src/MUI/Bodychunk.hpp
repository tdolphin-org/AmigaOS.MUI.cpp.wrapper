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
    /// Allows displaying large compressed images (e.g. About-Logos) by storing the picture as a compressed IFF/ILBM BODY chunk.
    /// MUI automatically decompresses the image when it is about to appear in a window.
    /// Since Bodychunk is a subclass of Bitmap, all Bitmap remapping and transparency features are available.
    class Bodychunk : public Bitmap
    {
      public:
        explicit Bodychunk(Object *pMuiObject)
          : Bitmap(pMuiObject)
        {
        }

        Bodychunk(const Root &root)
          : Bitmap(root.muiObject())
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

        /// @brief [ @b MUIA_Bodychunk_Body ]
        /// Returns the pointer to the BODY data of the picture. The data follows normal IFF/ILBM conventions.
        unsigned char *getBody() const;
        /// @brief [ @b MUIA_Bodychunk_Body ]
        /// Specifies a pointer to the BODY data of the picture. The data must follow normal IFF/ILBM conventions.
        /// MUIA_Bitmap_Width, MUIA_Bitmap_Height and MUIA_Bodychunk_Depth are required for correct decompression.
        /// Body data may be shared between different Bodychunk objects and does not need to be in chip ram.
        Bodychunk &setBody(unsigned char *pBody);

        /// @brief [ @b MUIA_Bodychunk_Compression ]
        /// Returns the BODY chunk compression type (0 = uncompressed, 1 = cmpByteRun1).
        unsigned char getCompression() const;
        /// @brief [ @b MUIA_Bodychunk_Compression ]
        /// Sets the BODY chunk compression type. Use cmpByteRun1 (==1) for byte-run compressed data, 0 for uncompressed.
        Bodychunk &setCompression(const unsigned char compression);

        /// @brief [ @b MUIA_Bodychunk_Depth ]
        /// Returns the number of bitplanes in the ILBM BODY data.
        long getDepth() const;
        /// @brief [ @b MUIA_Bodychunk_Depth ]
        /// Specifies the depth (number of bitplanes) of the picture. Required for correct BODY chunk parsing.
        /// Also set MUIA_Bodychunk_Masking if the BODY data contains a masking bitplane.
        Bodychunk &setDepth(const long depth);

        /// @brief [ @b MUIA_Bodychunk_Masking ]
        /// Returns the ILBM masking type of the BODY data.
        unsigned char getMasking() const;
        /// @brief [ @b MUIA_Bodychunk_Masking ]
        /// Indicates whether the BODY data contains a masking plane. Required for correct BODY chunk parsing.
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
        /// Specifies a pointer to the BODY data of the picture. Data must follow normal IFF/ILBM conventions.
        /// MUIA_Bitmap_Width, MUIA_Bitmap_Height and MUIA_Bodychunk_Depth are required for correct decompression.
        T &tagBody(unsigned char *pBody);
        /// @brief [ @b MUIA_Bodychunk_Compression ]
        /// Sets the BODY chunk compression type. Use cmpByteRun1 (==1) for byte-run compressed data, 0 for uncompressed.
        T &tagCompression(const unsigned char compression);
        /// @brief [ @b MUIA_Bodychunk_Depth ]
        /// Specifies the depth (number of bitplanes) of the picture. Required for correct BODY chunk parsing.
        T &tagDepth(const long depth);
        /// @brief [ @b MUIA_Bodychunk_Masking ]
        /// Indicates whether the BODY data contains a masking plane. Required for correct BODY chunk parsing.
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