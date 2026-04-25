//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    /// @brief MUI Dtpic class wrapper.
    /// Displays an arbitrary image loaded via datatypes.library. Supports full transparency and alpha channel.
    class Dtpic : public Area
    {
      public:
        explicit Dtpic(Object *pMuiObject)
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

#ifdef MUIA_Dtpic_Alpha
        /// @brief [ @b MUIA_Dtpic_Alpha ] Returns the current alpha blending value (0..255) applied when blitting the image.
        long getAlpha() const;
#endif
#ifdef MUIA_Dtpic_DarkenSelState
        /// @brief [ @b MUIA_Dtpic_DarkenSelState ] Returns whether the image brightness is decreased by 50% when the left mouse button is
        /// pressed.
        bool isDarkenSelState() const;
#endif
#ifdef MUIA_Dtpic_FreeHoriz
        /// @brief [ @b MUIA_Dtpic_FreeHoriz ] Returns whether the image may scale freely in horizontal direction.
        bool isFreeHoriz() const;
#endif
#ifdef MUIA_Dtpic_FreeVert
        /// @brief [ @b MUIA_Dtpic_FreeVert ] Returns whether the image may scale freely in vertical direction.
        bool isFreeVert() const;
#endif
#ifdef MUIA_Dtpic_Fade
        /// @brief [ @b MUIA_Dtpic_Fade ] Returns the current fade step value used for alpha transitions.
        long getFade() const;
#endif
#ifdef MUIA_Dtpic_LightenOnMouse
        /// @brief [ @b MUIA_Dtpic_LightenOnMouse ] Returns whether image brightness is increased by 20% when the mouse is over the object.
        bool isLightenOnMouse() const;
#endif
#ifdef MUIA_Dtpic_MinHeight
        /// @brief [ @b MUIA_Dtpic_MinHeight ] Returns whether the image's minimum height limit is enabled.
        bool isMinHeight() const;
#endif
#ifdef MUIA_Dtpic_MinWidth
        /// @brief [ @b MUIA_Dtpic_MinWidth ] Returns whether the image's minimum width limit is enabled.
        bool isMinWidth() const;
#endif
#ifdef MUIA_Dtpic_Name
        /// @brief [ @b MUIA_Dtpic_Name ] Returns the file name of the currently loaded image.
        std::string getName() const;
#endif
#ifdef MUIA_Dtpic_Alpha
        /// @brief [ @b MUIA_Dtpic_Alpha ] Sets the alpha blending value (0..255) applied when blitting the image. Has no effect on CLUT
        /// (<=8 bit) screens.
        Dtpic &setAlpha(const long alpha);
#endif
#ifdef MUIA_Dtpic_Fade
        /// @brief [ @b MUIA_Dtpic_Fade ] Sets the fade step for alpha transitions. Positive = step size (applied every 20ms); negative =
        /// stop fade and apply final alpha immediately.
        Dtpic &setFade(const long fade);
#endif
#ifdef MUIA_Dtpic_Name
        /// @brief [ @b MUIA_Dtpic_Name ] Sets the file name of the image to load via datatypes.library. The string is copied internally.
        Dtpic &setName(const std::string &name);
#endif
    };

    template <typename T, typename U> class DtpicBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        DtpicBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Dtpic)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

#ifdef MUIA_Dtpic_Alpha
        /// @brief [ @b MUIA_Dtpic_Alpha ]
        /// Specify an additional alpha value to be applied when blitting the loaded image onto the screen. The value of MUIA_Dtpic_Alpha is
        /// an 8bit value specifying the intensity of the alpha blitting. You usually want to specify 0xff. Alpha blitting won't work on
        /// CLUT (i.e. depth <= 8 bit) screens.
        T &tagAlpha(const long alpha);
#endif
#ifdef MUIA_Dtpic_DarkenSelState
        /// @brief [ @b MUIA_Dtpic_DarkenSelState ]
        /// If set to true the image's brightness will decreased by 50% whenever the left mouse button is pressed on the object.
        T &tagDarkenSelState(const bool darkenSelState);
#endif
#ifdef MUIA_Dtpic_FreeHoriz
        /// @brief [ @b MUIA_Dtpic_FreeHoriz ]
        /// If set to true the image is allowed to scale freely in horizontal direction.
        T &tagFreeHoriz(const bool freeHoriz);
#endif
#ifdef MUIA_Dtpic_FreeVert
        /// @brief [ @b MUIA_Dtpic_FreeVert ]
        /// If set to true the image is allowed to scale freely in vertical direction.
        T &tagFreeVert(const bool freeVert);
#endif
#ifdef MUIA_Dtpic_Fade
        /// @brief [ @b MUIA_Dtpic_Fade ]
        /// Setting this attribute to a positive value while also changing the image's alpha value will let Dtpic class do a fade between
        /// the previous and the new alpha value. This allows images to be faded in our out. Depending on the fading direction between the
        /// current and the final alpha value the specified value will be repeatedly added or subtracted respectively to the current alpha
        /// value with a delay of 20ms until the final alpha value has been reached.
        /// For negative values the fading process will be stopped and the final alpha value will be set immediately.
        T &tagFade(const long fade);
#endif
#ifdef MUIA_Dtpic_LightenOnMouse
        /// @brief [ @b MUIA_Dtpic_LightenOnMouse ]
        /// If set to true the image's brightness will increased by 20% whenever the mouse is moved over the object.
        T &tagLightenOnMouse(const bool lightenOnMouse);
#endif
#ifdef MUIA_Dtpic_MinHeight
        /// @brief [ @b MUIA_Dtpic_MinHeight ]
        /// If set to true the image's minimum height limit is enabled.
        T &tagMinHeight(const bool minHeight);
#endif
#ifdef MUIA_Dtpic_MinWidth
        /// @brief [ @b MUIA_Dtpic_MinWidth ]
        /// If set to true the image's minimum width limit is enabled.
        T &tagMinWidth(const bool minWidth);
#endif
#ifdef MUIA_Dtpic_Name
        /// @brief [ @b MUIA_Dtpic_Name ]
        /// Specify the name of the image file to be loaded using datatypes.library. This attribute is absolutely required.
        /// Dtpic class will remember the passed string pointer during OM_NEW and OM_SET, but the string will NOT be copied.
        /// The string is copied and stored internally by this C++ wrapper!
        T &tagName(const std::string &name);
#endif
    };

    class DtpicBuilder : public DtpicBuilderTemplate<DtpicBuilder, Dtpic>
    {
      public:
        DtpicBuilder();
    };
}

#define MUI_DTPIC_TPP_INCLUDE
#include "Dtpic.tpp"
#undef MUI_DTPIC_TPP_INCLUDE
