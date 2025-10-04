//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#pragma once

#include "Components/Core/Root.hpp"

#include "MUI/Group.hpp"
#include "MUI/Listview.hpp"

namespace Components
{
    class BoardsList : public Root
    {
        MUI::List mList;

        MUI::Listview mComponent;

      public:
        BoardsList();

        operator MUI::Listview &()
        {
            return mComponent;
        }

      protected:
        const MUI::Notify &muiNotify() const
        {
            return mComponent;
        }
    };
}