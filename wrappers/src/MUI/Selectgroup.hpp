//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2026 TDolphin
//

#pragma once

#ifdef AOS_MUI_VERSION_5

#include "Group.hpp"

#include "ValueTypes/Selectgroup/Active.hpp"

namespace MUI
{
    /// @brief Selectgroup objects combine radio buttons and labels or other visible objects into a group of selectable options.
    class Selectgroup : public Group
    {
      public:
        explicit Selectgroup(Object *pMuiObject)
          : Group(pMuiObject)
        {
        }

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class SelectgroupBuilderTemplate : public GroupBuilderTemplate<T, U>
    {
      public:
        SelectgroupBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Selectgroup)
          : GroupBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Selectgroup_Active ]
        T &tagActive(long active);
        /// @brief [ @b MUIA_Selectgroup_Active ] (typed)
        T &tagActive(ValueTypes::Selectgroup::Active active);

      protected:
        bool Validate() const override;
    };

    class SelectgroupBuilder : public SelectgroupBuilderTemplate<SelectgroupBuilder, Selectgroup>
    {
      public:
        SelectgroupBuilder();
    };
}

#define MUI_SELECTGROUP_TPP_INCLUDE
#include "Selectgroup.tpp"
#undef MUI_SELECTGROUP_TPP_INCLUDE

#endif // AOS_MUI_VERSION_5
