//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_VOLUMELIST_TPP_INCLUDE
#error "Do not include Volumelist.tpp directly! It is included by Volumelist.hpp."
#endif

namespace MUI
{
#ifdef MUIA_Volumelist_ExampleMode
    template <typename T, typename U> inline T &VolumelistBuilderTemplate<T, U>::tagExampleMode(const bool exampleMode)
    {
        this->PushTag(MUIA_Volumelist_ExampleMode, exampleMode);
        return (T &)*this;
    }
#endif
}
