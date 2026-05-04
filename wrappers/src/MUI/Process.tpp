//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#ifndef MUI_PROCESS_TPP_INCLUDE
#error "Process.tpp should only be included by Process.hpp"
#endif

namespace MUI
{
    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagAutoLaunch(const bool autoLaunch)
    {
        this->PushTag(MUIA_Process_AutoLaunch, autoLaunch);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagName(const unsigned long name)
    {
        this->PushTag(MUIA_Process_Name, name);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagPriority(const unsigned long priority)
    {
        this->PushTag(MUIA_Process_Priority, priority);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagSourceClass(const unsigned long sourceClass)
    {
        this->PushTag(MUIA_Process_SourceClass, sourceClass);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagSourceObject(const unsigned long sourceObject)
    {
        this->PushTag(MUIA_Process_SourceObject, sourceObject);
        return (T &)*this;
    }

    template <typename T, typename U> inline T &ProcessBuilderTemplate<T, U>::tagStackSize(const unsigned long stackSize)
    {
        this->PushTag(MUIA_Process_StackSize, stackSize);
        return (T &)*this;
    }
}
