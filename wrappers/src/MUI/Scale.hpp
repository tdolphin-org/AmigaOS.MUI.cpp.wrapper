//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief Wrapper for MUIC_Scale - a percentage scale running from 0% to 100%.
    /// The scale is typically used below another object such as a gauge and adapts its detail
    /// automatically to the available layout space.
    class Scale : public Area
    {
      public:
        explicit Scale(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Scale_Horiz ] Get whether the scale is horizontal.
        bool getHoriz() const;

        /// @brief [ @b MUIA_Scale_Horiz ] Set whether the scale is horizontal or vertical.
        Scale &setHoriz(const bool horiz);
    };

    template <typename T, typename U> class ScaleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ScaleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scale)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Scale_Horiz ] Set whether the initial scale is horizontal or vertical.
        T &tagHoriz(const bool horiz);
    };

    class ScaleBuilder : public ScaleBuilderTemplate<ScaleBuilder, Scale>
    {
      public:
        ScaleBuilder();
    };
}

#define MUI_SCALE_TPP_INCLUDE
#include "Scale.tpp"
#undef MUI_SCALE_TPP_INCLUDE
