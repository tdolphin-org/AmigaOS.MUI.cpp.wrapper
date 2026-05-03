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
#undef AddHead
#undef AddTail

namespace MUI
{
    /// @brief MUI Family class wrapper.
    /// Base class for MUI objects that manage an ordered list of child objects, such as menustrips, menus and menuitems.
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

        static inline bool instanceOf(const Root &object)
        {
            return MUI::instanceOf(object.muiObject(), className.c_str());
        }

        // is/get/set (attributes), all setters return object reference

#ifdef MUIA_Family_ChildCount
        /// @brief [ @b MUIA_Family_ChildCount ] Returns the current number of child objects in the family.
        /// @return Number of child objects.
        long getChildCount() const;
#endif

        /// @brief [ @b MUIA_Family_List ] Returns the internal child list of the family.
        /// You must traverse the returned list with intuition.library/NextObject().
        /// @return Pointer to the list of child objects.
        const struct MinList *getChildList() const;

        // methods, some returns object reference

        /// @brief [ @b MUIM_Family_AddHead ] Adds an object as the first child of the family.
        /// @param pChildObject Child object to add.
        Family &AddHead(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_AddHead ] Adds an object as the first child of the family.
        /// @param child Child wrapper to add.
        Family &AddHead(const Root &child);
        /// @brief [ @b MUIM_Family_AddTail ] Adds an object as the last child of the family.
        /// @param pChildObject Child object to add.
        Family &AddTail(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_AddTail ] Adds an object as the last child of the family.
        /// @param child Child wrapper to add.
        Family &AddTail(const Root &child);

#ifdef MUIM_Family_DoChildMethods
        /// @brief [ @b MUIM_Family_DoChildMethods ] Invokes the same method call on all children of the family.
        /// @param args Raw method ID and arguments forwarded to each child.
        /// @return Reference to this family.
        template <typename... Args> Family &DoChildMethods(Args... args)
        {
            DoMethod(muiObject(), MUIM_Family_DoChildMethods, args...);
            return *this;
        }
#endif

#ifdef MUIM_Family_GetChild
        /// @brief [ @b MUIM_Family_GetChild ] Returns a child selected by index or by a special MUIV_Family_GetChild_* selector.
        /// @param nr Zero-based child index or one of the special MUIV_Family_GetChild_* values.
        /// @param ref Reference object used by selectors like Next/Previous.
        /// @return Matching child object or nullptr if no child matches.
        Object *GetChild(const long nr, const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild ] Returns a child selected by index or by a special MUIV_Family_GetChild_* selector.
        /// @param nr Zero-based child index or one of the special MUIV_Family_GetChild_* values.
        /// @param ref Reference child wrapper used by selectors like Next/Previous.
        /// @return Matching child object or nullptr if no child matches.
        Object *GetChild(const long nr, const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_First ] Returns the first child of the family.
        Object *GetChildFirst() const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Last ] Returns the last child of the family.
        Object *GetChildLast() const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Next ] Returns the next child after the given reference child.
        Object *GetChildNext(const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Next ] Returns the next child after the given reference child.
        Object *GetChildNext(const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Previous ] Returns the previous child before the given reference
        /// child.
        Object *GetChildPrevious(const Object *ref = nullptr) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Previous ] Returns the previous child before the given reference
        /// child.
        Object *GetChildPrevious(const Root &ref) const;
        /// @brief [ @b MUIM_Family_GetChild, @b MUIV_Family_GetChild_Iterate ] Iterates over the family using an iterator state array.
        /// @param iteratorRef Pointer to the iterator state array described by the MUI docs.
        /// @return Next child object in iteration order or nullptr when iteration is complete.
        Object *GetChildIterate(void *iteratorRef) const;
#endif

        /// @brief [ @b MUIM_Family_Insert ] Inserts an object after another object in the family.
        /// @param pChildObject Child object to insert.
        /// @param pPredecessorObject Existing family member after which the new object is inserted.
        Family &Insert(const Object *pChildObject, const Object *pPredecessorObject);
        /// @brief [ @b MUIM_Family_Insert ] Inserts an object after another object in the family.
        /// @param obj Child wrapper to insert.
        /// @param pred Existing family member wrapper after which the new object is inserted.
        Family &Insert(const MUI::Root &obj, const MUI::Root &pred);
        /// @brief [ @b MUIM_Family_Remove ] Removes an object from the family.
        /// @param pChildObject Child object to remove.
        Family &Remove(const Object *pChildObject);
        /// @brief [ @b MUIM_Family_Remove ] Removes an object from the family.
        /// @param obj Child wrapper to remove.
        Family &Remove(const MUI::Root &obj);

#ifdef MUIM_Family_Reorder
        /// @brief [ @b MUIM_Family_Reorder ] Reorders the given children relative to the specified anchor object.
        /// @param after Object after which the given children should be placed; use nullptr for front and (Object *)-1 for back.
        /// @param objects NULL-terminated order source expressed as a vector.
        /// @note Prefer @b ReorderFront or @b ReorderBack for the special front/back cases.
        Family &Reorder(const Object *after, const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder ] Reorders the given children relative to the specified anchor object.
        /// @param after Object after which the given children should be placed; use nullptr for front and (Object *)-1 for back.
        /// @param objects NULL-terminated order source expressed as an initializer list.
        /// @note Prefer @b ReorderFront or @b ReorderBack for the special front/back cases.
        Family &Reorder(const Object *after, const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = 0 ] Reorders the given children to the front of the family child list.
        Family &ReorderFront(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = 0 ] Reorders the given children to the front of the family child list.
        Family &ReorderFront(const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = -1 ] Reorders the given children to the end of the family child list.
        Family &ReorderBack(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Reorder, after = -1 ] Reorders the given children to the end of the family child list.
        Family &ReorderBack(const std::initializer_list<const Object *> &objects);
#endif

        /// @brief [ @b MUIM_Family_Sort ] Sorts the family children into the order given by the vector.
        Family &Sort(const std::vector<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Sort ] Sorts the family children into the order given by the initializer list.
        Family &Sort(const std::initializer_list<const Object *> &objects);
        /// @brief [ @b MUIM_Family_Transfer ] Transfers all children from this family to another family, preserving their order.
        /// @param pDestinationFamilyObject Destination family object.
        Family &Transfer(const Object *pDestinationFamilyObject);
        /// @brief [ @b MUIM_Family_Transfer ] Transfers all children from this family to another family, preserving their order.
        /// @param destinationFamily Destination family wrapper.
        Family &Transfer(const Family &destinationFamily);
    };

    template <typename T, typename U> class FamilyBuilderTemplate : public NotifyBuilderTemplate<T, U>
    {
      public:
        FamilyBuilderTemplate(const std::string &uniqueId = MUI::EmptyUniqueId, const std::string &muiClassName = MUIC_Family)
          : NotifyBuilderTemplate<T, U>(uniqueId, muiClassName)
        {
        }

        /// @brief [ @b MUIA_Family_Child ] Adds a child object at family creation time.
        /// @param child Root wrapper of the child object.
        /// @param condition If false, the tag is omitted.
        T &tagChild(const MUI::Root &child, bool condition = true);
        /// @brief [ @b MUIA_Family_Child ] Adds a child object at family creation time.
        /// @param pChildObject Pointer to the child object.
        /// @param condition If false, the tag is omitted.
        T &tagChild(const Object *pChildObject, bool condition = true);
        /// @brief [ @b MUIA_Family_Child ] Adds an explicit nullptr child tag.
        /// This preserves the original MUI semantics where a NULL child causes family creation to fail.
        /// @param condition If false, the tag is omitted.
        T &tagChildNull(bool condition = true);
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
