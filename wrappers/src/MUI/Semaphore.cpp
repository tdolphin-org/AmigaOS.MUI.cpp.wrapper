//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Semaphore.hpp"

#include <proto/alib.h>

namespace MUI
{
    const std::string Semaphore::className = MUIC_Semaphore;

    SemaphoreBuilder::SemaphoreBuilder() { }

    unsigned long Semaphore::Attempt()
    {
        return DoMethod(muiObject(), MUIM_Semaphore_Attempt);
    }

    unsigned long Semaphore::AttemptShared()
    {
        return DoMethod(muiObject(), MUIM_Semaphore_AttemptShared);
    }

    Semaphore &Semaphore::Obtain()
    {
        DoMethod(muiObject(), MUIM_Semaphore_Obtain);
        return *this;
    }

    Semaphore &Semaphore::ObtainShared()
    {
        DoMethod(muiObject(), MUIM_Semaphore_ObtainShared);
        return *this;
    }

    Semaphore &Semaphore::Release()
    {
        DoMethod(muiObject(), MUIM_Semaphore_Release);
        return *this;
    }
}
