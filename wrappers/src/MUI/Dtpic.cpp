//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Dtpic.hpp"

namespace MUI
{
    const std::string Dtpic::className = MUIC_Dtpic;

    DtpicBuilder::DtpicBuilder() { }

    long Dtpic::getAlpha() const
    {
        return GetValueAsBool(MUIA_Dtpic_Alpha);
    }

    bool Dtpic::isDarkenSelState() const
    {
        return GetValueAsLong(MUIA_Dtpic_DarkenSelState);
    }

    long Dtpic::getFade() const
    {
        return GetValueAsBool(MUIA_Dtpic_Fade);
    }

    long Dtpic::isLightenOnMouse() const
    {
        return GetValueAsLong(MUIA_Dtpic_LightenOnMouse);
    }

    std::string Dtpic::getName() const
    {
        return GetValueAsString(MUIA_Dtpic_Name);
    }

    Dtpic &Dtpic::setAlpha(const long alpha)
    {
        SetValue(MUIA_Dtpic_Alpha, alpha);
        return *this;
    }

    Dtpic &Dtpic::setFade(const long fade)
    {
        SetValue(MUIA_Dtpic_Fade, fade);
        return *this;
    }

    Dtpic &Dtpic::setName(const std::string &name)
    {
        auto copy = StoreString(name);
        SetValue(MUIA_Dtpic_Name, copy);
        return *this;
    }
}
