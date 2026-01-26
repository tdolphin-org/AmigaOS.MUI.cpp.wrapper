//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_NUMERIC_TPP_INCLUDE
#error "Numeric.tpp should only be included by Numeric.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagCheckAllSizes(const bool checkAllSizes)
    {
        this->PushTag(MUIA_Numeric_CheckAllSizes, checkAllSizes);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagDefault(const long defaultValue)
    {
        this->PushTag(MUIA_Numeric_Default, defaultValue);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagFormat(const std::string &format)
    {
        auto copy = this->StoreString(MUIA_Numeric_Format, format);
        this->PushTag(MUIA_Numeric_Format, copy);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagMax(const long max)
    {
        this->PushTag(MUIA_Numeric_Max, max);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagMin(const long min)
    {
        this->PushTag(MUIA_Numeric_Min, min);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagReverse(const bool reverse)
    {
        this->PushTag(MUIA_Numeric_Reverse, reverse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagRevLeftRight(const bool revLeftRight)
    {
        this->PushTag(MUIA_Numeric_RevLeftRight, revLeftRight);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagRevUpDown(const bool revUpDown)
    {
        this->PushTag(MUIA_Numeric_RevUpDown, revUpDown);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &NumericBuilderTemplate<T, U>::tagValue(const long value)
    {
        this->PushTag(MUIA_Numeric_Value, value);
        return (T &)*this;
    }
}
