//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Text.hpp"

#ifdef MUIC_Fontdisplay

namespace MUI
{
    /// @brief MUI Fontdisplay class wrapper.
    /// Private class that displays a font example string. Inherits from Text.
    class Fontdisplay : public Text
    {
      public:
        explicit Fontdisplay(Object *pMuiObject)
          : Text(pMuiObject)
        {
        }

        Fontdisplay(const Root &root)
          : Text(root.muiObject())
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
    };

    template <typename T, typename U> class FontdisplayBuilderTemplate : public TextBuilderTemplate<T, U>
    {
      public:
        FontdisplayBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Fontdisplay)
          : TextBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }
    };

    class FontdisplayBuilder : public FontdisplayBuilderTemplate<FontdisplayBuilder, Fontdisplay>
    {
      public:
        FontdisplayBuilder();
    };
}

#define MUI_FONTDISPLAY_TPP_INCLUDE
#include "Fontdisplay.tpp"
#undef MUI_FONTDISPLAY_TPP_INCLUDE

#endif
