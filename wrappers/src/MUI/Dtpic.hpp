//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Dtpic : public Area
    {
      public:
        Dtpic(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        Dtpic(const APTR pMuiObject)
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

        /// @brief [ @b MUIA_Dtpic_Alpha ]
        long getAlpha() const;
        /// @brief [ @b MUIA_Dtpic_DarkenSelState ]
        bool isDarkenSelState() const;
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_Dtpic_Fade ]
        long getFade() const;
#endif
        /// @brief [ @b MUIA_Dtpic_LightenOnMouse ]
        long isLightenOnMouse() const;
        /// @brief [ @b MUIA_Dtpic_Name ]
        std::string getName() const;

        /// @brief [ @b MUIA_Dtpic_Alpha ]
        Dtpic &setAlpha(const long alpha);
        /// @brief [ @b MUIA_Dtpic_Fade ]
        Dtpic &setFade(const long fade);
        /// @brief [ @b MUIA_Dtpic_Name ]
        Dtpic &setName(const std::string &name);
    };

    template <typename T, typename U> class DtpicBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        DtpicBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Dtpic)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Dtpic_Alpha ]
        /// Specify an additional alpha value to be applied when blitting the loaded image onto the screen. The value of MUIA_Dtpic_Alpha is
        /// an 8bit value specifying the intensity of the alpha blitting. You usually want to specify 0xff. Alpha blitting won't work on
        /// CLUT (i.e. depth <= 8 bit) screens.
        T &tagAlpha(const long alpha);
        /// @brief [ @b MUIA_Dtpic_DarkenSelState ]
        /// If set to TRUE the image's brightness will decreased by 50% whenever the left mouse button is pressed on the object.
        T &tagDarkenSelState(const bool darkenSelState);
#ifndef __MORPHOS__
        /// @brief [ @b MUIA_Dtpic_Fade ]
        /// Setting this attribute to a positive value while also changing the image's alpha value will let Dtpic class do a fade between
        /// the previous and the new alpha value. This allows images to be faded in our out. Depending on the fading direction between the
        /// current and the final alpha value the specified value will be repeatedly added or subtracted respectively to the current alpha
        /// value with a delay of 20ms until the final alpha value has been reached.
        /// For negative values the fading process will be stopped and the final alpha value will be set immediately.
        T &tagFade(const long fade);
#endif
        /// @brief [ @b MUIA_Dtpic_LightenOnMouse ]
        /// If set to TRUE the image's brightness will increased by 20% whenever the mouse is moved over the object.
        T &tagLightenOnMouse(const bool lightenOnMouse);
        /// @brief [ @b MUIA_Dtpic_Name ]
        /// Specify the name of the image file to be loaded using datatypes.library. This attribute is absolutely required.
        /// Dtpic class will remember the passed string pointer during OM_NEW and OM_SET, but the string will NOT be copied.
        /// The string is copied and stored internally by this C++ wrapper!
        T &tagName(const std::string &name);
    };

    class DtpicBuilder : public DtpicBuilderTemplate<DtpicBuilder, Dtpic>
    {
      public:
        DtpicBuilder();
    };

    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagAlpha(const long alpha)
    {
        this->PushTag(MUIA_Dtpic_Alpha, alpha);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagDarkenSelState(const bool darkenSelState)
    {
        this->PushTag(MUIA_Dtpic_DarkenSelState, darkenSelState);
        return (T &)*this;
    }

#ifndef __MORPHOS__
    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagFade(const long fade)
    {
        this->PushTag(MUIA_Dtpic_Fade, fade);
        return (T &)*this;
    }
#endif

    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagLightenOnMouse(const bool lightenOnMouse)
    {
        this->PushTag(MUIA_Dtpic_LightenOnMouse, lightenOnMouse);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &DtpicBuilderTemplate<T, U>::tagName(const std::string &name)
    {
        auto copy = this->StoreString(MUIA_Dtpic_Name, name);
        this->PushTag(MUIA_Dtpic_Name, copy);
        return (T &)*this;
    }
}
