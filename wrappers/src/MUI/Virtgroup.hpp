//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Group.hpp"

namespace MUI
{
    class Virtgroup : public Group
    {
      public:
        explicit Virtgroup(Object *pMuiObject)
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
#ifdef MUIA_Virtgroup_TryFit
        /// @brief [ @b MUIA_Virtgroup_TryFit ]
        T &tagTryFit(const bool tryFit);
#endif
    };

    class VirtgroupBuilder : public VirtgroupBuilderTemplate<VirtgroupBuilder, Virtgroup>
    {
      public:
        VirtgroupBuilder();
    };
}

#define MUI_VIRTGROUP_TPP_INCLUDE
#include "Virtgroup.tpp"
#undef MUI_VIRTGROUP_TPP_INCLUDE
