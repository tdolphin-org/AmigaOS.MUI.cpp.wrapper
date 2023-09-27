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
