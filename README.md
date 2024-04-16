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

![basic example window](/docs/assets/basic.example.png)

*advanced example*

Code extended and divided in many files (Components), see: [advanced](/examples/advanced/)

![advanced example window](/docs/assets/advanced.example.png)

___
## Implementation status

| MUI/MCC class | C++ class | Wrapper | Builder | Source Notifier | Dest Notifier |
|-|-|:-:|:-:|:-:|:-:|
| [MUIC_Application](https://github.com/amiga-mui/muidev/wiki/MUI_Application) | [MUI::Application](/wrappers/src/MUI/Application.hpp) | in progress | in progress | - | in progress |
| [MUIC_Area](https://github.com/amiga-mui/muidev/wiki/MUI_Area) | [MUI::Area](/wrappers/src/MUI/Area.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Argstring](https://github.com/amiga-mui/muidev/wiki/MUI_Argstring) | - | - | - | - | - |
| [MUIC_Balance](https://github.com/amiga-mui/muidev/wiki/MUI_Balance) | [MUI::Balance](/wrappers/src/MUI/Balance.hpp) | Ready | Ready | not applicable | not applicable |
| [MUIC_Bitmap](https://github.com/amiga-mui/muidev/wiki/MUI_Bitmap) | - | - | - | - | - |
| [MUIC_Bodychunk](https://github.com/amiga-mui/muidev/wiki/MUI_Bodychunk) | - | - | - | - | - |
| [MUIC_Boopsi](https://github.com/amiga-mui/muidev/wiki/MUI_Boopsi) | - | - | - | - | - |
| [MUIC_Coloradjust](https://github.com/amiga-mui/muidev/wiki/MUI_Coloradjust) | - | - | - | - | - |
| [MUIC_Colorfield](https://github.com/amiga-mui/muidev/wiki/MUI_Colorfield) | - | - | - | - | - |
| [MUIC_Cycle](https://github.com/amiga-mui/muidev/wiki/MUI_Cycle) | [MUI::Cycle](/wrappers/src/MUI/Cycle.hpp) | Ready | Ready | Ready | Ready |
| [MUIC_Datamap](https://github.com/amiga-mui/muidev/wiki/MUI_Datamap) | - | - | - | - | - |
| [MUIC_Dataspace](https://github.com/amiga-mui/muidev/wiki/MUI_Dataspace) | - | - | - | - | - |
| [MUIC_Dirlist](https://github.com/amiga-mui/muidev/wiki/MUI_Dirlist) | - | - | - | - | - |
| [MUIC_Dtpic](https://github.com/amiga-mui/muidev/wiki/MUI_Dtpic) | [MUI::Dtpict](/wrappers/src/MUI/Dtpict.hpp) | Ready | Ready | - | - |
| [MUIC_Family](https://github.com/amiga-mui/muidev/wiki/MUI_Family) | [MUI::Family](/wrappers/src/MUI/Family.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Filepanel](https://github.com/amiga-mui/muidev/wiki/MUI_Filepanel) | - | - | - | - | - |
| [MUIC_Floattext](https://github.com/amiga-mui/muidev/wiki/MUI_Floattext) | [MUI::Floattext](/wrappers/src/MUI/Family.hpp) | in progress | in progress | - | - |
| [MUIC_Fontdisplay](https://github.com/amiga-mui/muidev/wiki/MUI_Fontdisplay) | - | - | - | - | - |
| [MUIC_Fontpanel](https://github.com/amiga-mui/muidev/wiki/MUI_Fontpanel) | [MUI::Fontpanel](/wrappers/src/MUI/Fontpanel.hpp) | Ready | Ready | - | - |
| [MUIC_Gadget](https://github.com/amiga-mui/muidev/wiki/MUI_Gadget) | [MUI::Gadget](/wrappers/src/MUI/Gadget.hpp) | Ready | Ready | not applicable | not applicable |
| [MUIC_Gauge](https://github.com/amiga-mui/muidev/wiki/MUI_Gauge) | - | - | - | - | - |
| [MUIC_Group](https://github.com/amiga-mui/muidev/wiki/MUI_Group) | [MUI::Group](/wrappers/src/MUI/Group.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Image](https://github.com/amiga-mui/muidev/wiki/MUI_Image) | [MUI::Image](/wrappers/src/MUI/Image.hpp) | in progress | in progress | - | - |
| [MUIC_Keyadjust](https://github.com/amiga-mui/muidev/wiki/MUI_Keyadjust) | - | - | - | - | - |
| [MUIC_Knob](https://github.com/amiga-mui/muidev/wiki/MUI_Knob) | - | - | - | - | - |
| [MUIC_Levelmeter](https://github.com/amiga-mui/muidev/wiki/MUI_Levelmeter) | - | - | - | - | - |
| [MUIC_List](https://github.com/amiga-mui/muidev/wiki/MUI_List) | [MUI::List](/wrappers/src/MUI/List.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Listview](https://github.com/amiga-mui/muidev/wiki/MUI_Listview) | [MUI::Listview](/wrappers/src/MUI/Listview.hpp) | in progress | in progress | - | - |
| [MUIC_Mccprefs](https://github.com/amiga-mui/muidev/wiki/MUI_Mccprefs) | - | - | - | - | - |
| [MUIC_Menu](https://github.com/amiga-mui/muidev/wiki/MUI_Menu) | [MUI::Menu](/wrappers/src/MUI/Menu.hpp) | Ready | Ready | in progress | in progress |
| [MUIC_Menuitem](https://github.com/amiga-mui/muidev/wiki/MUI_Menuitem) | [MUI::Menuitem](/wrappers/src/MUI/Menuitem.hpp) | in progress | Ready | in progress | in progress |
| [MUIC_Menustrip](https://github.com/amiga-mui/muidev/wiki/MUI_Menustrip) | [MUI::Menustrip](/wrappers/src/MUI/Menustrip.hpp) | in progress | Ready | - | - |
| [MUIC_Notify](https://github.com/amiga-mui/muidev/wiki/MUI_Notify) | [MUI::Notify](/wrappers/src/MUI/Notify.hpp) | in progress | Ready | in progress | in progress |
| [MUIC_Numericbutton](https://github.com/amiga-mui/muidev/wiki/MUI_Numericbutton) | - | - | - | - | - |
| [MUIC_Numeric](https://github.com/amiga-mui/muidev/wiki/MUI_Numeric) | [MUI::Numeric](/wrappers/src/MUI/Numeric.hpp) | Ready | Ready | - | - |
| [MUIC_Objectmap](https://github.com/amiga-mui/muidev/wiki/MUI_Objectmap) | - | - | - | - | - |
| [MUIC_Palette](https://github.com/amiga-mui/muidev/wiki/MUI_Palette) | - | - | - | - | - |
| [MUIC_Panel](https://github.com/amiga-mui/muidev/wiki/MUI_Panel) | [MUI::Panel](/wrappers/src/MUI/Panel.hpp) | Ready | Ready | not applicable | not applicable |
| [MUIC_Penadjust](https://github.com/amiga-mui/muidev/wiki/MUI_Penadjust) | - | - | - | - | - |
| [MUIC_Pendisplay](https://github.com/amiga-mui/muidev/wiki/MUI_Pendisplay) | - | - | - | - | - |
| [MUIC_Pixmap](https://github.com/amiga-mui/muidev/wiki/MUI_Pixmap) | - | - | - | - | - |
| [MUIC_Popasl](https://github.com/amiga-mui/muidev/wiki/MUI_Popasl) | [MUI::Popasl](/wrappers/src/MUI/Popasl.hpp) | Ready | Ready | - | - |
| [MUIC_Poplist](https://github.com/amiga-mui/muidev/wiki/MUI_Poplist) | - | - | - | - | - |
| [MUIC_Popobject](https://github.com/amiga-mui/muidev/wiki/MUI_Popobject) | - | - | - | - | - |
| [MUIC_Poppen](https://github.com/amiga-mui/muidev/wiki/MUI_Poppen) | - | - | - | - | - |
| [MUIC_Popscreen](https://github.com/amiga-mui/muidev/wiki/MUI_Popscreen) | - | - | - | - | - |
| [MUIC_Popstring](https://github.com/amiga-mui/muidev/wiki/MUI_Popstring) | [MUI::Popstring](/wrappers/src/MUI/Popstring.hpp) | Ready | Ready | - | - |
| [MUIC_Process](https://github.com/amiga-mui/muidev/wiki/MUI_Process) | - | - | - | - | - |
| [MUIC_Prop](https://github.com/amiga-mui/muidev/wiki/MUI_Prop) | [MUI::Prop](/wrappers/src/MUI/Prop.hpp) | Ready | Ready | Ready | Ready |
| [MUIC_Radio](https://github.com/amiga-mui/muidev/wiki/MUI_Radio) | [MUI::Radio](/wrappers/src/MUI/Radio.hpp) | Ready | Ready | - | - |
| [MUIC_Rectangle](https://github.com/amiga-mui/muidev/wiki/MUI_Rectangle) | [MUI::Rectangle](/wrappers/src/MUI/Rectangle.hpp) | Ready | Ready | not applicable | - |
| [MUIC_Register](https://github.com/amiga-mui/muidev/wiki/MUI_Register) | [MUI::Register](/wrappers/src/MUI/Register.hpp) | Ready | Ready | not applicable | Ready |
| [MUIC_Scale](https://github.com/amiga-mui/muidev/wiki/MUI_Scale) | - | - | - | - | - |
| [MUIC_Screenmodepanel](https://github.com/amiga-mui/muidev/wiki/MUI_Screenmodepanel) | - | - | - | - | - |
| [MUIC_Scrmodelist](https://github.com/amiga-mui/muidev/wiki/MUI_Scrmodelist) | - | - | - | - | - |
| [MUIC_Scrollbar](https://github.com/amiga-mui/muidev/wiki/MUI_Scrollbar) | [MUI::Scrollbar](/wrappers/src/MUI/Scrollbar.hpp) | Ready | Ready | - | - |
| [MUIC_Scrollgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Scrollgroup) | [MUI::Scrollgroup](/wrappers/src/MUI/Scrollgroup.hpp) | in progress | Ready | - | - |
| [MUIC_Selectgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Selectgroup) | - | - | - | - | - |
| [MUIC_Semaphore](https://github.com/amiga-mui/muidev/wiki/MUI_Semaphore) | - | - | - | - | - |
| [MUIC_Slave](https://github.com/amiga-mui/muidev/wiki/MUI_Slave) | - | - | - | - | - |
| [MUIC_Slider](https://github.com/amiga-mui/muidev/wiki/MUI_Slider) | [MUI::Slider](/wrappers/src/MUI/Slider.hpp) | Ready | Ready | - | - |
| [MUIC_String](https://github.com/amiga-mui/muidev/wiki/MUI_Sting) | [MUI::String](/wrappers/src/MUI/String.hpp) | in progress | in progress | in progress | in progress |
| [MUIC_Textdata](https://github.com/amiga-mui/muidev/wiki/MUI_Textdata) | - | - | - | - | - |
| [MUIC_Text](https://github.com/amiga-mui/muidev/wiki/MUI_Text) | [MUI::Text](/wrappers/src/MUI/Text.hpp) | in progress | in progress | - | - |
| [MUIC_Title](https://github.com/amiga-mui/muidev/wiki/MUI_Title) | [MUI::Title](/wrappers/src/MUI/Title.hpp) | in progress | Ready | - | - |
| [MUIC_Virtgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Virtgroup) | [MUI::Virtgroup](/wrappers/src/MUI/Virtgroup.hpp) | in progress | Ready | - | - |
| [MUIC_Volumelist](https://github.com/amiga-mui/muidev/wiki/MUI_Volumelist) | - | - | - | - | - |
| [MUIC_Window](https://github.com/amiga-mui/muidev/wiki/MUI_Window) | [MUI::Window](/wrappers/src/MUI/Window.hpp) | in progress | in progress | in progress | in progress |
| ... | ... | - | - | - | - |
| MUIC_Busy | [MUI::Busy](/wrappers/src/MUI/MCC/Busy.hpp) | Ready | Ready | - | - |
| ... | ... | - | - | - | - |
___
## Additional info

Method comments in Wrapper classes are mostly from [MUI documentation](https://github.com/amiga-mui/muidev/wiki).
