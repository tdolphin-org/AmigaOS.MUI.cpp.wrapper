//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief A Scale object generates a percentage scale running from 0% to 100%.
    /// A good place for such an object is e.g. below a fuel gauge. Depending on how much
    /// space is available, the scale will be more or less detailed.
    class Scale : public Area
    {
      public:
        explicit Scale(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Scale(const Root &root)
          : Area(root.muiObject())
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

        /// @brief [ @b MUIA_Scale_Horiz ] Indicate whether you want a horizontal or a vertical scale.
        /// Defaults to horizontal.
        bool getHoriz() const;

        /// @brief [ @b MUIA_Scale_Horiz ] Indicate whether you want a horizontal or a vertical scale.
        /// Defaults to horizontal.
        Scale &setHoriz(const bool horiz);
    };

    template <typename T, typename U> class ScaleBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        ScaleBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Scale)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Scale_Horiz ] Indicate whether you want a horizontal or a vertical scale.
        /// Defaults to horizontal.
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
