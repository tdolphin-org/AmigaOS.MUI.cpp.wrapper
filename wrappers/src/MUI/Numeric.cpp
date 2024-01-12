//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Numeric.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Numeric::className = MUIC_Numeric;

    NumericBuilder::NumericBuilder() { }

    bool Numeric::getCheckAllSizes() const
    {
        return GetValueAsBool(MUIA_Numeric_CheckAllSizes);
    }

    long Numeric::getDefault() const
    {
        return GetValueAsLong(MUIA_Numeric_Default);
    }

    std::string Numeric::getFormat() const
    {
        return GetValueAsString(MUIA_Numeric_Format);
    }

    long Numeric::getMax() const
    {
        return GetValueAsLong(MUIA_Numeric_Max);
    }

    long Numeric::getMin() const
    {
        return GetValueAsLong(MUIA_Numeric_Min);
    }

    bool Numeric::getReverse() const
    {
        return GetValueAsBool(MUIA_Numeric_Reverse);
    }

    bool Numeric::getRevLeftRight() const
    {
        return GetValueAsBool(MUIA_Numeric_RevLeftRight);
    }

    bool Numeric::getRevUpDown() const
    {
        return GetValueAsBool(MUIA_Numeric_RevUpDown);
    }

    long Numeric::getValue() const
    {
        return GetValueAsLong(MUIA_Numeric_Value);
    }

    Numeric &Numeric::setCheckAllSizes(const bool checkAllSizes)
    {
        SetValue(MUIA_Numeric_CheckAllSizes, checkAllSizes);
        return *this;
    }

    Numeric &Numeric::setDefault(const long defaultValue)
    {
        SetValue(MUIA_Numeric_Default, defaultValue);
        return *this;
    }

    Numeric &Numeric::setFormat(const std::string &format)
    {
        SetValue(MUIA_Numeric_Format, format);
        return *this;
    }

    Numeric &Numeric::setMax(const long max)
    {
        SetValue(MUIA_Numeric_Max, max);
        return *this;
    }

    Numeric &Numeric::setMin(const long min)
    {
        SetValue(MUIA_Numeric_Min, min);
        return *this;
    }

    Numeric &Numeric::setReverse(const bool reverse)
    {
        SetValue(MUIA_Numeric_Reverse, reverse);
        return *this;
    }

    Numeric &Numeric::setRevLeftRight(const bool revLeftRight)
    {
        SetValue(MUIA_Numeric_RevLeftRight, revLeftRight);
        return *this;
    }

    Numeric &Numeric::setRevUpDown(const bool revUpDown)
    {
        SetValue(MUIA_Numeric_RevUpDown, revUpDown);
        return *this;
    }

    Numeric &Numeric::setValue(const long value)
    {
        SetValue(MUIA_Numeric_Value, value);
        return *this;
    }

    Numeric &Numeric::Decrease(const long amount)
    {
        DoMethod(muiObject(), MUIM_Numeric_Decrease, amount);
        return *this;
    }

    Numeric &Numeric::Increase(const long amount)
    {
        DoMethod(muiObject(), MUIM_Numeric_Increase, amount);
        return *this;
    }

    Numeric &Numeric::ScaleToValue(const long scalemin, const long scalemax, const long scale)
    {
        DoMethod(muiObject(), MUIM_Numeric_ScaleToValue, scalemin, scalemax, scale);
        return *this;
    }

    Numeric &Numeric::SetDefault()
    {
        DoMethod(muiObject(), MUIM_Numeric_SetDefault);
        return *this;
    }

    Numeric &Numeric::Stringify(const long value)
    {
        DoMethod(muiObject(), MUIM_Numeric_Stringify, value);
        return *this;
    }

    Numeric &Numeric::ValueToScale(const long scalemin, const long scalemax)
    {
        DoMethod(muiObject(), MUIM_Numeric_ValueToScale, scalemin, scalemax);
        return *this;
    }

}
