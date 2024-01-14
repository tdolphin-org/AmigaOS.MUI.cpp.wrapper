//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <proto/asl.h>

#include "Popstring.hpp"

namespace MUI
{
    class Popasl : public Popstring
    {
      public:
        Popasl(const Object *pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        Popasl(const APTR pMuiObject)
          : Popstring(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Popasl_Active ]
        bool isActive() const;
        /// @brief [ @b MUIA_Popasl_StartHook ]
        Hook *getStartHook() const;
        /// @brief [ @b MUIA_Popasl_StopHook ]
        Hook *getStopHook() const;
        /// @brief [ @b MUIA_Popasl_Type ]
        unsigned long getType() const;

        /// @brief [ @b MUIA_Popasl_StartHook ]
        Popasl &setStartHook(const Hook *startHook);
        /// @brief [ @b MUIA_Popasl_StopHook ]
        Popasl &setStopHook(const Hook *stopHook);
    };

    template <typename T, typename U> class PopaslBuilderTemplate : public PopstringBuilderTemplate<T, U>
    {
      public:
        PopaslBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Popasl)
          : PopstringBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Popasl_StartHook ]
        T &tagStartHook(const Hook *startHook);
        /// @brief [ @b MUIA_Popasl_StopHook ]
        T &tagStopHook(const Hook *stopHook);
        /// @brief [ @b MUIA_Popasl_Type ]
        T &tagType(const unsigned long type);

        // File requester tags

        /// @brief [ @b ASLFR_TitleText ]
        T &tagAslFrTitleText(const char *titleText);
        /// @brief [ @b ASLFR_TitleText ]
        T &tagAslFrTitleText(const std::string &titleText);
        /// @brief [ @b ASLFR_DoPatterns ]
        T &tagAslFrDoPatterns(const bool doPatterns = true);
        /// @brief [ @b ASLFR_DrawersOnly ]
        T &tagAslFrDrawersOnly(const bool drawersOnly = true);
        /// @brief [ @b ASLFR_RejectIcons ]
        T &tagAslFrRejectIcons(const bool rejectIcons = true);
        /// @brief [ @b ASLFR_RejectPattern ]
        T &tagAslFrRejectPattern(const std::string &rejectPattern);
        /// @brief [ @b ASLFR_AcceptPattern ]
        T &tagAslFrAcceptPattern(const std::string &acceptPattern);
        /// @brief [ @b ASLFR_FilterDrawers ]
        T &tagAslFrFilterDrawers(const bool filterDrawers = true);
    };

    class PopaslBuilder : public PopaslBuilderTemplate<PopaslBuilder, Popasl>
    {
      public:
        PopaslBuilder();
    };

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagStartHook(const Hook *startHook)
    {
        this->PushTag(MUIA_Popasl_StartHook, startHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagStopHook(const Hook *stopHook)
    {
        this->PushTag(MUIA_Popasl_StopHook, stopHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagType(const unsigned long type)
    {
        this->PushTag(MUIA_Popasl_Type, type);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const char *titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrTitleText(const std::string &titleText)
    {
        this->PushTag(ASLFR_TitleText, titleText);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrDoPatterns(const bool doPatterns)
    {
        this->PushTag(ASLFR_DoPatterns, doPatterns);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrDrawersOnly(const bool drawersOnly)
    {
        this->PushTag(ASLFR_DrawersOnly, drawersOnly);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrRejectIcons(const bool rejectIcons)
    {
        this->PushTag(ASLFR_RejectIcons, rejectIcons);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrRejectPattern(const std::string &rejectPattern)
    {
        this->PushTag(ASLFR_RejectPattern, rejectPattern);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrAcceptPattern(const std::string &acceptPattern)
    {
        this->PushTag(ASLFR_AcceptPattern, acceptPattern);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopaslBuilderTemplate<T, U>::tagAslFrFilterDrawers(const bool filterDrawers)
    {
        this->PushTag(ASLFR_FilterDrawers, filterDrawers);
        return (T &)*this;
    }
}
