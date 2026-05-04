//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Process.hpp"

#ifdef MUIC_Slave

namespace MUI
{
    /// @brief Slave class wrapper. Provides safe asynchronous method dispatching between threads.
    /// The Slave class provides a convenient way of safely dispatching methods that are to be run
    /// asynchronously on a thread as well as a safe way to call a method from a thread on the main
    /// thread. A Slave object is always bound to a single object it will invoke methods on.
    class Slave : public Process
    {
      public:
        explicit Slave(Object *pMuiObject)
          : Process(pMuiObject)
        {
        }

        Slave(const Root &root)
          : Process(root.muiObject())
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

        // methods, some returns object reference

        /// @brief [ @b MUIM_Slave_Cleanup ]
        /// This method should be implemented if your slave needs some special cleanup procedure
        /// before the slave thread eventually ceases to exist. Keep in mind that this method might
        /// be called during the parent object's OM_DISPOSE method.
        Slave &Cleanup();

        /// @brief [ @b MUIM_Slave_Dispatch ]
        /// Dispatch a method on the slave's thread. If called from the thread the method will be
        /// dispatched on the main thread instead. Execution of all methods is asynchronous and will
        /// happen in parallel. Do not pass volatile or temporary data as parameters.
        /// Use MUIF_Slave_Delegate_ForceSlave as @a flags to always dispatch on the slave's thread.
        /// @param flags Set to MUIF_Slave_Delegate_ForceSlave to force dispatch on slave thread; 0 otherwise.
        /// @param args The dispatched method ID followed by all method parameters. Count is computed automatically.
        /// @return Non-zero if setting up the dispatch message succeeded; zero on failure (caller must free dynamically allocated params).
        template <typename... Args> unsigned long Dispatch(const unsigned long flags, Args... args)
        {
            return DoMethod(muiObject(), MUIM_Slave_Dispatch, flags, (LONG)sizeof...(Args), args...);
        }

        /// @brief [ @b MUIM_Slave_Error ]
        /// This method will be called on the slave's main object to dispose dynamically allocated
        /// parameters of a dispatched method that could not be executed, e.g. when the application
        /// is disposed before all queued methods were executed.
        /// @param failedDispatch A full Msg containing the failed MethodID and all parameters.
        Slave &Error(Msg failedDispatch);

        /// @brief [ @b MUIM_Slave_Setup ]
        /// This method should be implemented if your slave needs some special setup procedure
        /// before the first method is dispatched in the slave thread. Useful for initialising
        /// network connections or similar resources.
        /// @return Signal mask containing the signals for which MUIM_Slave_SignalsReceived will be triggered; 0 if not needed.
        unsigned long Setup();

        /// @brief [ @b MUIM_Slave_SignalsReceived ]
        /// This method is invoked on the slave process whenever the slave process receives a signal
        /// matching those returned by MUIM_Slave_Setup.
        /// @param sigmask Received signal mask.
        Slave &SignalsReceived(const unsigned long sigmask);
    };

    template <typename T, typename U> class SlaveBuilderTemplate : public ProcessBuilderTemplate<T, U>
    {
      public:
        SlaveBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Slave)
          : ProcessBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Slave_Application ]
        /// Explicitly set the application object. Required when the main object is not subclassed
        /// from Area or has not received MUIM_Setup yet. By default Slave class tries to obtain
        /// the application object automatically on first method dispatch.
        T &tagApplication(Object *application);

        /// @brief [ @b MUIA_Slave_Class ]
        /// If set to a valid class pointer, all methods will be dispatched using CoerceMethod()
        /// rather than DoMethod().
        T &tagClass(Object *muiClass);

        /// @brief [ @b MUIA_Slave_Object ]
        /// Mandatory destination object to dispatch methods on. MUST be set during OM_NEW.
        T &tagObject(Object *object);
    };

    class SlaveBuilder : public SlaveBuilderTemplate<SlaveBuilder, Slave>
    {
      public:
        SlaveBuilder();
    };
}

#define MUI_SLAVE_TPP_INCLUDE
#include "Slave.tpp"
#undef MUI_SLAVE_TPP_INCLUDE

#endif
