//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_FAMILY_TPP_INCLUDE
#error "File Family.tpp can not be included directly, include file Family.hpp instead!"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &FamilyBuilderTemplate<T, U>::tagChild(const MUI::Root &child)
    {
        this->PushTag(MUIA_Family_Child, child.muiObject(), false);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &FamilyBuilderTemplate<T, U>::tagChild(const Object *child)
    {
        if (child)
            this->PushTag(MUIA_Family_Child, child, false);
        return (T &)*this;
    }
}
