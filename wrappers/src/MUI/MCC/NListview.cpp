//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "NListview.hpp"

#include <proto/alib.h>
#include <stdexcept>

namespace MUI::MCC
{
    const std::string NListview::className = MUIC_NListview;

    NList NListview::getNList() const
    {
        return NList(GetValueAsObjectPtr(MUIA_NListview_NList));
    }

    enum NListview_VSB NListview::getVert_ScrollBar() const
    {
        return NListview_VSB(GetValueAsLong(MUIA_NListview_Vert_ScrollBar));
    }

    enum NListview_HSB NListview::getHoriz_ScrollBar() const
    {
        return NListview_HSB(GetValueAsLong(MUIA_NListview_Horiz_ScrollBar));
    }

    long NListview::getVSB_Width() const
    {
        return GetValueAsLong(MUIA_NListview_VSB_Width);
    }

    long NListview::getHSB_Height() const
    {
        return GetValueAsLong(MUIA_NListview_HSB_Height);
    }

    NListview &NListview::setVert_ScrollBar(const enum NListview_VSB vert_ScrollBar)
    {
        SetValue(MUIA_NListview_Vert_ScrollBar, (long)vert_ScrollBar);
        return *this;
    }

    NListview &NListview::setHoriz_ScrollBar(const enum NListview_HSB horiz_ScrollBar)
    {
        SetValue(MUIA_NListview_Horiz_ScrollBar, (long)horiz_ScrollBar);
        return *this;
    }

    NListviewBuilder::NListviewBuilder()
      : AreaBuilderTemplate(MUI::EmptyUniqueId, NListview::className)
      , hasNListObject(false)
    {
    }

    NListviewBuilder &NListviewBuilder::tagNList(const NList &list)
    {
        hasNListObject = true;
        PushTag(MUIA_NListview_NList, list.muiObject());
        return *this;
    }

    NListviewBuilder &NListviewBuilder::tagVert_ScrollBar(const enum NListview_VSB vert_ScrollBar)
    {
        PushTag(MUIA_NListview_Vert_ScrollBar, (long)vert_ScrollBar);
        return *this;
    }

    NListviewBuilder &NListviewBuilder::tagHoriz_ScrollBar(const enum NListview_HSB horiz_ScrollBar)
    {
        PushTag(MUIA_NListview_Horiz_ScrollBar, (long)horiz_ScrollBar);
        return *this;
    }

    NListview NListviewBuilder::object() const
    {
        // Each listview needs a list object as child. The list object is mandatory for NListview, without it object will fail on creation.
        // So check if there is tag for NList (MUIA_NListview_NList).
        if (!hasNListObject)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + ", missing NList object for NListview!";
            throw std::runtime_error(error);
        }

        return AreaBuilderTemplate::object();
    }

    NListview NListviewBuilder::object(const unsigned long dataSize, const void *pDispatcher) const
    {
        // Each listview needs a list object as child. The list object is mandatory for NListview, without it object will fail on creation.
        // So check if there is tag for NList (MUIA_NListview_NList).
        if (!hasNListObject)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + ", missing NList object for NListview!";
            throw std::runtime_error(error);
        }

        return AreaBuilderTemplate::object();
    }
}
