//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Numeric : public Area
    {
      public:
        explicit Numeric(Object *pMuiObject)
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

        /// @brief [ @b MUIM_Numeric_Decrease ] Decrease the value of a numeric class object.
        Numeric &Decrease(const long amount);
        /// @brief [ @b MUIM_Numeric_Increase ] Increase the value of a numeric class object.
        Numeric &Increase(const long amount);
        /// @brief [ @b MUIM_Numeric_ScaleToValue ] Transform a scale value to the numeric object's min/max range.
        long ScaleToValue(const long scalemin, const long scalemax, const long scale) const;
        /// @brief [ @b MUIM_Numeric_SetDefault ] Reset the current value to the configured default.
        Numeric &SetDefault();
        /// @brief [ @b MUIM_Numeric_Stringify ] Translate a numeric value into its string representation.
        std::string Stringify(const long value) const;
        /// @brief [ @b MUIM_Numeric_ValueToScale ] Transform the current numeric value to the requested scale.
        long ValueToScale(const long scalemin, const long scalemax) const;
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
}

#define MUI_NUMERIC_TPP_INCLUDE
#include "Numeric.tpp"
#undef MUI_NUMERIC_TPP_INCLUDE
