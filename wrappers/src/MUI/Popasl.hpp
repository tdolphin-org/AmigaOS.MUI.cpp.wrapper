//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include <proto/asl.h>

#include "Popstring.hpp"

namespace MUI
{
    class Popasl : public Popstring
    {
      public:
        Popasl(const Object *pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        Popasl(const APTR pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class PopaslBuilderTemplate : public PopstringBuilderTemplate<T, U>
    {
      public:
        PopaslBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popasl)
          : PopstringBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popasl_Type ]
        T &tagType(const unsigned long type);
        /// @brief [ @b ASLFR_TitleText ]
        T &tagAslFrTitleText(const char *titleText);
        /// @brief [ @b ASLFR_TitleText ]
        T &tagAslFrTitleText(const std::string &titleText);
        /// @brief [ @b ASLFR_DrawersOnly ]
        T &tagAslFrDrawersOnly(const bool drawersOnly = true);
    };

    class PopaslBuilder : public PopaslBuilderTemplate<PopaslBuilder, Popasl>
    {
      public:
        PopaslBuilder();
    };

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagType(const unsigned long type)
    {
        this->PushTag(MUIA_Popasl_Type, type);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const char *titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const std::string &titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(ASLFR_DrawersOnly, drawersOnly);
        return (T &)*this;
    }
}
