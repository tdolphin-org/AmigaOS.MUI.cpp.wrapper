//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Popobject.hpp"

namespace MUI
{
    const std::string Popobject::className = MUIC_Popobject;

    PopobjectBuilder::PopobjectBuilder() { }

    bool Popobject::isFollow() const
    {
        return GetValueAsBool(MUIA_Popobject_Follow);
    }

    bool Popobject::isLight() const
    {
        return GetValueAsBool(MUIA_Popobject_Light);
    }

    bool Popobject::isVolatile() const
    {
        return GetValueAsBool(MUIA_Popobject_Volatile);
    }

    Object *Popobject::getObject() const
    {
        return GetValueAsObjectPtr(MUIA_Popobject_Object);
    }

    Hook *Popobject::getObjStrHook() const
    {
        return GetValueAsHookPtr(MUIA_Popobject_ObjStrHook);
    }

    Hook *Popobject::getStrObjHook() const
    {
        return GetValueAsHookPtr(MUIA_Popobject_StrObjHook);
    }

    Hook *Popobject::getWindowHook() const
    {
        return GetValueAsHookPtr(MUIA_Popobject_WindowHook);
    }

    Popobject &Popobject::setFollow(const bool follow)
    {
        SetValue(MUIA_Popobject_Follow, follow);
        return *this;
    }

    Popobject &Popobject::setLight(const bool light)
    {
        SetValue(MUIA_Popobject_Light, light);
        return *this;
    }

    Popobject &Popobject::setVolatile(const bool vol)
    {
        SetValue(MUIA_Popobject_Volatile, vol);
        return *this;
    }

    Popobject &Popobject::setObjStrHook(const Hook *objStrHook)
    {
        SetValue(MUIA_Popobject_ObjStrHook, objStrHook);
        return *this;
    }

    Popobject &Popobject::setStrObjHook(const Hook *strObjHook)
    {
        SetValue(MUIA_Popobject_StrObjHook, strObjHook);
        return *this;
    }

    Popobject &Popobject::setWindowHook(const Hook *windowHook)
    {
        SetValue(MUIA_Popobject_WindowHook, windowHook);
        return *this;
    }
}
