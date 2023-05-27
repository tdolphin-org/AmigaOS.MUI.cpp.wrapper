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

All example code in one file, see: [Main.cpp](/examples/basic/Main.cpp)

![git desktop window](/docs/assets/basic.example.png)
