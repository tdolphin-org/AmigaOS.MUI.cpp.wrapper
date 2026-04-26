//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_POPOBJECT_TPP_INCLUDE
#error "Popobject.tpp should only be included by Popobject.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagFollow(const bool follow)
    {
        this->PushTag(MUIA_Popobject_Follow, follow);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagLight(const bool light)
    {
        this->PushTag(MUIA_Popobject_Light, light);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagObject(const Object *object)
    {
        this->PushTag(MUIA_Popobject_Object, object);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagObjStrHook(const Hook *objStrHook)
    {
        this->PushTag(MUIA_Popobject_ObjStrHook, objStrHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagStrObjHook(const Hook *strObjHook)
    {
        this->PushTag(MUIA_Popobject_StrObjHook, strObjHook);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagVolatile(const bool vol)
    {
        this->PushTag(MUIA_Popobject_Volatile, vol);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &PopobjectBuilderTemplate<T, U>::tagWindowHook(const Hook *windowHook)
    {
        this->PushTag(MUIA_Popobject_WindowHook, windowHook);
        return (T &)*this;
    }
}
