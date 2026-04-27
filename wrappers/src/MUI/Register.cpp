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

#if defined(AOS_MUI_VERSION_5) && defined(MUIA_Register_Titles)
    Register &Register::setTitles(const char *titles[])
    {
        auto copy = StoreStringArray(MUIA_Register_Titles, titles);
        SetValue(MUIA_Register_Titles, copy);
        return *this;
    }

    Register &Register::setTitles(const std::vector<std::string> &titles)
    {
        auto copy = StoreStringArray(MUIA_Register_Titles, titles);
        SetValue(MUIA_Register_Titles, copy);
        return *this;
    }

#if defined(MUIV_Register_Titles_UData) && defined(MUIV_Register_Titles_Frame)
    Register &Register::setTitles(const enum Register_Titles titles)
    {
        SetValue(MUIA_Register_Titles, (long)titles);
        return *this;
    }
#endif
#endif
}
