//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_GAUGE_TPP_INCLUDE
#error "Gauge.tpp should only be included by Gauge.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagCurrent(const long current)
    {
        this->PushTag(MUIA_Gauge_Current, current);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagDivide(const unsigned long divide)
    {
        this->PushTag(MUIA_Gauge_Divide, divide);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagHoriz(const bool horiz)
    {
        this->PushTag(MUIA_Gauge_Horiz, horiz);
        return (T &)*this;
    }

#ifdef MUIA_Gauge_InfoRate
    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagInfoRate(const long infoRate)
    {
        this->PushTag(MUIA_Gauge_InfoRate, infoRate);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagInfoText(const std::string &infoText)
    {
        auto copy = this->StoreString(MUIA_Gauge_InfoText, infoText);
        this->PushTag(MUIA_Gauge_InfoText, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &GaugeBuilderTemplate<T, U>::tagMax(const long max)
    {
        this->PushTag(MUIA_Gauge_Max, max);
        return (T &)*this;
    }
}
