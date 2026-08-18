//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#pragma once

#ifdef __MORPHOS__

#define REG(x)

#ifndef DISPATCHER
#define DISPATCHER(Name) \
static ULONG Name##_Dispatcher(void); \
struct EmulLibEntry GATE ##Name##_Dispatcher = { TRAP_LIB, 0, (void (*)(void)) Name##_Dispatcher }; \
static ULONG Name##_Dispatcher(void) { struct IClass *cl=(struct IClass*)REG_A0; Msg msg=(Msg)REG_A1; Object *obj=(Object*)REG_A2;
#define DISPATCHER_REF(Name) &GATE##Name##_Dispatcher
#define DISPATCHER_END }
#endif

#elif defined(__AROS__)
// AROS: dispatcher for custom classes uses the AROS-specific machinery
// (handles the x86_64 ABI). SDI_hook.h provides DISPATCHER and ENTRY().

#include "SDI_hook.h"

#define REG(x)

#define DISPATCHER_REF(Name) ENTRY(Name)
#define DISPATCHER_END

#else
#define REG(x)

#define DISPATCHER(Name) ULONG ASM SAVEDS Name##Dispatcher(struct IClass *cl, Msg msg, Object *obj)
#define DISPATCHER_REF(Name) ((const void*)Name##Dispatcher)
#define DISPATCHER_END

#endif

#if defined __MAXON__ || defined __GNUC__
	#define ASM
	#define SAVEDS
	#else
	#define ASM    __asm
	#define SAVEDS __saveds
#endif
