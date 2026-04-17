//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Register.hpp"

namespace MUI
{
    const std::string Register::className = MUIC_Register;

    RegisterBuilder::RegisterBuilder() { }

    const char **Register::getTitles() const
    {
        return GetValueAsConstCharArrayPtr(MUIA_Register_Titles);
    }

#if MUIMASTER_VMIN >= 20 // MUI5
    Register &Register::setTitles(const char *titles[])
    {
        SetValue(MUIA_Register_Titles, titles);
        return *this;
    }
#endif
}
