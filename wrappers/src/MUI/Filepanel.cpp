//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Filepanel.hpp"

#ifdef MUIC_Filepanel

#include <proto/alib.h>

namespace MUI
{
    const std::string Filepanel::className = MUIC_Filepanel;

    FilepanelBuilder::FilepanelBuilder() { }

    std::string Filepanel::getAcceptPattern() const
    {
        return GetValueAsString(MUIA_Filepanel_AcceptPattern);
    }

    bool Filepanel::isDoMultiSelect() const
    {
        return GetValueAsBool(MUIA_Filepanel_DoMultiSelect);
    }

    bool Filepanel::isDoPatterns() const
    {
        return GetValueAsBool(MUIA_Filepanel_DoPatterns);
    }

    bool Filepanel::isDoSaveMode() const
    {
        return GetValueAsBool(MUIA_Filepanel_DoSaveMode);
    }

    std::string Filepanel::getDrawer() const
    {
        return GetValueAsString(MUIA_Filepanel_Drawer);
    }

    bool Filepanel::isDrawersOnly() const
    {
        return GetValueAsBool(MUIA_Filepanel_DrawersOnly);
    }

    std::string Filepanel::getFile() const
    {
        return GetValueAsString(MUIA_Filepanel_File);
    }

    bool Filepanel::isFilterDrawers() const
    {
        return GetValueAsBool(MUIA_Filepanel_FilterDrawers);
    }

    Hook *Filepanel::getFilterFunc() const
    {
        return GetValueAsHookPtr(MUIA_Filepanel_FilterFunc);
    }

    std::string Filepanel::getPattern() const
    {
        return GetValueAsString(MUIA_Filepanel_Pattern);
    }

    bool Filepanel::isRejectIcons() const
    {
        return GetValueAsBool(MUIA_Filepanel_RejectIcons);
    }

    std::string Filepanel::getRejectPattern() const
    {
        return GetValueAsString(MUIA_Filepanel_RejectPattern);
    }

    Filepanel &Filepanel::setDrawer(const char *drawer)
    {
        if (drawer == nullptr)
        {
            ClearStoredString(MUIA_Filepanel_Drawer);
            SetValue(MUIA_Filepanel_Drawer, nullptr);
        }
        else
            SetValue(MUIA_Filepanel_Drawer, StoreString(MUIA_Filepanel_Drawer, std::string { drawer }));

        return *this;
    }

    Filepanel &Filepanel::setDrawer(const std::string &drawer)
    {
        SetValue(MUIA_Filepanel_Drawer, StoreString(MUIA_Filepanel_Drawer, drawer));
        return *this;
    }

    Filepanel &Filepanel::setFile(const char *file)
    {
        if (file == nullptr)
        {
            ClearStoredString(MUIA_Filepanel_File);
            SetValue(MUIA_Filepanel_File, nullptr);
        }
        else
            SetValue(MUIA_Filepanel_File, StoreString(MUIA_Filepanel_File, std::string { file }));

        return *this;
    }

    Filepanel &Filepanel::setFile(const std::string &file)
    {
        SetValue(MUIA_Filepanel_File, StoreString(MUIA_Filepanel_File, file));
        return *this;
    }

    Filepanel &Filepanel::setPattern(const char *pattern)
    {
        if (pattern == nullptr)
        {
            ClearStoredString(MUIA_Filepanel_Pattern);
            SetValue(MUIA_Filepanel_Pattern, nullptr);
        }
        else
            SetValue(MUIA_Filepanel_Pattern, StoreString(MUIA_Filepanel_Pattern, std::string { pattern }));

        return *this;
    }

    Filepanel &Filepanel::setPattern(const std::string &pattern)
    {
        SetValue(MUIA_Filepanel_Pattern, StoreString(MUIA_Filepanel_Pattern, pattern));
        return *this;
    }

#ifdef MUIM_Filepanel_AddRow
    Filepanel &Filepanel::AddRow(const Object *label, const Object *contents)
    {
        DoMethod(muiObject(), MUIM_Filepanel_AddRow, label, contents);
        return *this;
    }

    Filepanel &Filepanel::AddRow(const Root &label, const Root &contents)
    {
        return AddRow(label.muiObject(), contents.muiObject());
    }
#endif
}

#endif
