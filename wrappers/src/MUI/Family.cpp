//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#include "Family.hpp"

#include <clib/alib_protos.h>

namespace MUI
{
    const std::string Family::className = MUIC_Family;

    FamilyBuilder::FamilyBuilder() { }

    Family &Family::Insert(const MUI::Root &obj, const MUI::Root &pred)
    {
        DoMethod(muiObject(), MUIM_Family_Insert, obj.muiObject(), pred.muiObject());
        return *this;
    }

    Family &Family::Remove(const MUI::Root &obj)
    {
        DoMethod(muiObject(), MUIM_Family_Remove, obj.muiObject());
        return *this;
    }
}
