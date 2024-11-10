//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Gauge.hpp"

namespace MUI
{
    const std::string Gauge::className = MUIC_Gauge;

    GaugeBuilder::GaugeBuilder() { }

    long Gauge::getCurrent() const
    {
        return GetValueAsLong(MUIA_Gauge_Current);
    }

    unsigned long Gauge::getDivide() const
    {
        return GetValueAsULong(MUIA_Gauge_Divide);
    }

#ifdef MUIA_Gauge_InfoRate
    long Gauge::getInfoRate() const
    {
        return GetValueAsLong(MUIA_Gauge_InfoRate);
    }
#endif

    std::string Gauge::getInfoText() const
    {
        return GetValueAsString(MUIA_Gauge_InfoText);
    }

    long Gauge::getMax() const
    {
        return GetValueAsLong(MUIA_Gauge_Max);
    }

    Gauge &Gauge::setCurrent(const long current)
    {
        SetValue(MUIA_Gauge_Current, current);
        return *this;
    }

    Gauge &Gauge::setDivide(const unsigned long divide)
    {
        SetValue(MUIA_Gauge_Divide, divide);
        return *this;
    }

#ifdef MUIA_Gauge_InfoRate
    Gauge &Gauge::setInfoRate(const long horiz)
    {
        SetValue(MUIA_Gauge_InfoRate, horiz);
        return *this;
    }
#endif

    Gauge &Gauge::setInfoText(const std::string &infoText)
    {
        SetValue(MUIA_Gauge_InfoText, StoreString(MUIA_Gauge_InfoText, infoText));
        return *this;
    }

    Gauge &Gauge::setMax(const long max)
    {
        SetValue(MUIA_Gauge_Max, max);
        return *this;
    }
}
