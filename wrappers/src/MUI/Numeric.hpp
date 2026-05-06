//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief Numeric class wrapper.
    /// Base class for integer input/display objects. Numeric itself provides common range,
    /// formatting and conversion logic shared by subclasses such as Slider, Knob and Numericbutton.
    class Numeric : public Area
    {
      public:
        explicit Numeric(Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Numeric(const Root &root)
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

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ] Returns whether all values in range are checked for text size.
        bool getCheckAllSizes() const;
        /// @brief [ @b MUIA_Numeric_Default ] Returns default value used by SetDefault().
        long getDefault() const;
        /// @brief [ @b MUIA_Numeric_Format ] Returns printf-style format string used by Stringify().
        std::string getFormat() const;
        /// @brief [ @b MUIA_Numeric_Max ] Returns maximum allowed numeric value.
        long getMax() const;
        /// @brief [ @b MUIA_Numeric_Min ] Returns minimum allowed numeric value.
        long getMin() const;
        /// @brief [ @b MUIA_Numeric_Reverse ] Returns whether scale mapping is reversed.
        bool getReverse() const;
        /// @brief [ @b MUIA_Numeric_RevLeftRight ] Returns whether left/right key behaviour is reversed.
        bool getRevLeftRight() const;
        /// @brief [ @b MUIA_Numeric_RevUpDown ] Returns whether up/down key behaviour is reversed.
        bool getRevUpDown() const;
        /// @brief [ @b MUIA_Numeric_Value ] Returns current numeric value.
        long getValue() const;

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ] Enables or disables full text-size scan across range.
        /// @param checkAllSizes Set to true to check all formatted values, false for standard checks.
        Numeric &setCheckAllSizes(const bool checkAllSizes);
        /// @brief [ @b MUIA_Numeric_Default ] Sets default value used by SetDefault().
        /// @param defaultValue Default numeric value.
        Numeric &setDefault(const long defaultValue);
        /// @brief [ @b MUIA_Numeric_Format ] Sets printf-style format string used by Stringify().
        /// @param format Format string (defaults to "%ld" in MUI).
        Numeric &setFormat(const std::string &format);
        /// @brief [ @b MUIA_Numeric_Max ] Sets maximum allowed numeric value.
        /// @param max Maximum value.
        Numeric &setMax(const long max);
        /// @brief [ @b MUIA_Numeric_Min ] Sets minimum allowed numeric value.
        /// @param min Minimum value.
        Numeric &setMin(const long min);
        /// @brief [ @b MUIA_Numeric_Reverse ] Reverses value-to-scale mapping.
        /// @param reverse Set to true to map minimum value to maximum display scale.
        Numeric &setReverse(const bool reverse);
        /// @brief [ @b MUIA_Numeric_RevLeftRight ] Reverses keyboard left/right behaviour.
        /// @param revLeftRight Set to true to swap left/right key actions.
        Numeric &setRevLeftRight(const bool revLeftRight);
        /// @brief [ @b MUIA_Numeric_RevUpDown ] Reverses keyboard up/down behaviour.
        /// @param revUpDown Set to true to swap up/down key actions.
        Numeric &setRevUpDown(const bool revUpDown);
        /// @brief [ @b MUIA_Numeric_Value ] Sets current numeric value.
        /// @param value New value, clipped by MUI to current min/max range.
        Numeric &setValue(const long value);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Numeric_Decrease ] Decrease the value of a numeric class object.
        /// @param amount Amount to decrease by.
        Numeric &Decrease(const long amount);
        /// @brief [ @b MUIM_Numeric_Increase ] Increase the value of a numeric class object.
        /// @param amount Amount to increase by.
        Numeric &Increase(const long amount);
        /// @brief [ @b MUIM_Numeric_ScaleToValue ] Transform a scale value to the numeric object's min/max range.
        /// @param scalemin Minimum input scale value.
        /// @param scalemax Maximum input scale value.
        /// @param scale Input value on the foreign scale.
        /// @return Transformed numeric value.
        long ScaleToValue(const long scalemin, const long scalemax, const long scale) const;
        /// @brief [ @b MUIM_Numeric_SetDefault ] Reset the current value to the configured default.
        Numeric &SetDefault();
        /// @brief [ @b MUIM_Numeric_Stringify ] Translate a numeric value into its string representation.
        /// @param value Numeric value to stringify.
        /// @return Stringified representation of @a value.
        std::string Stringify(const long value) const;
        /// @brief [ @b MUIM_Numeric_ValueToScale ] Transform the current numeric value to the requested scale.
        /// @param scalemin Minimum target scale value.
        /// @param scalemax Maximum target scale value.
        /// @return Current value transformed to the target scale.
        long ValueToScale(const long scalemin, const long scalemax) const;
    };

    template <typename T, typename U> class NumericBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        NumericBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Numeric)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Numeric_CheckAllSizes ] Enables or disables full text-size scan across range.
        T &tagCheckAllSizes(const bool checkAllSizes);
        /// @brief [ @b MUIA_Numeric_Default ] Sets default value used by SetDefault().
        T &tagDefault(const long defaultValue);
        /// @brief [ @b MUIA_Numeric_Format ] Sets printf-style format string used by Stringify().
        T &tagFormat(const std::string &format);
        /// @brief [ @b MUIA_Numeric_Max ] Sets maximum allowed numeric value.
        T &tagMax(const long max);
        /// @brief [ @b MUIA_Numeric_Min ] Sets minimum allowed numeric value.
        T &tagMin(const long min);
        /// @brief [ @b MUIA_Numeric_Reverse ] Reverses value-to-scale mapping.
        T &tagReverse(const bool reverse);
        /// @brief [ @b MUIA_Numeric_RevLeftRight ] Reverses keyboard left/right behaviour.
        T &tagRevLeftRight(const bool revLeftRight);
        /// @brief [ @b MUIA_Numeric_RevUpDown ] Reverses keyboard up/down behaviour.
        T &tagRevUpDown(const bool revUpDown);
        /// @brief [ @b MUIA_Numeric_Value ] Sets current numeric value.
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
