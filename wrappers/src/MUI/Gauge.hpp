//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Gauge : public Area
    {
      public:
        explicit Gauge(Object *pMuiObject)
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

        /// @brief [ @b MUIA_Gauge_Current ]
        long getCurrent() const;
        /// @brief [ @b MUIA_Gauge_Divide ]
        unsigned long getDivide() const;
#ifdef MUIA_Gauge_InfoRate
        /// @brief [ @b MUIA_Gauge_InfoRate ]
        long getInfoRate() const;
#endif
        /// @brief [ @b MUIA_Gauge_InfoText ]
        std::string getInfoText() const;
        /// @brief [ @b MUIA_Gauge_Max ]
        long getMax() const;

        /// @brief [ @b MUIA_Gauge_Current ]
        Gauge &setCurrent(const long current);
        /// @brief [ @b MUIA_Gauge_Divide ]
        Gauge &setDivide(const unsigned long divide);
#ifdef MUIA_Gauge_InfoRate
        /// @brief [ @b MUIA_Gauge_InfoRate ]
        Gauge &setInfoRate(const long InfoRate);
#endif
        /// @brief [ @b MUIA_Gauge_InfoText ]
        Gauge &setInfoText(const std::string &infoText);
        /// @brief [ @b MUIA_Gauge_Max ]
        Gauge &setMax(const long max);
    };

    template <typename T, typename U> class GaugeBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        GaugeBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Gauge)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Gauge_Current ]
        T &tagCurrent(const long current);
        /// @brief [ @b MUIA_Gauge_Divide ]
        T &tagDivide(const unsigned long divide);
        /// @brief [ @b MUIA_Gauge_Horiz ]
        T &tagHoriz(const bool horiz);
        /// @brief [ @b MUIA_Gauge_InfoRate ]
        T &tagInfoRate(const long infoRate);
        /// @brief [ @b MUIA_Gauge_InfoText ]
        T &tagInfoText(const std::string &infoText);
        /// @brief [ @b MUIA_Gauge_Max ]
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
