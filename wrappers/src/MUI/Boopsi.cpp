//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Boopsi.hpp"

namespace MUI
{
    const std::string Boopsi::className = MUIC_Boopsi;

    BoopsiBuilder::BoopsiBuilder() { }

    struct IClass *Boopsi::getClass() const
    {
        return static_cast<struct IClass *>(GetValueAsPtr(MUIA_Boopsi_Class));
    }

    Boopsi &Boopsi::setClass(struct IClass *pClass)
    {
        SetValue(MUIA_Boopsi_Class, pClass);
        return *this;
    }

    std::string Boopsi::getClassID() const
    {
        return GetValueAsString(MUIA_Boopsi_ClassID);
    }

    Boopsi &Boopsi::setClassID(const std::string &classID)
    {
        SetValue(MUIA_Boopsi_ClassID, StoreString(MUIA_Boopsi_ClassID, classID));
        return *this;
    }

    unsigned long Boopsi::getMaxHeight() const
    {
        return GetValueAsULong(MUIA_Boopsi_MaxHeight);
    }

    Boopsi &Boopsi::setMaxHeight(const unsigned long maxHeight)
    {
        SetValue(MUIA_Boopsi_MaxHeight, maxHeight);
        return *this;
    }

    unsigned long Boopsi::getMaxWidth() const
    {
        return GetValueAsULong(MUIA_Boopsi_MaxWidth);
    }

    Boopsi &Boopsi::setMaxWidth(const unsigned long maxWidth)
    {
        SetValue(MUIA_Boopsi_MaxWidth, maxWidth);
        return *this;
    }

    unsigned long Boopsi::getMinHeight() const
    {
        return GetValueAsULong(MUIA_Boopsi_MinHeight);
    }

    Boopsi &Boopsi::setMinHeight(const unsigned long minHeight)
    {
        SetValue(MUIA_Boopsi_MinHeight, minHeight);
        return *this;
    }

    unsigned long Boopsi::getMinWidth() const
    {
        return GetValueAsULong(MUIA_Boopsi_MinWidth);
    }

    Boopsi &Boopsi::setMinWidth(const unsigned long minWidth)
    {
        SetValue(MUIA_Boopsi_MinWidth, minWidth);
        return *this;
    }

    Object *Boopsi::getObject() const
    {
        return GetValueAsObjectPtr(MUIA_Boopsi_Object);
    }

    unsigned long Boopsi::getTagDrawInfo() const
    {
        return GetValueAsULong(MUIA_Boopsi_TagDrawInfo);
    }

    Boopsi &Boopsi::setTagDrawInfo(const unsigned long tagDrawInfo)
    {
        SetValue(MUIA_Boopsi_TagDrawInfo, tagDrawInfo);
        return *this;
    }

    unsigned long Boopsi::getTagScreen() const
    {
        return GetValueAsULong(MUIA_Boopsi_TagScreen);
    }

    Boopsi &Boopsi::setTagScreen(const unsigned long tagScreen)
    {
        SetValue(MUIA_Boopsi_TagScreen, tagScreen);
        return *this;
    }

    unsigned long Boopsi::getTagWindow() const
    {
        return GetValueAsULong(MUIA_Boopsi_TagWindow);
    }

    Boopsi &Boopsi::setTagWindow(const unsigned long tagWindow)
    {
        SetValue(MUIA_Boopsi_TagWindow, tagWindow);
        return *this;
    }
}
