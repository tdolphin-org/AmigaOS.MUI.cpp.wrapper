//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    class Virtgroup : public Group
    {
      public:
        Virtgroup(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference
    };

    template <typename T, typename U> class VirtgroupBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        VirtgroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Virtgroup)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Virtgroup_Input ]
        T &tagInput(const bool input);
        /// @brief [ @b MUIA_Virtgroup_Left ]
        T &tagLeft(const long left);
        /// @brief [ @b MUIA_Virtgroup_Top ]
        T &tagTop(const long top);
        /// @brief [ @b MUIA_Virtgroup_TryFit ]
        T &tagTryFit(const bool tryFit);
    };

    class VirtgroupBuilder : public VirtgroupBuilderTemplate<VirtgroupBuilder, Virtgroup>
    {
      public:
        VirtgroupBuilder();
    };

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagInput(const bool input)
    {
        this->PushTag(MUIA_Virtgroup_Input, input);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagLeft(const long left)
    {
        this->PushTag(MUIA_Virtgroup_Left, left);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagTop(const long top)
    {
        this->PushTag(MUIA_Virtgroup_Top, top);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &VirtgroupBuilderTemplate<T, U>::tagTryFit(const bool tryFit)
    {
        this->PushTag(MUIA_Virtgroup_TryFit, tryFit);
        return (T &)*this;
    }
}
