//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#include "BoardsList.hpp"

#include "Components/DataTypes/BoardRef.hpp"
#include "Components/MCC/BoardsList.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

namespace Components
{
    BoardsList::BoardsList()
      : mList(MCC::BoardsListBuilder().tagFormat("BAR,").tagTitle(true).tagFrame(MUI::Frame::Group).object())
      , mComponent(MUI::ListviewBuilder().tagList(mList).object())
    {

        auto item1 = BoardRef { MUIX_B "[0x0a0a] " MUIX_N "Sega", MUIX_B "[0x0a0a] " MUIX_N "Saturn" };
        auto item2 = BoardRef { MUIX_B "[0x0a0a] " MUIX_N "Sony", MUIX_B "[0x0a0a] " MUIX_N "PlayStation" };
        auto item3 = BoardRef { MUIX_B "[0x0a0a] " MUIX_N "Nintendo", MUIX_B "[0x0a0a] " MUIX_N "Switch" };
        auto item4 = BoardRef { MUIX_B "[0x0a0a] " MUIX_N "Microsoft", MUIX_B "[0x0a0a] " MUIX_N "Xbox" };

        mList.InsertSingleBottom(&item1);
        mList.InsertSingleBottom(&item2);
        mList.InsertSingleBottom(&item3);
        mList.InsertSingleBottom(&item4);
    }
}
