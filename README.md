# AmigaOS.MUI.cpp.wrapper
AmigaOS/MorphOS MUI C++ wrapper classes

**Not all MUI classes/attributes/methods are implemented! (work in progress)**
___
## Requirements for build

### MorphOS compilation

- MorphOS SDK3.16+
- TextEditor developer files

### Linux cross compilation for AmigaOS

- bebbo/amiga-gcc (https://github.com/bebbo/amiga-gcc)
- AmigaOS MUI5+ developer files
- TextEditor developer files
___
## Build

*Linux cross compilation for AmigaOS3 68k*
```
make aos_m68k
```

*MorphOS PowerPC compilation*
```
make mos_ppc
```

### build structure in *wrappers* folder
```
obj -> morphos  -> ppc
    -> amigaos  -> m68k

lib -> morphos  -> ppc
    -> amigaos  -> m68k
```