//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief MUI Gauge class wrapper.
    /// Gauge is a display element commonly used to present progress values.
    class Gauge : public Area
    {
      public:
        explicit Gauge(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Gauge(const Root &root)
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

        /// @brief [ @b MUIA_Gauge_Current ] Get the current level value of the gauge.
        long getCurrent() const;
        /// @brief [ @b MUIA_Gauge_Divide ] Get the divisor applied to current value updates.
        unsigned long getDivide() const;
#ifdef MUIA_Gauge_InfoRate
        /// @brief [ @b MUIA_Gauge_InfoRate ] Get info text refresh-rate divider (MorphOS/AmigaOS MUI5 SDK dependent).
        long getInfoRate() const;
#endif
        /// @brief [ @b MUIA_Gauge_InfoText ] Get text displayed inside the gauge.
        std::string getInfoText() const;
        /// @brief [ @b MUIA_Gauge_Max ] Get the maximum value of the gauge.
        long getMax() const;

        /// @brief [ @b MUIA_Gauge_Current ] Set the current level value of the gauge.
        Gauge &setCurrent(const long current);
        /// @brief [ @b MUIA_Gauge_Divide ] Set divisor used before processing current level updates.
        Gauge &setDivide(const unsigned long divide);
#ifdef MUIA_Gauge_InfoRate
        /// @brief [ @b MUIA_Gauge_InfoRate ] Set info text refresh-rate divider (MorphOS/AmigaOS MUI5 SDK dependent).
        Gauge &setInfoRate(const long infoRate);
#endif
        /// @brief [ @b MUIA_Gauge_InfoText ] Set text displayed inside the gauge.
        Gauge &setInfoText(const std::string &infoText);
        /// @brief [ @b MUIA_Gauge_Max ] Set the maximum value of the gauge.
        Gauge &setMax(const long max);
    };

    template <typename T, typename U> class GaugeBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        GaugeBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Gauge)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Gauge_Current ] Set initial current level value.
        T &tagCurrent(const long current);
        /// @brief [ @b MUIA_Gauge_Divide ] Set initial divisor for current level updates.
        T &tagDivide(const unsigned long divide);
        /// @brief [ @b MUIA_Gauge_Horiz ] Select horizontal (true) or vertical (false) gauge at initialization.
        T &tagHoriz(const bool horiz);
#ifdef MUIA_Gauge_InfoRate
        /// @brief [ @b MUIA_Gauge_InfoRate ]
        T &tagInfoRate(const long infoRate);
#endif
        /// @brief [ @b MUIA_Gauge_InfoText ] Set initial text displayed inside gauge.
        T &tagInfoText(const std::string &infoText);
        /// @brief [ @b MUIA_Gauge_Max ] Set initial maximum gauge value.
        T &tagMax(const long max);
    };

    class GaugeBuilder : public GaugeBuilderTemplate<GaugeBuilder, Gauge>
    {
      public:
        GaugeBuilder();
    };
}

#define MUI_GAUGE_TPP_INCLUDE
#include "Gauge.tpp"
#undef MUI_GAUGE_TPP_INCLUDE
