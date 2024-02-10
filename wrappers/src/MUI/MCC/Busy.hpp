//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "MUI/Area.hpp"
#include <mui/Busy_mcc.h>

namespace MUI::MCC
{
    class Busy : public MUI::Area
    {
      public:
        Busy(const Object *pObject)
          : Area(pObject)
        {
        }

        Busy(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        Busy(const Root &root)
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

        /// @biref [ @b MUIA_Busy_Speed == @b MUIV_Busy_Speed_Off ]
        bool isSpeedOff() const;
        /// @biref [ @b MUIA_Busy_Speed == @b MUIV_Busy_Speed_User ]
        bool isSpeedUser() const;
        /// @biref [ @b MUIA_Busy_Speed ]
        long getSpeed() const;

        /// @brief [ @b MUIA_Busy_Speed, @b MUIV_Busy_Speed_Off ]
        /// MUIV_Busy_Speed_Off will stop the Busy bar.
        Busy &setSpeedOff();
        /// @brief [ @b MUIA_Busy_Speed, @b MUIV_Busy_Speed_User ]
        /// MUIV_Busy_Speed_User takes over the speed at preferences.
        Busy &setSpeedUser();
        /// @brief [ @b MUIA_Busy_Speed ]
        /// Trigger the speed of the moving Busy bar. Values between 1 and 250 are allowed.
        Busy &setSpeed(const unsigned char speed);

        // methods, some returns object reference

        /// @brief [ @b MUIM_Busy_Move ]
        Busy &Move();
    };

    template <typename T, typename U> class BusyBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        BusyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = U::className)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Busy_ShowHideIH ]
        /// On default the MUI InputHandler is added in the MUIM_Setup method and removed in MUIM_Cleanup, set this to TRUE the
        /// MUIM_Show/MUIM_Hide methods are used.
        T &tagShowHideIH(const bool showHideIH);
        /// @brief [ @b MUIA_Busy_Speed, @b MUIV_Busy_Speed_Off ]
        /// MUIV_Busy_Speed_Off will stop the Busy bar.
        T &tagSpeedOff();
        /// @brief [ @b MUIA_Busy_Speed, @b MUIV_Busy_Speed_User ]
        /// MUIV_Busy_Speed_User takes over the speed at preferences.
        T &tagSpeedUser();
        /// @brief [ @b MUIA_Busy_Speed ]
        /// The speed of the moving Busy bar. Values between 1 and 250 are allowed.
        T &tagSpeed(const unsigned char speed);
    };

    class BusyBuilder : public BusyBuilderTemplate<BusyBuilder, Busy>
    {
      public:
        BusyBuilder();
    };

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
