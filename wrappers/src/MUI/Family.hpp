//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2026 TDolphin
//

#pragma once

#include "Notify.hpp"

#include <initializer_list>
#include <vector>

#undef Insert
#undef Remove

namespace MUI
{
    class Family : public Notify
    {
      public:
        explicit Family(Object *pMuiObject)
          : Notify(pMuiObject)
        {
        }

        Family(const Root &root)
          : Notify(root.muiObject())
        {
        }

        // instanceOf

        const static std::string className;

        static inline bool instanceOf(Object *pMuiObject)
        {
            return MUI::instanceOf(pMuiObject, className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

        /// @brief [ @b MUIA_Family_ChildCount ]
        /// Returns the number of family members of a family object.
        /// @return number of child objects.
        long getChildCount() const;
        /// @brief [ @b MUIA_Family_List ]
        /// Returns a pointer to a struct MinList which contains the children of a family object. You must parse this list with
        /// intuition.library/NextObject().
        /// @return list of child objects.
        struct MinList *getChildList() const;

        // methods, some returns object reference

        /// @brief [ @b MUIM_Family_AddHead ]
        /// Add an object as first object to the family.
        Family &AddHead(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_AddHead ]
        /// Add an object as first object to the family.
        Family &AddHead(const Root &child);
        /// @brief [ @b MUIM_Family_AddTail ]
        /// Add an object as last object to the family.
        Family &AddTail(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_AddTail ]
        /// Add an object as last object to the family.
        Family &AddTail(const Root &child);
        /// @brief [ @b MUIM_Family_DoChildMethods ]
        /// Invoke a method on all children of a family.
        template <typename... Args> Family &DoChildMethods(Args... args)
        {
            DoMethod(muiObject(), MUIM_Family_DoChildMethods, args...);
            return *this;
        }

        /// @brief [ @b MUIM_Family_GetChild ]
        /// Obtain a child of a family.
        Object *GetChild(const long nr, const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild ]
        /// Obtain a child of a family.
        Object *GetChild(const long nr, const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_First ]
        /// Return the first child of the family.
        Object *GetChildFirst() const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Last ]
        /// Return the last child of the family.
        Object *GetChildLast() const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Next ]
        /// Return the next child of the family for the given reference child.
        Object *GetChildNext(const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Next ]
        /// Return the next child of the family for the given reference child.
        Object *GetChildNext(const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Previous ]
        /// Return the previous child of the family for the given reference child.
        Object *GetChildPrevious(const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Previous ]
        /// Return the previous child of the family for the given reference child.
        Object *GetChildPrevious(const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Iterate ]
        /// Iterate over all children of the family using an iterator reference array.
        Object *GetChildIterate(void *iteratorRef) const;

        /// @brief [ @b MUIM_Family_Insert ]
        /// Add an object after another object to the family.
        Family &Insert(const Object *pChildObject, const Object *pPredecessorObject);
        /// @brief [ @b MUIM_Family_Insert ]
        /// Add an object after another object to the family.
        Family &Insert(const MUI::Root &obj, const MUI::Root &pred);
        /// @brief [ @b MUIM_Family_Remove ]
        /// Remove an object from a family.
        Family &Remove(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_Remove ]
        /// Remove an object from a family.
        Family &Remove(const MUI::Root &obj);

        /// @brief [ @b MUIM_Family_Reorder ]
        /// Reorder the children of a family.
        /// Object *after the object to reorder the children after. Special values are
        /// 0: reorder the objects at the front of the Family object's child list;
        /// -1: reorder the objects at the end of the Family object's child list;
        /// @note rather use @b ReorderFront or @b ReorderBack for these special cases
        Family &Reorder(const Object *after, const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder ]
        /// Reorder the children of a family.
        /// Object *after the object to reorder the children after. Special values are
        /// 0: reorder the objects at the front of the Family object's child list;
        /// -1: reorder the objects at the end of the Family object's child list;
        /// @note rather use @b ReorderFront or @b ReorderBack for these special cases
        Family &Reorder(const Object *after, const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = 0 ]
        /// Reorder the given children to the front of the family child list.
        Family &ReorderFront(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = 0 ]
        /// Reorder the given children to the front of the family child list.
        Family &ReorderFront(const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = -1 ]
        /// Reorder the given children to the end of the family child list.
        Family &ReorderBack(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = -1 ]
        /// Reorder the given children to the end of the family child list.
        Family &ReorderBack(const std::initializer_list<const Object *> &objects);

        /// @brief [ @b MUIM_Family_Sort ]
        /// Sort the children of a family.
        Family &Sort(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Sort ]
        /// Sort the children of a family.
        Family &Sort(const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Transfer ]
        /// Remove all children from this family and add them to another family in the same order.
        Family &Transfer(const Object *pDestinationFamilyObject);
        /// @brief [ @b MUIM_Family_Transfer ]
        /// Remove all children from this family and add them to another family in the same order.
        Family &Transfer(const Family &destinationFamily);
    };

    template <typename T, typename U> class FamilyBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        FamilyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Family)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Family_Child ]
        /// @param child Root wrapper of child object, if null object, object is not added
        /// @param condition if false, tag is not added
        T &tagChild(const MUI::Root &child, bool condition = true);
        /// @brief [ @b MUIA_Family_Child ]
        /// @param pChildObject pointer to child object, if nullptr, object is not added
        /// @param condition if false, tag is not added
        T &tagChild(const Object *pChildObject, bool condition = true);
    };

    class FamilyBuilder : public FamilyBuilderTemplate<FamilyBuilder, Family>
    {
      public:
        FamilyBuilder();
    };
}

#define MUI_FAMILY_TPP_INCLUDE
#include "Family.tpp"
#undef MUI_FAMILY_TPP_INCLUDE
