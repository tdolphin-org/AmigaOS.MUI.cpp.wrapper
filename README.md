# AmigaOS.MUI.cpp.wrapper
AmigaOS/MorphOS MUI C++ wrapper classes
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
make amigaos_m68k
```

*MorphOS compilation*
```
make morphos_ppc
```

### build structure

    obj -> morphos  -> ppc
        -> amigaos  -> m68k

    lib -> morphos  -> ppc
        -> amigaos  -> m68k
