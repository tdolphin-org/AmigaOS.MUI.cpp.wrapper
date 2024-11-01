//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#include "ActionRoot.hpp"

#include "Dispatcher/OnActiveEntryDispatcher.hpp"
#include "Dispatcher/OnClickDispatcher.hpp"
#include "Dispatcher/OnDoubleClickEntryDispatcher.hpp"
#include "Dispatcher/OnTimerDispatcher.hpp"

namespace Components::MCC
{
    DispatchMethodResult dispatchMethod(unsigned long method, IClass *cl, Object *obj, void *msg)
    {
        DispatchMethodResult result;
        result.dispatchResult = true;

        switch (method)
        {
            case OM_NEW:
                result.methodResult = methodNew(cl, obj, msg);
                break;
            case OM_DISPOSE:
                result.methodResult = methodDispose(cl, obj, msg);
                break;
            case MUIM_Setup:
                result.methodResult = methodSetup(cl, obj, msg);
                break;
            case MUIM_Cleanup:
                result.methodResult = methodCleanup(cl, obj, msg);
                break;
            case MUIM_ActionOnClick:
                result.methodResult = methodOnClick(cl, obj, msg);
                break;
            case MUIM_ActionOnTimer:
                result.methodResult = methodOnTimer(cl, obj, msg);
                break;
            case MUIM_ActionOnActiveEntry:
                result.methodResult = methodOnActiveEntry(cl, obj, msg);
                break;
            case MUIM_ActionOnDoubleClickEntry:
                result.methodResult = methodOnDoubleClickEntry(cl, obj, msg);
                break;
            default:
                result.dispatchResult = false;
        }

        return result;
    }

    unsigned long methodNew(IClass *cl, Object *obj, void *msg, const unsigned long tagDispatcher /*= MUIA_ActionDispatcher*/)
    {
        if (!(obj = (Object *)DoSuperMethodA(cl, obj, (Msg)msg)))
            return FALSE;

        CustomObjectData *pData = reinterpret_cast<CustomObjectData *> INST_DATA(cl, obj);
        pData->pDispatcher = nullptr;
        pData->inputHandlerNode.ihn_Object = nullptr;

        struct TagItem *tag;
        for (auto tags = ((struct opSet *)msg)->ops_AttrList; (tag = NextTagItem(&tags));)
        {
            if (tag->ti_Tag == tagDispatcher)
            {
                if (tag->ti_Data)
                    pData->pDispatcher = reinterpret_cast<ActionDispatcherRoot *>(tag->ti_Data);
            }
            else if (tag->ti_Tag == MUIA_ActionTimer)
            {
                // prepare data
                pData->inputHandlerNode.ihn_Flags = MUIIHNF_TIMER;
                pData->inputHandlerNode.ihn_Millis = tag->ti_Data;
                pData->inputHandlerNode.ihn_Object = obj;
                pData->inputHandlerNode.ihn_Method = MUIM_ActionOnTimer;
            }
        }

        return (unsigned long)obj;
    }

    // OM_NEW didn't allocates anything, do nothing here...
    unsigned long methodDispose(IClass *cl, Object *obj, void *msg)
    {
        return DoSuperMethodA(cl, obj, (Msg)msg);
    }

    unsigned long methodSetup(IClass *cl, Object *obj, void *msg)
    {
        if (!DoSuperMethodA(cl, obj, (Msg)msg))
            return FALSE;

        CustomObjectData *pData = reinterpret_cast<CustomObjectData *> INST_DATA(cl, obj);
        if (pData->inputHandlerNode.ihn_Object)
            DoMethod(_app(obj), MUIM_Application_AddInputHandler, &pData->inputHandlerNode);

        return TRUE;
    }

    unsigned long methodCleanup(IClass *cl, Object *obj, void *msg)
    {
        if (!DoSuperMethodA(cl, obj, (Msg)msg))
            return FALSE;

        CustomObjectData *pData = reinterpret_cast<CustomObjectData *> INST_DATA(cl, obj);
        if (pData->inputHandlerNode.ihn_Object)
            DoMethod(_app(obj), MUIM_Application_RemInputHandler, &pData->inputHandlerNode);

        return TRUE;
    }

    unsigned long methodOnClick(struct IClass *cl, Object *obj, void *msg)
    {
        Components::MCC::CustomObjectData *pData = reinterpret_cast<Components::MCC::CustomObjectData *> INST_DATA(cl, obj);
        if (pData->pDispatcher)
            return reinterpret_cast<Components::MCC::OnClickDispatcher *>(pData->pDispatcher)->OnClick();

        return FALSE;
    }

    unsigned long methodOnActiveEntry(IClass *cl, Object *obj, void *msg)
    {
        Components::MCC::CustomObjectData *pData = reinterpret_cast<Components::MCC::CustomObjectData *> INST_DATA(cl, obj);
        if (pData->pDispatcher)
            return reinterpret_cast<Components::MCC::OnActiveEntryDispatcher *>(pData->pDispatcher)->OnActiveEntry();

        return FALSE;
    }

    unsigned long methodOnTimer(IClass *cl, Object *obj, void *msg)
    {
        Components::MCC::CustomObjectData *pData = reinterpret_cast<Components::MCC::CustomObjectData *> INST_DATA(cl, obj);
        if (pData->pDispatcher)
            return reinterpret_cast<Components::MCC::OnTimerDispatcher *>(pData->pDispatcher)->OnTimer();

        return FALSE;
    }

    unsigned long methodOnDoubleClickEntry(struct IClass *cl, Object *obj, void *msg)
    {
        Components::MCC::CustomObjectData *pData = reinterpret_cast<Components::MCC::CustomObjectData *> INST_DATA(cl, obj);
        if (pData->pDispatcher != nullptr)
            reinterpret_cast<Components::MCC::OnDoubleClickEntryDispatcher *>(pData->pDispatcher)->OnDoubleClickEntry();

        return FALSE;
    }
}
