# AmigaOS.MUI.cpp.wrapper
AmigaOS/MorphOS MUI C++ wrapper classes

**Not all MUI classes/attributes/methods are implemented! (work in progress)**
___
## Requirements for build

### MorphOS compilation

- MorphOS SDK3.18+
- [TextEditor developer files](https://github.com/amiga-mui/texteditor)
- [NList developer files](https://github.com/amiga-mui/nlist)

### Linux cross compilation for AmigaOS

- [bebbo/amiga-gcc](https://github.com/bebbo/amiga-gcc)
- [AmigaOS MUI5+ developer files](https://github.com/amiga-mui/muidev)
- [TextEditor developer files](https://github.com/amiga-mui/texteditor)
- [NList developer files](https://github.com/amiga-mui/nlist)
___
## Build

*Linux cross compilation for AmigaOS3 m68k*
```
$ make aos_m68k
```

*Linux rebuild (parallel on 4 threads/cores) for AmigaOS3 m68k*
```
$ make clean ; make aos_m68k -j 4
```

*MorphOS PowerPC compilation*
```
$ make mos_ppc
```

*MorphOS rebuild*
```
$ make clean ; make mos_ppc
```

### build structure in *wrappers* folder
```
obj -> morphos  -> ppc  -> *.o
    -> amigaos  -> m68k -> *.o

lib -> morphos  -> ppc  -> libMUIcpp.a
    -> amigaos  -> m68k -> libMUIcpp.a
```
___
## Examples

*basic example*

All code in one file, see: [Main.cpp](/examples/basic/Main.cpp)

![git desktop window](/docs/assets/basic.example.png)

*advanced example*

Code extended and divided in many files (Components), see: [advanced](/examples/advanced/)

![git desktop window](/docs/assets/advanced.example.png)

___
## Implementation status (partial)

| MUI/MCC class | C++ class | Wrapper | Builder | Source Notifier | Dest Notifier |
|-|-|:-:|:-:|:-:|:-:|
| [MUIC_Application](https://github.com/amiga-mui/muidev/wiki/MUI_Application) | [MUI::Application](/wrappers/src/MUI/Application.hpp) | in progress | in progress | - | in progress |
| [MUIC_Area](https://github.com/amiga-mui/muidev/wiki/MUI_Area) | [MUI::Area](/wrappers/src/MUI/Area.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Balance](https://github.com/amiga-mui/muidev/wiki/MUI_Balance) | [MUI::Balance](/wrappers/src/MUI/Balance.hpp) | Ready | Ready | not applicable | not applicable |
| [MUIC_Bitmap](https://github.com/amiga-mui/muidev/wiki/MUI_Bitmap) | - | - | - | - | - |
| [MUIC_Cycle](https://github.com/amiga-mui/muidev/wiki/MUI_Cycle) | [MUI::Cycle](/wrappers/src/MUI/Cycle.hpp) | Ready | Ready | Ready | Ready |
| [MUIC_Family](https://github.com/amiga-mui/muidev/wiki/MUI_Family) | [MUI::Family](/wrappers/src/MUI/Family.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Floattext](https://github.com/amiga-mui/muidev/wiki/MUI_Floattext) | [MUI::Floattext](/wrappers/src/MUI/Family.hpp) | in progress | in progress | - | - |
| [MUIC_Gadget](https://github.com/amiga-mui/muidev/wiki/MUI_Gadget) | [MUI::Gadget](/wrappers/src/MUI/Gadget.hpp) | Ready | Ready | not applicable | not applicable |
| [MUIC_Group](https://github.com/amiga-mui/muidev/wiki/MUI_Group) | [MUI::Group](/wrappers/src/MUI/Group.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Image](https://github.com/amiga-mui/muidev/wiki/MUI_Image) | [MUI::Image](/wrappers/src/MUI/Image.hpp) | in progress | in progress | - | - |
| [MUIC_List](https://github.com/amiga-mui/muidev/wiki/MUI_List) | [MUI::List](/wrappers/src/MUI/List.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Listview](https://github.com/amiga-mui/muidev/wiki/MUI_Listview) | [MUI::Listview](/wrappers/src/MUI/Listview.hpp) | in progress | in progress | - | - |
| [MUIC_Menu](https://github.com/amiga-mui/muidev/wiki/MUI_Menu) | [MUI::Menu](/wrappers/src/MUI/Menu.hpp) | Ready | Ready | in progress | in progress |
| [MUIC_Menuitem](https://github.com/amiga-mui/muidev/wiki/MUI_Menuitem) | [MUI::Menuitem](/wrappers/src/MUI/Menuitem.hpp) | in progress | Ready | in progress | in progress |
| [MUIC_Prop](https://github.com/amiga-mui/muidev/wiki/MUI_Prop) | [MUI::Prop](/wrappers/src/MUI/Prop.hpp) | Ready | Ready | Ready | Ready |
| [MUIC_Scrollbar](https://github.com/amiga-mui/muidev/wiki/MUI_Scrollbar) | [MUI::Scrollbar](/wrappers/src/MUI/Scrollbar.hpp) | Ready | Ready | - | - |

___
## Additional info

Method comments in Wrapper classes are mostly from [MUI documentation](https://github.com/amiga-mui/muidev/wiki).
