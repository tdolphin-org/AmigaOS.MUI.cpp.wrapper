//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_MCC_BUSY_TPP_INCLUDE
#error "Busy.tpp should only be included by Busy.hpp"
#endif

namespace MUI::MCC
{
    template <typename T, typename U> inline T &BusyBuilderTemplate<T, U>::tagShowHideIH(const bool showHideIH)
    {
        this->PushTag(MUIA_Busy_ShowHideIH, showHideIH);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &BusyBuilderTemplate<T, U>::tagSpeedOff()
    {
        this->PushTag(MUIA_Busy_Speed, (long)MUIV_Busy_Speed_Off);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &BusyBuilderTemplate<T, U>::tagSpeedUser()
    {
        this->PushTag(MUIA_Busy_Speed, (long)MUIV_Busy_Speed_User);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &BusyBuilderTemplate<T, U>::tagSpeed(const unsigned char speed)
    {
        this->PushTag(MUIA_Busy_Speed, speed);
        return (T &)*this;
    }
}
