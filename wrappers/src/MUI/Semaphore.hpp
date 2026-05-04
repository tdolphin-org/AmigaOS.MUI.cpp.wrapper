//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Core/BuilderRoot.hpp"
#include "Core/Root.hpp"

#include <libraries/mui.h>

namespace MUI
{
    /// @brief Semaphore class wrapper. Provides semaphore-equipped MUI objects for thread-safe access.
    /// The Semaphore class helps to access dataspace objects from different tasks. Its methods are
    /// identical to the exec.library semaphore functions and work on the semaphore contained in
    /// the class instance data.
    class Semaphore : public Root
    {
      public:
        explicit Semaphore(Object *pMuiObject)
          : Root(pMuiObject)
        {
        }

        Semaphore(const Root &root)
          : Root(root.muiObject())
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

        /// @brief [ @b MUIM_Semaphore_Attempt ]
        /// Emulates exec.library/AttemptSemaphore. Tries to obtain the semaphore without blocking.
        /// @return true if the semaphore was obtained, false if it was already locked.
        bool Attempt();

        /// @brief [ @b MUIM_Semaphore_AttemptShared ]
        /// Emulates exec.library/AttemptSemaphoreShared. Tries to obtain the semaphore in shared
        /// mode without blocking. The pre-V39 autodocs fixes are already implemented.
        /// @return true if the shared semaphore was obtained, false if it was already exclusively locked.
        bool AttemptShared();

        /// @brief [ @b MUIM_Semaphore_Obtain ]
        /// Emulates exec.library/ObtainSemaphore. Blocks until the semaphore can be obtained exclusively.
        Semaphore &Obtain();

        /// @brief [ @b MUIM_Semaphore_ObtainShared ]
        /// Emulates exec.library/ObtainSemaphoreShared. Blocks until the semaphore can be obtained
        /// in shared mode. The pre-V39 autodocs fixes are already implemented.
        Semaphore &ObtainShared();

        /// @brief [ @b MUIM_Semaphore_Release ]
        /// Emulates exec.library/ReleaseSemaphore. Releases a previously obtained semaphore.
        Semaphore &Release();
    };

    template <typename T, typename U> class SemaphoreBuilderTemplate : public BuilderRoot<U>
    {
      public:
        SemaphoreBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Semaphore)
          : BuilderRoot<U>(uniqueId, muiClassName)
        {
        }
    };

    class SemaphoreBuilder : public SemaphoreBuilderTemplate<SemaphoreBuilder, Semaphore>
    {
      public:
        SemaphoreBuilder();
    };
}
