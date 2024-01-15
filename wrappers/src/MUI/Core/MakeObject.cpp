//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include "MakeObject.hpp"

#include "AOS/TagBuilderRoot.hpp"
#include "Object.hpp"

#include <iostream>

namespace MUI
{
    Object *MakeObject::Checkmark()
    {
        return MUI_MakeObject(MUIO_Checkmark, 0);
    }

    Object *MakeObject::SimpleButton(const char *label)
    {
        return MUI_MakeObject(MUIO_Button, (unsigned long)label);
    }

    Object *MakeObject::SimpleButton(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Button, (unsigned long)label.c_str());
    }

    Object *MakeObject::PopButton(unsigned long img)
    {
        return MUI_MakeObject(MUIO_PopButton, img);
    }

    Object *MakeObject::Label(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, 0);
    }

    Object *MakeObject::Label(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), 0);
    }

    Object *MakeObject::Label1(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_SingleFrame);
    }

    Object *MakeObject::Label1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_SingleFrame);
    }

    Object *MakeObject::Label2(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::Label2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::LLabel(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_LeftAligned);
    }

    Object *MakeObject::LLabel(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_LeftAligned);
    }

    Object *MakeObject::LLabel1(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_LeftAligned | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::LLabel1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_LeftAligned | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::LLabel2(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_LeftAligned | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::LLabel2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_LeftAligned | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::CLabel(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_Centered);
    }

    Object *MakeObject::CLabel(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_Centered);
    }

    Object *MakeObject::CLabel1(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_Centered | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::CLabel1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_Centered | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::CLabel2(const char *label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label, MUIO_Label_Centered | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::CLabel2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_Centered | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::FreeLabel(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert);
    }

    Object *MakeObject::FreeLabel1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::FreeLabel2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::FreeLLabel(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_LeftAligned);
    }

    Object *MakeObject::FreeLLabel1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(),
                              MUIO_Label_FreeVert | MUIO_Label_LeftAligned | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::FreeLLabel2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(),
                              MUIO_Label_FreeVert | MUIO_Label_LeftAligned | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::FreeCLabel(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_Centered);
    }

    Object *MakeObject::FreeCLabel1(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_Centered | MUIO_Label_SingleFrame);
    }

    Object *MakeObject::FreeCLabel2(const std::string &label)
    {
        return MUI_MakeObject(MUIO_Label, (unsigned long)label.c_str(), MUIO_Label_FreeVert | MUIO_Label_Centered | MUIO_Label_DoubleFrame);
    }

    Object *MakeObject::HVSpace()
    {
        return MUI_NewObject(MUIC_Rectangle, TAG_DONE);
    }

    Object *MakeObject::HSpace(const unsigned long space)
    {
        return MUI_MakeObject(MUIO_HSpace, space);
    }

    Object *MakeObject::VSpace(const unsigned long space)
    {
        return MUI_MakeObject(MUIO_VSpace, space);
    }

    Object *MakeObject::HBar(const unsigned long space)
    {
        return MUI_MakeObject(MUIO_HBar, space);
    }

    Object *MakeObject::VBar(const unsigned long space)
    {
        return MUI_MakeObject(MUIO_VBar, space);
    }

    Object *MakeObject::HCenter(const Object *object)
    {
        AOS::TagBuilderRoot tagBuilder;

        tagBuilder.PushTag(MUIA_Group_Horiz, true);
        tagBuilder.PushTag(MUIA_Group_Spacing, 0L);
        tagBuilder.PushTag(MUIA_Group_Child, HSpace(0), false);
        tagBuilder.PushTag(MUIA_Group_Child, object, false);
        tagBuilder.PushTag(MUIA_Group_Child, HSpace(0), false);

        return muiObject(MUIC_Group, tagBuilder.getTags());
    }

    Object *MakeObject::VCenter(const Object *object)
    {
        AOS::TagBuilderRoot tagBuilder;

        tagBuilder.PushTag(MUIA_Group_Horiz, false);
        tagBuilder.PushTag(MUIA_Group_Spacing, 0L);
        tagBuilder.PushTag(MUIA_Group_Child, VSpace(0), false);
        tagBuilder.PushTag(MUIA_Group_Child, object, false);
        tagBuilder.PushTag(MUIA_Group_Child, VSpace(0), false);

        return muiObject(MUIC_Group, tagBuilder.getTags());
    }
}
