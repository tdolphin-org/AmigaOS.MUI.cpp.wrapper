//
//  AmigaOS MUI C++ wrapper
//
//  Components
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#include <intuition/classusr.h>
#include <libraries/mui.h>
#include <proto/alib.h>
#include <proto/utility.h>

// methods and attributes are "private" for Custom Class

#define TagBaseActionRoot (TAG_USER | (1 << 16))

// common private Methods

#define MUIM_ActionOnTimer (TagBaseActionRoot | 0x0001)
#define MUIM_ActionOnClick (TagBaseActionRoot | 0x0002)
#define MUIM_ActionOnActive (TagBaseActionRoot | 0x0003)
#define MUIM_ActionOnActiveEntry (TagBaseActionRoot | 0x0004)
#define MUIM_ActionOnDoubleClickEntry (TagBaseActionRoot | 0x0005)
#define MUIM_ActionOnChange (TagBaseActionRoot | 0x0006)

// common Attributes

#define MUIA_ActionDispatcher (TagBaseActionRoot + 0x0100) // [i..] void*
#define MUIA_ActionTimer (TagBaseActionRoot + 0x0101) // [i..] ULONG

namespace Components::MCC
{
    struct DispatchMethodResult
    {
        unsigned long methodResult;
        bool dispatchResult;

        DispatchMethodResult()
          : methodResult(FALSE)
          , dispatchResult(false)
        {
        }

        DispatchMethodResult(unsigned long methodResult, bool dispatchResult)
          : methodResult(methodResult)
          , dispatchResult(dispatchResult)
        {
        }
    };

    template <typename T> class ActionRoot : public T
    {
      public:
        ActionRoot(Object *pMuiObject)
          : T(pMuiObject)
        {
        }
    };

    class ActionDispatcherRoot
    {
      public:
        ActionDispatcherRoot() { }

        virtual unsigned long OnClick()
        {
            return 0;
        };

        virtual unsigned long OnActiveEntry()
        {
            return 0;
        };

        virtual unsigned long OnTimer()
        {
            return 0;
        }

        virtual unsigned long OnDoubleClickEntry()
        {
            return 0;
        }
    };

    struct CustomObjectData
    {
        ActionDispatcherRoot *pDispatcher;
        struct MUI_InputHandlerNode inputHandlerNode;
    };

    DispatchMethodResult dispatchMethod(unsigned long method, struct IClass *cl, Object *obj, void *msg);

    /// @brief OM_NEW
    unsigned long methodNew(struct IClass *cl, Object *obj, void *msg, const unsigned long tagDispatcher = MUIA_ActionDispatcher);
    /// @brief OM_DISPOSE
    unsigned long methodDispose(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_Setup
    unsigned long methodSetup(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_Cleanup
    unsigned long methodCleanup(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_ActionOnClick
    unsigned long methodOnClick(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_ActionOnActiveEntry
    unsigned long methodOnActiveEntry(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_ActionOnTimer
    unsigned long methodOnTimer(struct IClass *cl, Object *obj, void *msg);
    /// @brief MUIM_ActionOnDoubleClickEntry
    unsigned long methodOnDoubleClickEntry(struct IClass *cl, Object *obj, void *msg);
}
