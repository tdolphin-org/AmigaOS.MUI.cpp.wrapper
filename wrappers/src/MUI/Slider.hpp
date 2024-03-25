//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Numeric.hpp"

#undef Slider

namespace MUI
{
    class Slider : public Numeric
    {
      public:
        Slider(const Object *pMuiObject)
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

    template <typename T, typename U> inline T &SliderBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Slider_Horiz, horiz);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &SliderBuilderTemplate<T, U>::tagQuiet(const bool quiet)
    {
        this->PushTag(MUIA_Slider_Quiet, quiet);
        return (T &)*this;
    }
}
