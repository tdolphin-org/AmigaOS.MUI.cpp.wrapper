//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Numeric.hpp"

#undef Slider

namespace MUI
{
    class Slider : public Numeric
    {
      public:
        explicit Slider(Object *pMuiObject)
          : Numeric(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Slider_Horiz ]
        bool getHoriz() const;

        /// @brief [ @b MUIA_Slider_Horiz ]
        Slider &setHoriz(const bool horiz);
    };

    template <typename T, typename U> class SliderBuilderTemplate : public NumericBuilderTemplate<T, U>
    {
      public:
        SliderBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Slider)
          : NumericBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Slider_Horiz ]
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Slider_Quiet ]
        T &tagQuiet(const bool quiet);
    };

    class SliderBuilder : public SliderBuilderTemplate<SliderBuilder, Slider>
    {
      public:
        SliderBuilder();
    };
}

#define MUI_SLIDER_TPP_INCLUDE
#include "Slider.tpp"
#undef MUI_SLIDER_TPP_INCLUDE
