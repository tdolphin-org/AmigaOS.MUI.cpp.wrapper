//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Process.hpp"

#ifdef MUIC_Process

#include <proto/alib.h>

namespace MUI
{
    const std::string Process::className = MUIC_Process;

    ProcessBuilder::ProcessBuilder() { }

    struct Task *Process::getTask() const
    {
        return static_cast<struct Task *>(GetValueAsPtr(MUIA_Process_Task));
    }

    bool Process::Kill(const long maxdelay)
    {
        return DoMethod(muiObject(), MUIM_Process_Kill, maxdelay);
    }

    Process &Process::Launch()
    {
        DoMethod(muiObject(), MUIM_Process_Launch);
        return *this;
    }

#ifdef __MORPHOS__
    Process &Process::Process_(ULONG *kill, Boopsiobject *proc)
#else
    Process &Process::Process_(ULONG *kill, Object *proc)
#endif
    {
        DoMethod(muiObject(), MUIM_Process_Process, kill, proc);
        return *this;
    }

    Process &Process::Signal(const unsigned long sigs)
    {
        DoMethod(muiObject(), MUIM_Process_Signal, sigs);
        return *this;
    }
}

#endif
