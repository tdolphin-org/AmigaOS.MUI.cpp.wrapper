//
//  AmigaOS MUI C++ wrapper
//
//  (c) TDolphin 2022-2023
//

#pragma once

#include "Core/ObjectScope.hpp"
#include "Notify.hpp"

namespace MUI
{
    class Window;
    class Application : public Notify
    {
      public:
        Application(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // get/set (attributes), all setters return object reference
        // methods, some can return object reference
    };

    class ApplicationBuilder : public NotifyBuilderTemplate<ApplicationBuilder, Application>
    {
      public:
        ApplicationBuilder();

        /// @brief [ @b MUIA_Application_Author ]
        ApplicationBuilder &tagAuthor(const char *author);
        /// @brief [ @b MUIA_Application_Author ]
        ApplicationBuilder &tagAuthor(const std::string &author);
        /// @brief [ @b MUIA_Application_Base ]
        ApplicationBuilder &tagBase(const char *base);
        /// @brief [ @b MUIA_Application_Base ]
        ApplicationBuilder &tagBase(const std::string &base);
        /// @brief [ @b MUIA_Application_Copyright ]
        ApplicationBuilder &tagCopyright(const char *copyright);
        /// @brief [ @b MUIA_Application_Copyright ]
        ApplicationBuilder &tagCopyright(const std::string &copyright);
        /// @brief [ @b MUIA_Application_Description ]
        ApplicationBuilder &tagDescription(const char *description);
        /// @brief [ @b MUIA_Application_Description ]
        ApplicationBuilder &tagDescription(const std::string &description);
        /// @brief [ @b MUIA_Application_Title ]
        ApplicationBuilder &tagTitle(const char *title);
        /// @brief [ @b MUIA_Application_Title ]
        ApplicationBuilder &tagTitle(const std::string &title);
        /// @brief [ @b MUIA_Application_UsedClasses ]
        ApplicationBuilder &tagUsedClasses(char *usedClasses[]);
        /// @brief [ @b MUIA_Application_Version ]
        /// @param version version text with $VER !!!!
        ApplicationBuilder &tagVersion(const char *version);
        /// @brief [ @b MUIA_Application_Version ]
        /// @param version version text with $VER !!!!
        ApplicationBuilder &tagVersion(const std::string &version);
        /// @brief [ @b MUIA_Application_Window ]
        ApplicationBuilder &tagWindow(const Window &window);
    };

    class ApplicationScope : ObjectScope
    {
      public:
        ApplicationScope(const Application &application)
          : ObjectScope(application.muiObject())
        {
        }
    };
}