//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_FONTPANEL_TPP_INCLUDE
#error "File Fontpanel.tpp can not be included directly, include file Fontpanel.hpp instead!"
#endif

namespace MUI
{
#ifdef MUIA_Fontpanel_ShowCollection
    template <typename T, typename U>
    inline T &FontpanelBuilderTemplate<T, U>::tagShowCollection(const enum Fontpanel_ShowCollection showCollection)
    {
        this->PushTag(MUIA_Fontpanel_ShowCollection, static_cast<long>(showCollection));
        return (T &)*this;
    }

    template <typename T, typename U>
    inline T &FontpanelBuilderTemplate<T, U>::tagShowCollection(const std::set<enum Fontpanel_ShowCollection> &showCollections)
    {
        long showCollection = 0;
        for (auto &value : showCollections)
            showCollection |= static_cast<long>(value);
        this->PushTag(MUIA_Fontpanel_ShowCollection, showCollection);
        return (T &)*this;
    }
#endif
}
