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

    // explicitly no copy
    MuiMasterBaseScope(const MuiMasterBaseScope &) = delete;
    MuiMasterBaseScope &operator=(const MuiMasterBaseScope &) = delete;

    // explicitly no move
    MuiMasterBaseScope(MuiMasterBaseScope &&) noexcept = delete;
    MuiMasterBaseScope &operator=(MuiMasterBaseScope &&) noexcept = delete;

    Library *library() const;
};
