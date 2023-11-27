//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Notify.hpp"

#undef Insert
#undef Remove

namespace MUI
{
    class Family : public Notify
    {
      public:
        Family(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Family(const APTR pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Family(const Root &root)
          : Notify(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        // methods, some returns object reference

        /// @brief [ @b MUIM_Family_Insert ]
        Family &Insert(const MUI::Root &obj, const MUI::Root &pred);
        /// @brief [ @b MUIM_Family_Remove ]
        Family &Remove(const MUI::Root &obj);
    };

    template <typename T, typename U> class FamilyBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        FamilyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Family)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Family_Child ]
        T &tagChild(const MUI::Root &child);
        /// @brief [ @b MUIA_Family_Child ]
        T &tagChild(const Object *child);
    };

    class FamilyBuilder : public FamilyBuilderTemplate<FamilyBuilder, Family>
    {
      public:
        FamilyBuilder();
    };

    template <typename T, typename U> inline T &FamilyBuilderTemplate<T, U>::tagChild(const MUI::Root &child)
    {
        this->PushTag(MUIA_Family_Child, child.muiObject(), false);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FamilyBuilderTemplate<T, U>::tagChild(const Object *child)
    {
        if (child)
            this->PushTag(MUIA_Family_Child, child, false);
        return (T &)*this;
    }
}
