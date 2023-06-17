//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
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

        Balance(const APTR pMuiObject)
          : Area(pMuiObject)
        {
        }

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, MUIC_Balance);
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
        T &tagQuiet(const long quiet);
    };

    class BalanceBuilder : public BalanceBuilderTemplate<BalanceBuilder, Balance>
    {
      public:
        BalanceBuilder();
    };

    template <typename T, typename U> inline T &BalanceBuilderTemplate<T, U>::tagQuiet(const long quiet)
    {
        this->PushTag(MUIA_Balance_Quiet, quiet);
        return (T &)*this;
    }
}
