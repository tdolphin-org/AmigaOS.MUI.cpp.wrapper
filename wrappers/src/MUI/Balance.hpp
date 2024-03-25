//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include "Area.hpp"

namespace MUI
{
    class Balance : public Area
    {
      public:
        Balance(const Object *pMuiObject)
          : Area(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }
    };

    template <typename T, typename U> class BalanceBuilderTemplate : public AreaBuilderTemplate<T, U>
    {
      public:
        BalanceBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Balance)
          : AreaBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Balance_Quiet ]
        /// If set to true the balance object will show its frame only if the mouse is located over the object. Otherwise it will be
        /// invisible. By default is false.
        T &tagQuiet(const bool quiet);
    };

    class BalanceBuilder : public BalanceBuilderTemplate<BalanceBuilder, Balance>
    {
      public:
        BalanceBuilder();
    };

    template <typename T, typename U> inline T &BalanceBuilderTemplate<T, U>::tagQuiet(const bool quiet)
    {
        this->PushTag(MUIA_Balance_Quiet, quiet);
        return (T &)*this;
    }
}
