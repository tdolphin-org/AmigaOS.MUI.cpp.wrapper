//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#include "Object.hpp"

#include "AOS/TagsScope.hpp"
#include "CustomClassManager.hpp"
#include "CustomClassScope.hpp"

#include <proto/intuition.h>
#include <proto/muimaster.h>

#ifdef TRACE_MUI
#include <cstdio>
#endif
#include <stdexcept>

namespace MUI
{
    Object *muiObject(const std::string &className, const std::vector<AOS::TagItemObject> &tags)
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
        std::fprintf(stderr, "%s:\n", className.c_str());
#endif
        AOS::TagsScope tagsScope(tags);
#ifdef TRACE_MUI
        const auto tagsString = tagsScope.toString();
        std::fprintf(stderr, "# tags [%zu]: %s\n", tags.size(), tagsString.c_str());
#endif
        auto *pObject = MUI_NewObjectA((char *)className.c_str(), tagsScope.tagItems());
#ifdef TRACE_MUI
        std::fprintf(stderr, "==> %p\n", (void *)pObject);
#endif
        if (pObject == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " MUI_NewObjectA(" + className + ") returned nullptr";
            throw std::invalid_argument(error);
        }

        return pObject;
    }

    Object *amccObject(const std::string &uniqueId, const std::string &className, const std::vector<AOS::TagItemObject> &tags,
                       const unsigned long dataSize, const void *dispatcher)
    {
#ifdef TRACE_MUI
        std::fprintf(stderr, "%s\n", __PRETTY_FUNCTION__);
        std::fprintf(stderr, "%s:\n", className.c_str());
#endif
        AOS::TagsScope tagsScope(tags);
        auto &mccScope = CustomClassManager::instance().get(uniqueId, className, dataSize, dispatcher);
#ifdef TRACE_MUI
        const auto tagsString = tagsScope.toString();
        std::fprintf(stderr, "# tags [%zu]: %s\n", tags.size(), tagsString.c_str());
#endif
        // TODO? for #?.mcc MUI_NewObject could be used (see muimaster doc)
        auto *pObject = (Object *)NewObjectA(mccScope.mcc()->mcc_Class, nullptr, tagsScope.tagItems());
#ifdef TRACE_MUI
        std::fprintf(stderr, "==> %p\n", (void *)pObject);
#endif
        if (pObject == nullptr)
        {
            auto error = std::string { __PRETTY_FUNCTION__ } + " NewObjectA(" + className + ") returned nullptr";
            throw std::invalid_argument(error);
        }

        return pObject;
    }
}
