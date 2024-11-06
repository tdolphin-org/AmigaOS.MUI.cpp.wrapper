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

#ifdef MUIA_Dtpic_Alpha
    long Dtpic::getAlpha() const
    {
        return GetValueAsBool(MUIA_Dtpic_Alpha);
    }
#endif

#ifdef MUIA_Dtpic_DarkenSelState
    bool Dtpic::isDarkenSelState() const
    {
        return GetValueAsLong(MUIA_Dtpic_DarkenSelState);
    }
#endif

#ifdef MUIA_Dtpic_Fade
    long Dtpic::getFade() const
    {
        return GetValueAsBool(MUIA_Dtpic_Fade);
    }
#endif

#ifdef MUIA_Dtpic_LightenOnMouse
    long Dtpic::isLightenOnMouse() const
    {
        return GetValueAsLong(MUIA_Dtpic_LightenOnMouse);
    }
#endif

#ifdef MUIA_Dtpic_Name
    std::string Dtpic::getName() const
    {
        return GetValueAsString(MUIA_Dtpic_Name);
    }
#endif

#ifdef MUIA_Dtpic_Alpha
    Dtpic &Dtpic::setAlpha(const long alpha)
    {
        SetValue(MUIA_Dtpic_Alpha, alpha);
        return *this;
    }
#endif

#ifdef MUIA_Dtpic_Fade
    Dtpic &Dtpic::setFade(const long fade)
    {
        SetValue(MUIA_Dtpic_Fade, fade);
        return *this;
    }
#endif

#ifdef MUIA_Dtpic_Name
    Dtpic &Dtpic::setName(const std::string &name)
    {
        SetValue(MUIA_Dtpic_Name, StoreString(MUIA_Dtpic_Name, name));
        return *this;
    }
#endif
}
