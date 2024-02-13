//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "Register.hpp"

namespace MUI
{
    const std::string Register::className = MUIC_Register;

    RegisterBuilder::RegisterBuilder() { }

    char **Register::getTitles() const
    {
        return GetValueAsCharArrayPtr(MUIA_Register_Titles);
    }

    Register &Register::setTitles(const char *titles[])
    {
        SetValue(MUIA_Register_Titles, titles);
        return *this;
    }
}
