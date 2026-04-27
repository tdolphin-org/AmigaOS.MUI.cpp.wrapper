//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_BOOPSI_TPP_INCLUDE
#error "Boopsi.tpp should only be included by Boopsi.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagClass(struct IClass *pClass)
    {
        this->PushTag(MUIA_Boopsi_Class, pClass);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagClassID(const std::string &classID)
    {
        this->PushTag(MUIA_Boopsi_ClassID, this->StoreString(MUIA_Boopsi_ClassID, classID));
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagMaxHeight(const unsigned long maxHeight)
    {
        this->PushTag(MUIA_Boopsi_MaxHeight, maxHeight);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagMaxWidth(const unsigned long maxWidth)
    {
        this->PushTag(MUIA_Boopsi_MaxWidth, maxWidth);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagMinHeight(const unsigned long minHeight)
    {
        this->PushTag(MUIA_Boopsi_MinHeight, minHeight);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagMinWidth(const unsigned long minWidth)
    {
        this->PushTag(MUIA_Boopsi_MinWidth, minWidth);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagRemember(const unsigned long tagID)
    {
        this->PushTag(MUIA_Boopsi_Remember, tagID);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagSmart(const bool smart)
    {
        this->PushTag(MUIA_Boopsi_Smart, smart);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagTagDrawInfo(const unsigned long tagDrawInfo)
    {
        this->PushTag(MUIA_Boopsi_TagDrawInfo, tagDrawInfo);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagTagScreen(const unsigned long tagScreen)
    {
        this->PushTag(MUIA_Boopsi_TagScreen, tagScreen);
        return (T &)*this;
    }

    template <typename T, typename U> T &BoopsiBuilderTemplate<T, U>::tagTagWindow(const unsigned long tagWindow)
    {
        this->PushTag(MUIA_Boopsi_TagWindow, tagWindow);
        return (T &)*this;
    }
}
