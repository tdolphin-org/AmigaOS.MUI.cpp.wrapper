//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Semaphore.hpp"

#ifdef MUIC_Process

namespace MUI
{
    /// @brief Process class wrapper. Simplifies creation of subtasks to execute in parallel with the application.
    /// Typically a Process object is embedded into a custom class rather than being subclassed.
    /// A subprocess must NOT invoke any method of any of the application's objects directly — all
    /// methods must be pushed via MUIM_Application_PushMethod.
    class Process : public Semaphore
    {
      public:
        explicit Process(Object *pMuiObject)
          : Semaphore(pMuiObject)
        {
        }

        Process(const Root &root)
          : Semaphore(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Process_Task ]
        /// Returns a pointer to the created process task.
        struct Task *getTask() const;

        // methods, some returns object reference

        /// @brief [ @b MUIM_Process_Kill ]
        /// Stops the process loop (MUIM_Process_Process). Does nothing if the loop is not running.
        /// @param maxdelay Maximum time in seconds to wait until the child task eventually terminates.
        /// @return true if killing the child task was successful, false otherwise.
        bool Kill(const long maxdelay);

        /// @brief [ @b MUIM_Process_Launch ]
        /// Starts the process loop (MUIM_Process_Process). Does nothing if the loop is already running.
        Process &Launch();

        /// @brief [ @b MUIM_Process_Process ]
        /// Main process method. The termination condition is passed via @a kill pointer.
        /// A proper implementation should wait for a signal to avoid using 100% CPU.
        /// @param kill Stay in the main loop as long as this variable is zero.
        /// @param proc Pointer to this Process object itself.
#ifdef __MORPHOS__
        Process &Process_(ULONG *kill, Boopsiobject *proc);
#else
        Process &Process_(ULONG *kill, Object *proc);
#endif

        /// @brief [ @b MUIM_Process_Signal ]
        /// Sends a signal mask to the created child process.
        /// @param sigs Signal mask to send to the Process' child task.
        Process &Signal(const unsigned long sigs);
    };

    template <typename T, typename U> class ProcessBuilderTemplate : public SemaphoreBuilderTemplate<T, U>
    {
      public:
        ProcessBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Process)
          : SemaphoreBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Process_AutoLaunch ]
        /// If set to true the process loop is started right after the object instance is created.
        /// Defaults to true.
        T &tagAutoLaunch(const bool autoLaunch);

        /// @brief [ @b MUIA_Process_Name ]
        /// Specifies a name for the process. The name will be copied internally. If not specified,
        /// a suitable name is generated automatically.
        T &tagName(const unsigned long name);

        /// @brief [ @b MUIA_Process_Priority ]
        /// Specifies a priority for the process. Defaults to the same priority as the calling process.
        T &tagPriority(const unsigned long priority);

        /// @brief [ @b MUIA_Process_SourceClass ]
        /// Points to the container class for embedding Process into a custom class. MUIM_Process_Process
        /// will be called using the class given here and the object given with MUIA_Process_SourceObject.
        T &tagSourceClass(const unsigned long sourceClass);

        /// @brief [ @b MUIA_Process_SourceObject ]
        /// Points to the container object for embedding Process into a custom class. MUIM_Process_Process
        /// will be called using the class given with MUIA_Process_SourceClass and this object.
        T &tagSourceObject(const unsigned long sourceObject);

        /// @brief [ @b MUIA_Process_StackSize ]
        /// Specifies a stack size for the new process. Defaults to 32K.
        T &tagStackSize(const unsigned long stackSize);
    };

    class ProcessBuilder : public ProcessBuilderTemplate<ProcessBuilder, Process>
    {
      public:
        ProcessBuilder();
    };
}

#define MUI_PROCESS_TPP_INCLUDE
#include "Process.tpp"
#undef MUI_PROCESS_TPP_INCLUDE

#endif
