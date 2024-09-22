//
//  AmigaOS MUI C++ wrapper
//
//  (c) 2022-2024 TDolphin
//

#include <exec/libraries.h>

class MuiMasterBaseScope
{
  public:
    MuiMasterBaseScope();
    ~MuiMasterBaseScope();

    // copy is forbidden
    MuiMasterBaseScope(const MuiMasterBaseScope &) = delete;
    MuiMasterBaseScope &operator=(const MuiMasterBaseScope &) = delete;

    // move is default
    MuiMasterBaseScope(MuiMasterBaseScope &&other) noexcept = default;
    MuiMasterBaseScope &operator=(MuiMasterBaseScope &&other) noexcept = default;

    Library *library() const;
};
