//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2023 TDolphin
//

#pragma once

#include "Core/ObjectScope.hpp"
#include "Notify.hpp"

namespace MUI
{
    class Window;
    class Menustrip;

    class Application : public Notify
    {
      public:
        Application(const Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Application(const APTR pMuiObject)
          : Notify(pMuiObject)
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Application_Menustrip ]
        Object *getMenustripObject() const;
        /// @brief [ @b MUIA_Application_Menustrip ]
        Menustrip getMenustrip() const;

        /// @brief [ @b MUIA_Application_WindowList ]
        std::vector<Window> getWindowList();

        // methods, some can return object reference

        /// @brief [ @b MUIM_Application_Load, @b MUIV_Application_Load_ENVARC ]
        Application &LoadEnvArc();
        /// @brief [ @b MUIM_Application_Save, @b MUIV_Application_Save_ENVARC ]
        Application &SaveEnvArc();
        /// @brief [ @b MUIA_Application_Sleep, @b TRUE ]
        Application &Sleep();
        /// @brief [ @b MUIA_Application_Sleep, @b FALSE ]
        Application &WakeUp();
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
        /// @brief [ @b MUIA_Application_Menustrip ]
        ApplicationBuilder &tagMenustrip(const Menustrip &menustrip);
        /// @brief [ @b MUIA_Application_SingleTask ]
        ApplicationBuilder &tagSingleTask(const bool singleTask);
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
        /// @brief [ @b MUIA_Application_Window ]
        ApplicationBuilder &tagWindows(const std::vector<Window> &windows);
    };

    class ApplicationScope : ObjectScope
    {
      public:
        ApplicationScope(const Application &application);
        ~ApplicationScope();
    };

    class ApplicationSleepScope
    {
      public:
        ApplicationSleepScope();
        ~ApplicationSleepScope();
    };
}
