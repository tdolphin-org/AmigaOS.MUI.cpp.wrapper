//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_SLAVE_TPP_INCLUDE
#error "Slave.tpp should only be included by Slave.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &SlaveBuilderTemplate<T, U>::tagApplication(Object *application)
    {
        this->PushTag(MUIA_Slave_Application, application);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &SlaveBuilderTemplate<T, U>::tagClass(Object *muiClass)
    {
        this->PushTag(MUIA_Slave_Class, muiClass);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &SlaveBuilderTemplate<T, U>::tagObject(Object *object)
    {
        this->PushTag(MUIA_Slave_Object, object);
        return (T &)*this;
    }
}
