# AmigaOS.MUI.cpp.wrapper
AmigaOS/MorphOS MUI C++ Wrapper Classes is a modern C++17 library that provides wrapper classes for the Magic User Interface (MUI) on AmigaOS and MorphOS. These classes simplify interaction with the MUI API, enabling developers to use C++ idioms and abstractions to build robust and maintainable user interfaces. The library encapsulates MUI elements within object-oriented classes, improving code readability and reducing the need for low-level MUI calls, thus allowing developers to focus on higher-level design and functionality.

**Not all MUI classes/attributes/methods are implemented! (work in progress)**
___
## Requirements for build

### MorphOS compilation

- AmigaOS.cpp.wrapper (https://github.com/tdolphin-org/AmigaOS.cpp.wrapper) located in path *../AmigaOS.cpp.wrapper*
- MorphOS SDK3.18+
- [TextEditor developer files](https://github.com/amiga-mui/texteditor)
- [NList developer files](https://github.com/amiga-mui/nlist)

### Linux cross compilation for AmigaOS

- AmigaOS.cpp.wrapper (https://github.com/tdolphin-org/AmigaOS.cpp.wrapper) located in path *../AmigaOS.cpp.wrapper*
- [bebbo/amiga-gcc](https://codeberg.org/bebbo/amiga-gcc)
- [AmigaOS MUI5 developer files](https://github.com/amiga-mui/muidev) or [AmigaOS MUI3.8 developer files](https://aminet.net/package/dev/mui/mui38dev)
- [TextEditor developer files](https://github.com/amiga-mui/texteditor)
- [NList developer files](https://github.com/amiga-mui/nlist)

### Linux cross compilation for MorphOS

- AmigaOS.cpp.wrapper (https://github.com/tdolphin-org/AmigaOS.cpp.wrapper) located in path *../AmigaOS.cpp.wrapper*
- [MorphOS SDK deb](https://bigfoot.morphos-team.net/test/morphos-sdk_20230510-1_amd64.deb)
- [setup-cross-sdk.sh script](https://bigfoot.morphos-team.net/files/setup-cross-sdk.sh)
- [TextEditor developer files](https://github.com/amiga-mui/texteditor)
- [NList developer files](https://github.com/amiga-mui/nlist)
___
## Build

*AmigaOS3 m68k (Linux cross compilation)*
```
$ make cross_aos_m68k
```

*AmigaOS3 m68k rebuild, parallel on 4 threads/cores (Linux cross compilation) *
```
$ make clean ; make cross_aos_m68k -j 4
```

*MorphOS PowerPC compilation*
```
$ make mos_ppc
```

*MorphOS rebuild*
```
$ make clean ; make mos_ppc
```

*MorphOS PowerPC (Linux cross compilation)*
```
$ make cross_mos_ppc
```

*MorphOS PowerPC rebuild, parallel on 4 threads/cores (Linux cross compilation)*
```
$ make clean ; make cross_mos_ppc -j 4
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

### Column names descriptions

- Wrapper 3.8 = status of wrapper implementation for MUI 3.8 if appicable
- Wrapper AMUI5 = status of wrapper implementation of extra attributes and methods for AmigaOS MUI 5.0 if applicable
- Wrapper MMUI5 = status of wrapper implementation of extra attributes and methods for MorphOS MUI 5.0 if applicable
- Builder 3.8 = status of builder implementation for MUI 3.8 if appicable
- Builder AMUI5 = status of builder implementation of extra attributes for AmigaOS MUI 5.0 if applicable
- Builder MMUI5 = status of builder implementation of extra attributes for MorphOS MUI 5.0 if applicable

### Version tags

- `3.8` = MUI 3.8
- `AMUI5` = AmigaOS MUI 5.0
- `MMUI5` = MorphOS MUI 5.0
- `n/a` = class/element is not available in that version (always apply to MUI 3.8 in this project)

| MUI class | C++ class | Wrapper 3.8 | Wrapper AMUI5 | Wrapper MMUI5 | Builder 3.8 | Builder AMUI5 | Builder MMUI5 | Source Notifier | Dest Notifier |
|-|-|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| [MUIC_Application](https://github.com/amiga-mui/muidev/wiki/MUI_Application) | [MUI::Application](/wrappers/src/MUI/Application.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | in progress |
| [MUIC_Aboutmui](https://github.com/amiga-mui/muidev/wiki/MUI_Aboutmui) | [MUI::Aboutmui](/wrappers/src/MUI/Aboutmui.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Area](https://github.com/amiga-mui/muidev/wiki/MUI_Area) | [MUI::Area](/wrappers/src/MUI/Area.hpp) | Ready | in progress | in progress | Ready | in progress | in progress | in progress | in progress |
| [MUIC_Argstring](https://github.com/amiga-mui/muidev/wiki/MUI_Argstring) | [MUI::Argstring](/wrappers/src/MUI/Argstring.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Balance](https://github.com/amiga-mui/muidev/wiki/MUI_Balance) | [MUI::Balance](/wrappers/src/MUI/Balance.hpp) | Ready | in progress | in progress | Ready | in progress | in progress | not applicable | not applicable |
| [MUIC_Bitmap](https://github.com/amiga-mui/muidev/wiki/MUI_Bitmap) | [MUI::Bitmap](/wrappers/src/MUI/Bitmap.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Bodychunk](https://github.com/amiga-mui/muidev/wiki/MUI_Bodychunk) | [MUI::Bodychunk](/wrappers/src/MUI/Bodychunk.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Boopsi](https://github.com/amiga-mui/muidev/wiki/MUI_Boopsi) | [MUI::Boopsi](/wrappers/src/MUI/Boopsi.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Coloradjust](https://github.com/amiga-mui/muidev/wiki/MUI_Coloradjust) | [MUI::Coloradjust](/wrappers/src/MUI/Coloradjust.hpp) | Ready | - | Ready | Ready | - | Ready | - | - |
| [MUIC_Colorfield](https://github.com/amiga-mui/muidev/wiki/MUI_Colorfield) | [MUI::Colorfield](/wrappers/src/MUI/Colorfield.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Cycle](https://github.com/amiga-mui/muidev/wiki/MUI_Cycle) | [MUI::Cycle](/wrappers/src/MUI/Cycle.hpp) | Ready | Ready | Ready | Ready | - | - | Ready | Ready |
| [MUIC_Datamap](https://github.com/amiga-mui/muidev/wiki/MUI_Datamap) | [MUI::Datamap](/wrappers/src/MUI/Datamap.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Dataspace](https://github.com/amiga-mui/muidev/wiki/MUI_Dataspace) | [MUI::Dataspace](/wrappers/src/MUI/Dataspace.hpp) | Ready | Ready | Ready | Ready | - | - | - | - |
| [MUIC_Dirlist](https://github.com/amiga-mui/muidev/wiki/MUI_Dirlist) | [MUI::Dirlist](/wrappers/src/MUI/Dirlist.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Dtpic](https://github.com/amiga-mui/muidev/wiki/MUI_Dtpic) | [MUI::Dtpic](/wrappers/src/MUI/Dtpic.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Family](https://github.com/amiga-mui/muidev/wiki/MUI_Family) | [MUI::Family](/wrappers/src/MUI/Family.hpp) | Ready | Ready | Ready | Ready | - | - | in progress | in progress |
| [MUIC_Filepanel](https://github.com/amiga-mui/muidev/wiki/MUI_Filepanel) | [MUI::Filepanel](/wrappers/src/MUI/Filepanel.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Floattext](https://github.com/amiga-mui/muidev/wiki/MUI_Floattext) | [MUI::Floattext](/wrappers/src/MUI/Floattext.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Fontdisplay](https://github.com/amiga-mui/muidev/wiki/MUI_Fontdisplay) | [MUI::Fontdisplay](/wrappers/src/MUI/Fontdisplay.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Fontpanel](https://github.com/amiga-mui/muidev/wiki/MUI_Fontpanel) | [MUI::Fontpanel](/wrappers/src/MUI/Fontpanel.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Gadget](https://github.com/amiga-mui/muidev/wiki/MUI_Gadget) | [MUI::Gadget](/wrappers/src/MUI/Gadget.hpp) | Ready | - | - | Ready | - | - | not applicable | not applicable |
| [MUIC_Gauge](https://github.com/amiga-mui/muidev/wiki/MUI_Gauge) | [MUI::Gauge](/wrappers/src/MUI/Gauge.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Group](https://github.com/amiga-mui/muidev/wiki/MUI_Group) | [MUI::Group](/wrappers/src/MUI/Group.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| [MUIC_Image](https://github.com/amiga-mui/muidev/wiki/MUI_Image) | [MUI::Image](/wrappers/src/MUI/Image.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Keyadjust](https://github.com/amiga-mui/muidev/wiki/MUI_Keyadjust) | [MUI::Keyadjust](/wrappers/src/MUI/Keyadjust.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Knob](https://github.com/amiga-mui/muidev/wiki/MUI_Knob) | [MUI::Knob](/wrappers/src/MUI/Knob.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Levelmeter](https://github.com/amiga-mui/muidev/wiki/MUI_Levelmeter) | [MUI::Levelmeter](/wrappers/src/MUI/Levelmeter.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_List](https://github.com/amiga-mui/muidev/wiki/MUI_List) | [MUI::List](/wrappers/src/MUI/List.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| [MUIC_Listview](https://github.com/amiga-mui/muidev/wiki/MUI_Listview) | [MUI::Listview](/wrappers/src/MUI/Listview.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Mccprefs](https://github.com/amiga-mui/muidev/wiki/MUI_Mccprefs) | [MUI::Mccprefs](/wrappers/src/MUI/Mccprefs.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Menu](https://github.com/amiga-mui/muidev/wiki/MUI_Menu) | [MUI::Menu](/wrappers/src/MUI/Menu.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| [MUIC_Menuitem](https://github.com/amiga-mui/muidev/wiki/MUI_Menuitem) | [MUI::Menuitem](/wrappers/src/MUI/Menuitem.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| [MUIC_Menustrip](https://github.com/amiga-mui/muidev/wiki/MUI_Menustrip) | [MUI::Menustrip](/wrappers/src/MUI/Menustrip.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Notify](https://github.com/amiga-mui/muidev/wiki/MUI_Notify) | [MUI::Notify](/wrappers/src/MUI/Notify.hpp) | Ready | Ready | Ready | Ready | - | - | in progress | in progress |
| [MUIC_Numericbutton](https://github.com/amiga-mui/muidev/wiki/MUI_Numericbutton) | [MUI::Numericbutton](/wrappers/src/MUI/Numericbutton.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Numeric](https://github.com/amiga-mui/muidev/wiki/MUI_Numeric) | [MUI::Numeric](/wrappers/src/MUI/Numeric.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Objectmap](https://github.com/amiga-mui/muidev/wiki/MUI_Objectmap) | [MUI::Objectmap](/wrappers/src/MUI/Objectmap.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Palette](https://github.com/amiga-mui/muidev/wiki/MUI_Palette) | [MUI::Palette](/wrappers/src/MUI/Palette.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Panel](https://github.com/amiga-mui/muidev/wiki/MUI_Panel) | [MUI::Panel](/wrappers/src/MUI/Panel.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | not applicable | not applicable |
| [MUIC_Penadjust](https://github.com/amiga-mui/muidev/wiki/MUI_Penadjust) | [MUI::Penadjust](/wrappers/src/MUI/Penadjust.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Pendisplay](https://github.com/amiga-mui/muidev/wiki/MUI_Pendisplay) | [MUI::Pendisplay](/wrappers/src/MUI/Pendisplay.hpp) | Ready | - | Ready | Ready | - | Ready | in progress | in progress |
| [MUIC_Pixmap](https://github.com/amiga-mui/muidev/wiki/MUI_Pixmap) | [MUI::Pixmap](/wrappers/src/MUI/Pixmap.hpp) | n/a | Ready | n/a | n/a | Ready | n/a | - | - |
| [MUIC_Popasl](https://github.com/amiga-mui/muidev/wiki/MUI_Popasl) | [MUI::Popasl](/wrappers/src/MUI/Popasl.hpp) | Ready | - | Ready | Ready | - | Ready | - | - |
| [MUIC_Poplist](https://github.com/amiga-mui/muidev/wiki/MUI_Poplist) | [MUI::Poplist](/wrappers/src/MUI/Poplist.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Popobject](https://github.com/amiga-mui/muidev/wiki/MUI_Popobject) | [MUI::Popobject](/wrappers/src/MUI/Popobject.hpp) | Ready | - | n/a | Ready | - | n/a | - | - |
| [MUIC_Poppen](https://github.com/amiga-mui/muidev/wiki/MUI_Poppen) | [MUI::Poppen](/wrappers/src/MUI/Poppen.hpp) | Ready | - | n/a | Ready | - | n/a | not applicable | not applicable |
| [MUIC_Popscreen](https://github.com/amiga-mui/muidev/wiki/MUI_Popscreen) | [MUI::Popscreen](/wrappers/src/MUI/Popscreen.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Popstring](https://github.com/amiga-mui/muidev/wiki/MUI_Popstring) | [MUI::Popstring](/wrappers/src/MUI/Popstring.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Process](https://github.com/amiga-mui/muidev/wiki/MUI_Process) | [MUI::Process](/wrappers/src/MUI/Process.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | not applicable | not applicable |
| [MUIC_Prop](https://github.com/amiga-mui/muidev/wiki/MUI_Prop) | [MUI::Prop](/wrappers/src/MUI/Prop.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | Ready | Ready |
| [MUIC_Radio](https://github.com/amiga-mui/muidev/wiki/MUI_Radio) | [MUI::Radio](/wrappers/src/MUI/Radio.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Rectangle](https://github.com/amiga-mui/muidev/wiki/MUI_Rectangle) | [MUI::Rectangle](/wrappers/src/MUI/Rectangle.hpp) | Ready | - | - | Ready | - | - | not applicable | - |
| [MUIC_Register](https://github.com/amiga-mui/muidev/wiki/MUI_Register) | [MUI::Register](/wrappers/src/MUI/Register.hpp) | Ready | Ready | - | Ready | Ready | Ready | not applicable | Ready |
| [MUIC_Scale](https://github.com/amiga-mui/muidev/wiki/MUI_Scale) | [MUI::Scale](/wrappers/src/MUI/Scale.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Screenmodepanel](https://github.com/amiga-mui/muidev/wiki/MUI_Screenmodepanel) | [MUI::Screenmodepanel](/wrappers/src/MUI/Screenmodepanel.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Scrmodelist](https://github.com/amiga-mui/muidev/wiki/MUI_Scrmodelist) | [MUI::Scrmodelist](/wrappers/src/MUI/Scrmodelist.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_Scrollbar](https://github.com/amiga-mui/muidev/wiki/MUI_Scrollbar) | [MUI::Scrollbar](/wrappers/src/MUI/Scrollbar.hpp) | Ready | Ready | - | Ready | Ready | - | - | - |
| [MUIC_Scrollgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Scrollgroup) | [MUI::Scrollgroup](/wrappers/src/MUI/Scrollgroup.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Selectgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Selectgroup) | [MUI::Selectgroup](/wrappers/src/MUI/Selectgroup.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Semaphore](https://github.com/amiga-mui/muidev/wiki/MUI_Semaphore) | [MUI::Semaphore](/wrappers/src/MUI/Semaphore.hpp) | Ready | - | - | Ready | - | - | not applicable | not applicable |
| [MUIC_Slave](https://github.com/amiga-mui/muidev/wiki/MUI_Slave) | [MUI::Slave](/wrappers/src/MUI/Slave.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | not applicable | not applicable |
| [MUIC_Slider](https://github.com/amiga-mui/muidev/wiki/MUI_Slider) | [MUI::Slider](/wrappers/src/MUI/Slider.hpp) | Ready | - | - | Ready | - | - | - | - |
| [MUIC_String](https://github.com/amiga-mui/muidev/wiki/MUI_String) | [MUI::String](/wrappers/src/MUI/String.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| [MUIC_Textdata](https://github.com/amiga-mui/muidev/wiki/MUI_Textdata) | [MUI::Textdata](/wrappers/src/MUI/Textdata.hpp) | n/a | Ready | n/a | n/a | Ready | n/a | - | - |
| [MUIC_Text](https://github.com/amiga-mui/muidev/wiki/MUI_Text) | [MUI::Text](/wrappers/src/MUI/Text.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Title](https://github.com/amiga-mui/muidev/wiki/MUI_Title) | [MUI::Title](/wrappers/src/MUI/Title.hpp) | n/a | Ready | Ready | n/a | Ready | Ready | - | - |
| [MUIC_Virtgroup](https://github.com/amiga-mui/muidev/wiki/MUI_Virtgroup) | [MUI::Virtgroup](/wrappers/src/MUI/Virtgroup.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | - | - |
| [MUIC_Volumelist](https://github.com/amiga-mui/muidev/wiki/MUI_Volumelist) | [MUI::Volumelist](/wrappers/src/MUI/Volumelist.hpp) | Ready | - | - | Ready | Ready | Ready | - | - |
| [MUIC_Window](https://github.com/amiga-mui/muidev/wiki/MUI_Window) | [MUI::Window](/wrappers/src/MUI/Window.hpp) | Ready | Ready | Ready | Ready | Ready | Ready | in progress | in progress |
| ... | ... | - | - | - | - | - | - | - | - |

| MCC class | C++ class | Wrapper | Builder | Source Notifier | Dest Notifier |
|-|-|:-:|:-:|:-:|:-:|
| MUIC_Busy | [MUI::Busy](/wrappers/src/MUI/MCC/Busy.hpp) | Ready | Ready | - | - |
| ... | ... | - | - | - | - |
___
## Additional info

Method comments in Wrapper classes are mostly from [MUI documentation](https://github.com/amiga-mui/muidev/wiki).
