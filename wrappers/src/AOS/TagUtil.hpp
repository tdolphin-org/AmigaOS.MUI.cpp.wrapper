//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include <exec/types.h>
#include <map>
#include <string>
#include <utility/tagitem.h>

namespace AOS
{
    class TagUtil
    {
        enum class ValueType
        {
            Default,
            String, // STRPTR, CONST_STRPTR
            StringArray, // CONST_STRPTR *
            Bool, // BOOL
            Byte, //  BYTE
            Char, // CHAR
            Word, // WORD
            Long, // LONG
            ULong, // ULONG
            Pointer, // Object *, struct XXX *, APTR
            Int64Pointer, // int64 *
        };

        struct TagSpec
        {
            std::string tagName;
            enum ValueType valueType;
        };

        /// @brief TAG_NAME => (TAG_NAME as string, tag value type)
        static std::map<Tag, TagSpec> mNames;

      public:
        static std::string toString(const Tag tagName);
        static std::string toString(const TagItem &tagItem);

        static std::string TagDataSTRPTR(const ULONG value);
        static std::string TagDataBool(const ULONG value);
        static std::string TagDataChar(const ULONG value);
    };
}