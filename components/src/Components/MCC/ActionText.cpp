//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2026 TDolphin
//

#include "ActionText.hpp"

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "MUI/Notifier/Notifier.hpp"

#include "SDI/SDI_compiler.h"
#include "SDI/SDI_hook.h"

#ifdef TRACE_CUSTOM_COMPONENTS
#include <cstdio>
#endif

DISPATCHER(ActionTextDispatcherFunc)
{
    // Be careful with debug output here.
    // It causes that MUI interface hangs during "drag&drop"!
    // std::fprintf(stderr, "%s MethodID: 0x%lx\n", __PRETTY_FUNCTION__, msg->MethodID);

    auto dispatchMethodResult = Components::MCC::dispatchMethod(msg->MethodID, cl, obj, msg);
    if (dispatchMethodResult.dispatchResult)
        return dispatchMethodResult.methodResult;

    return DoSuperMethodA(cl, obj, msg);
}

namespace Components::MCC
{
    ActionTextBuilder::ActionTextBuilder()
      : MUI::TextBuilderTemplate<ActionTextBuilder, ActionRoot<MUI::Text>>("ActionText")
    {
    }

    ActionRoot<MUI::Text> ActionTextBuilder::object(OnClickDispatcher &dispatcher)
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
#endif
        PushTag(MUIA_ActionDispatcher, (void *)&dispatcher);

        auto object = MUI::TextBuilderTemplate<ActionTextBuilder, ActionRoot<MUI::Text>>::object(sizeof(CustomObjectData),
                                                                                                 ENTRY(ActionTextDispatcherFunc));

        // object (un)pressed -> call dispatcher method
        MUI::Notifier::from(object).onPressed(false).notifySelf().method(MUIM_ActionOnClick);

        return object;
    }
}
