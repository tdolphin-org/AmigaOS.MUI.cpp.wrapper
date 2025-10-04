//
//  AmigaOS MUI C++ wrapper
//
//  Advanced Example
//
//  (c) 2022-2025 TDolphin
//

#include "BoardsList.hpp"

#include "Components/DataTypes/BoardRef.hpp"
#include "MUI/Notifier/Notifier.hpp"

#ifdef TRACE_CUSTOM_COMPONENTS
#include <iostream>
#endif

#include <proto/alib.h>
#include <proto/exec.h>
#include <proto/utility.h>

#include "SDI/platform_macros.hpp"

static size_t ConstructEntry(struct IClass *, Boopsiobject *, struct MUIP_List_Construct *msg)
{
    BoardRef *copy = (BoardRef *)AllocPooled(msg->pool, sizeof(BoardRef));
    if (copy != nullptr)
        *copy = *(BoardRef *)msg->entry;

    return (unsigned long)copy;
}

static size_t DestructEntry(struct IClass *, Boopsiobject *, struct MUIP_List_Destruct *msg)
{
    if (msg->entry)
        FreePooled(msg->pool, (APTR)msg->entry, sizeof(BoardRef));

    return 0;
}

static size_t DisplayEntry(struct IClass *, Boopsiobject *, struct MUIP_List_Display *msg)
{
    // have to be static because msg->array is used after this method returns
    static BoardRef displayBoardRef;
    auto array = msg->array;
    if (msg->entry)
    {
        displayBoardRef = *(BoardRef *)msg->entry;
        *array++ = displayBoardRef.vendor;
        *array = displayBoardRef.device;
    }
    else
    {
        *array++ = MUIX_C "[ID] Vendor";
        *array = MUIX_C "[ID] Device";
    }

    return 0;
}

DISPATCHER(BoardsList)
{
    switch (msg->MethodID)
    {
        case MUIM_List_Construct:
            return ConstructEntry(cl, obj, (struct MUIP_List_Construct *)msg);
        case MUIM_List_Destruct:
            return DestructEntry(cl, obj, (struct MUIP_List_Destruct *)msg);
        case MUIM_List_Display:
            return DisplayEntry(cl, obj, (struct MUIP_List_Display *)msg);
        default:
            return DoSuperMethodA(cl, obj, msg);
    }
}
DISPATCHER_END

namespace Components::MCC
{
    BoardsListBuilder::BoardsListBuilder()
      : MUI::ListBuilderTemplate<BoardsListBuilder, ActionRoot<MUI::List>>("BoardsList")
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        tagMaxColumns(2);
    }

    ActionRoot<MUI::List> BoardsListBuilder::object()
    {
#ifdef TRACE_CUSTOM_COMPONENTS
        std::cout << __PRETTY_FUNCTION__ << std::endl;
#endif
        auto list = MUI::ListBuilderTemplate<BoardsListBuilder, ActionRoot<MUI::List>>::object(sizeof(CustomObjectData),
                                                                                               DISPATCHER_REF(BoardsList));
        return list;
    }
}
