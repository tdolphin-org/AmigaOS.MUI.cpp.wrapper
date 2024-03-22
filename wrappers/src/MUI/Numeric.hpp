//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Numeric : public Area
    {
      public:
        Numeric(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Numeric(const APTR pMuiObject)
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

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ]
        bool getCheckAllSizes() const;
        /// @brief [ @b MUIA_Numeric_Default ]
        long getDefault() const;
        /// @brief [ @b MUIA_Numeric_Format ]
        std::string getFormat() const;
        /// @brief [ @b MUIA_Numeric_Max ]
        long getMax() const;
        /// @brief [ @b MUIA_Numeric_Min ]
        long getMin() const;
        /// @brief [ @b MUIA_Numeric_Reverse ]
        bool getReverse() const;
        /// @brief [ @b MUIA_Numeric_RevLeftRight ]
        bool getRevLeftRight() const;
        /// @brief [ @b MUIA_Numeric_RevUpDown ]
        bool getRevUpDown() const;
        /// @brief [ @b MUIA_Numeric_Value ]
        long getValue() const;

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ]
        Numeric &setCheckAllSizes(const bool checkAllSizes);
        /// @brief [ @b MUIA_Numeric_Default ]
        Numeric &setDefault(const long defaultValue);
        /// @brief [ @b MUIA_Numeric_Format ]
        Numeric &setFormat(const std::string &format);
        /// @brief [ @b MUIA_Numeric_Max ]
        Numeric &setMax(const long max);
        /// @brief [ @b MUIA_Numeric_Min ]
        Numeric &setMin(const long min);
        /// @brief [ @b MUIA_Numeric_Reverse ]
        Numeric &setReverse(const bool reverse);
        /// @brief [ @b MUIA_Numeric_RevLeftRight ]
        Numeric &setRevLeftRight(const bool revLeftRight);
        /// @brief [ @b MUIA_Numeric_RevUpDown ]
        Numeric &setRevUpDown(const bool revUpDown);
        /// @brief [ @b MUIA_Numeric_Value ]
        Numeric &setValue(const long value);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Numeric_Decrease ]
        Numeric &Decrease(const long amount);
        /// @brief [ @b MUIM_Numeric_Increase ]
        Numeric &Increase(const long amount);
        /// @brief [ @b MUIM_Numeric_ScaleToValue ]
        Numeric &ScaleToValue(const long scalemin, const long scalemax, const long scale);
        /// @brief [ @b MUIM_Numeric_SetDefault ]
        Numeric &SetDefault();
        /// @brief [ @b MUIM_Numeric_Stringify ]
        Numeric &Stringify(const long value);
        /// @brief [ @b MUIM_Numeric_ValueToScale ]
        Numeric &ValueToScale(const long scalemin, const long scalemax);
    };

    template <typename T, typename U> class NumericBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        NumericBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Numeric)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ]
        T &tagCheckAllSizes(const bool checkAllSizes);
        /// @brief [ @b MUIA_Numeric_Default ]
        T &tagDefault(const long defaultValue);
        /// @brief [ @b MUIA_Numeric_Format ]
        T &tagFormat(const std::string &format);
        /// @brief [ @b MUIA_Numeric_Max ]
        T &tagMax(const long max);
        /// @brief [ @b MUIA_Numeric_Min ]
        T &tagMin(const long min);
        /// @brief [ @b MUIA_Numeric_Reverse ]
        T &tagReverse(const bool reverse);
        /// @brief [ @b MUIA_Numeric_RevLeftRight ]
        T &tagRevLeftRight(const bool revLeftRight);
        /// @brief [ @b MUIA_Numeric_RevUpDown ]
        T &tagRevUpDown(const bool revUpDown);
        /// @brief [ @b MUIA_Numeric_Value ]
        T &tagValue(const long value);
    };

    class NumericBuilder : public NumericBuilderTemplate<NumericBuilder, Numeric>
    {
      public:
        NumericBuilder();
    };

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
