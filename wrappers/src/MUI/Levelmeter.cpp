//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Levelmeter.hpp"

namespace MUI
{
    const std::string Levelmeter::className = MUIC_Levelmeter;

    LevelmeterBuilder::LevelmeterBuilder() { }

    std::string Levelmeter::getLabel() const
    {
        return GetValueAsString(MUIA_Levelmeter_Label);
    }

    Levelmeter &Levelmeter::setLabel(const char *label)
    {
        SetValue(MUIA_Levelmeter_Label, label);
        return *this;
    }

    Levelmeter &Levelmeter::setLabel(const std::string &label)
    {
        SetValue(MUIA_Levelmeter_Label, label);
        return *this;
    }
}
