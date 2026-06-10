//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2026 TDolphin
//

#include "ActionList.hpp"

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "MUI/Notifier/Notifier.hpp"

#include "SDI/SDI_compiler.h"
#include "SDI/SDI_hook.h"

#ifdef TRACE_CUSTOM_COMPONENTS
#include "amiga_std_light/iostream.hpp"
#endif

DISPATCHER(ActionListDispatcherFunc)
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
    ActionListBuilder::ActionListBuilder()
      : MUI::ListBuilderTemplate<ActionListBuilder, ActionRoot<MUI::List>>("ActionList")
    {
    }

    ActionRoot<MUI::List> ActionListBuilder::object(ActionListDispatcher &dispatcher)
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << "\n";
#endif
        PushTag(MUIA_ActionDispatcher, (void *)&dispatcher);

        auto object = MUI::ListBuilderTemplate<ActionListBuilder, ActionRoot<MUI::List>>::object(sizeof(CustomObjectData),
                                                                                                 ENTRY(ActionListDispatcherFunc));

        // any list item selected -> call dispatcher method
        MUI::Notifier::from(object).onActiveEveryTime().notifySelf().method(MUIM_ActionOnActiveEntry);

#ifdef MUIA_List_DoubleClick        
        // double click -> call dispatcher method
        MUI::Notifier::from(object).onDoubleClick(true).notifySelf().method(MUIM_ActionOnDoubleClickEntry);
#endif

        return object;
    }
}
