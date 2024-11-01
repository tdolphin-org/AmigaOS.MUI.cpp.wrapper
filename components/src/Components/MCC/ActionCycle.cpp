//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#include "ActionCycle.hpp"

#ifdef TRACE_CUSTOM_COMPONENTS
#include <iostream>
#endif

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "MUI/Notifier/Notifier.hpp"

#include "SDI/SDI_compiler.h"
#include "SDI/SDI_hook.h"

unsigned long methodActionCycleActive(struct IClass *cl, Object *obj, Msg msg)
{
    Components::MCC::CustomObjectData *pData = reinterpret_cast<Components::MCC::CustomObjectData *> INST_DATA(cl, obj);
    if (pData->pDispatcher != nullptr)
        return reinterpret_cast<Components::MCC::ActionCycleDispatcher *>(pData->pDispatcher)->OnCycle();

    return 0;
}

DISPATCHER(ActionCycleDispatcherFunc)
{
    // Be careful with std::cout, when here is some "debug" info !!!
    // It causes that MUI interface hangs during "drag&drop"!
    // std::cout << __PRETTY_FUNCTION__ << std::hex << "MethodID: 0x" << msg->MethodID << std::endl;

    switch (msg->MethodID)
    {
        case MUIM_ActionOnActive:
            return methodActionCycleActive(cl, obj, (Msg)msg);
        default:
        {
            auto dispatchMethodResult = Components::MCC::dispatchMethod(msg->MethodID, cl, obj, msg);
            if (dispatchMethodResult.dispatchResult)
                return dispatchMethodResult.methodResult;
        }
    }

    return DoSuperMethodA(cl, obj, msg);
}

namespace Components::MCC
{
    ActionCycleBuilder::ActionCycleBuilder()
      : MUI::CycleBuilderTemplate<ActionCycleBuilder, ActionRoot<MUI::Cycle>>("ActionCycle")
    {
    }

    ActionRoot<MUI::Cycle> ActionCycleBuilder::object(ActionCycleDispatcher &dispatcher)
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        PushTag(MUIA_ActionDispatcher, (void *)&dispatcher);

        auto object = MUI::CycleBuilderTemplate<ActionCycleBuilder, ActionRoot<MUI::Cycle>>::object(sizeof(CustomObjectData),
                                                                                                    ENTRY(ActionCycleDispatcherFunc));

        // any cycle changed -> call dispatcher method
        MUI::Notifier::from(object).onActiveEveryTime().notifySelf().method(MUIM_ActionOnActive);

        return object;
    }
}
