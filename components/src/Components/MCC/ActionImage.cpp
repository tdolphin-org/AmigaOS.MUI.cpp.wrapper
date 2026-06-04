//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2026 TDolphin
//

#include "ActionImage.hpp"

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "MUI/Notifier/Notifier.hpp"

#include "SDI/SDI_compiler.h"
#include "SDI/SDI_hook.h"

#ifdef TRACE_CUSTOM_COMPONENTS
#include "amiga_std_light/iostream.hpp"
#endif

DISPATCHER(ActionImageDispatcher)
{
    // Be careful with debug output here.
    // It causes that MUI interface hangs during "drag&drop"!
    // std::cerr << __PRETTY_FUNCTION__ << " MethodID: 0x" << msg->MethodID << "\n";

    auto dispatchMethodResult = Components::MCC::dispatchMethod(msg->MethodID, cl, obj, msg);
    if (dispatchMethodResult.dispatchResult)
        return dispatchMethodResult.methodResult;

    return DoSuperMethodA(cl, obj, msg);
}

namespace Components::MCC
{
    ActionImageBuilder::ActionImageBuilder()
      : MUI::ImageBuilderTemplate<ActionImageBuilder, ActionRoot<MUI::Image>>("ActionImage")
    {
    }

    ActionRoot<MUI::Image> ActionImageBuilder::object(OnClickDispatcher &dispatcher)
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cerr << __PRETTY_FUNCTION__ << "\n";
#endif
        PushTag(MUIA_ActionDispatcher, (void *)&dispatcher);

        auto object = MUI::ImageBuilderTemplate<ActionImageBuilder, ActionRoot<MUI::Image>>::object(sizeof(CustomObjectData),
                                                                                                    ENTRY(ActionImageDispatcher));

        // object (un)pressed -> call dispatcher method
        MUI::Notifier::from(object).onPressed(false).notifySelf().method(MUIM_ActionOnClick);

        return object;
    }
}
