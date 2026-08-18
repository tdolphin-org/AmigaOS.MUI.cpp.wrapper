# Zadanie: Dodanie obsługi AROS (Zune) do projektu AmigaOS MUI C++ wrapper

## Kontekst

Pracujesz nad projektem **AmigaOS MUI C++ wrapper** — nowoczesną biblioteką C++17
dostarczającą klasy wrapperów dla Magic User Interface (MUI). Projekt wspiera obecnie:

- **AmigaOS 68k MUI 3.8** (target `cross_amigaos_m68k_MUI38`, makro `-DAOS_MUI38`, detekcja `AOS_MUI_VERSION_3_8`)
- **AmigaOS 68k MUI 5.0** (target `cross_amigaos_m68k_MUI5`, makro `-DAOS_MUI5`, detekcja `AOS_MUI_VERSION_5`)
- **MorphOS MUI 5.0** (target `morphos_ppc` / `cross_morphos_ppc`, detekcja `MOS_MUI_VERSION_5`)

Uwaga: **MUI 5.0 dla MorphOS to inna implementacja niż MUI 5.0 dla AmigaOS 68k** —
różne zestawy atrybutów/metod, dlatego w kodzie istnieją osobne makra detekcji.

Celem zadania jest dodanie wsparcia dla **AROS** i jego natywnego GUI — **Zune**
(Zune to kompatybilna z MUI reimplementacja; w AROS realizowana przez
`muimaster.library`). Zakres: cross-kompilacja na Linuxie, detekcja wersji,
targety Makefile dla biblioteki i przykładów, dokumentacja instalacji toolchaina
oraz weryfikacja (uruchomienie w hosted AROS).

Całość prac odbywa się na branchu **`feature/aros-zune-support`**.

---

## Cel

1. Biblioteka `MUIcpp` kompiluje się i linkuje dla **AROS x86_64 (hosted)** przy pomocy
   cross-kompilatora `x86_64-aros-g++`.
2. Przykłady (`basic`, `advanced`) budują się dla AROS i da się je uruchomić w
   hosted AROS (przez `AROSBootstrap`).
3. Istniejące targety (AmigaOS m68k MUI3.8/MUI5, MorphOS PPC) **nie mogą się zepsuć**.
4. W README znajduje się sekcja opisująca, co trzeba zainstalować na Linuxie,
   aby uzyskać cross-kompilację dla AROS.

---

## Etap 1 – Środowisko: cross-kompilacja AROS x86_64 na Linuxie

Aby uzyskać działający cross-kompilator i środowisko testowe (hosted AROS), wykonaj:

**1. Zależności systemowe (Debian/Ubuntu):**
```bash
sudo apt install gcc g++ make git flex bison gawk python3 python3-mako \
                 libx11-dev libpng-dev genisoimage cmake curl nasm \
                 autoconf automake libxext-dev liblzo2-dev libxxf86vm-dev \
                 libsdl1.2-dev byacc yasm xorriso mtools
```
Uwaga: `cmake` jest potrzebny (jeden wewnętrzny komponent builda go wymaga —
bez niego build pada w połowie na cunit).

**2. Źródła AROS — KLUCZOWY WYBÓR REPOZYTORIUM:**
```bash
mkdir -p ~/Aros/arosbuilds && cd ~/Aros/arosbuilds
git clone https://github.com/deadwood2/AROS.git AROS
```
Używaj wyłącznie **`deadwood2/AROS`** (stabilna linia ABIv11). Nie używaj
`aros-development-team/AROS` (bleeding edge) — binarki skompilowane przeciw
innemu ABI natychmiast padają na AROS (typowy błąd: *"Illegal address access"*
w `Exec_B3_OpenResource`).

**3. Zbuduj cross-kompilator:**
```bash
cp ./AROS/scripts/rebuild.sh .
./rebuild.sh
```
Z menu wybierz: `1) toolchain-core-x86_64`. To buduje `x86_64-aros-gcc` i
pokrewne narzędzia (20–40 minut). Wynik: `~/Aros/arosbuilds/toolchain-core-x86_64/`.

**4. Zbuduj hosted AROS (system do testów):**
```bash
./rebuild.sh
```
Z menu wybierz: `2) core-linux-x86_64 (DEBUG)`. To kompiluje cały system.
Uruchomienie w oknie na pulpicie:
```bash
cd ~/Aros/arosbuilds/core-linux-x86_64-d/bin/linux-x86_64/AROS
./boot/linux/AROSBootstrap
```

**5. Standaryzacja ścieżki `/opt/aros` + wrapper z `--sysroot`:**
```bash
echo 'export PATH="$HOME/Aros/arosbuilds/toolchain-core-x86_64:$PATH"' >> ~/.bashrc
source ~/.bashrc
```
Bez `--sysroot` kompilator podłączy hostowe nagłówki Linuxa zamiast AROS — zawsze
kompiluj z `--sysroot`.

Aby ścieżka była **maszynowo-niezależna** (w duchu `/opt/amiga` dla m68k i
wbudowanego sysroot w toolchainie MorphOS), zmapuj build AROSA na konwencjonalne
**`/opt/aros`** przez skrypt `tools/install-aros-cross.sh` (tworzy symlinki
`/opt/aros/{toolchain,Development}` + generuje wrappery w `/opt/aros/bin`, które
wpisują `--sysroot=` na sztywno):
```sh
sudo /bin/sh /home/<user>/AmigaOS.cpp.wrapper/tools/install-aros-cross.sh \
     /home/<user>/Aros/arosbuilds
echo 'export PATH=/opt/aros/bin:$PATH' >> ~/.bashrc
```
Ręcznie (odpowiednik powyższego):
```sh
sudo ln -sfn ~/Aros/arosbuilds/toolchain-core-x86_64 /opt/aros/toolchain
sudo ln -sfn ~/Aros/arosbuilds/core-linux-x86_64-d/bin/linux-x86_64/AROS/Development /opt/aros/Development
# wrapper w /opt/aros/bin:
#!/bin/sh
exec /opt/aros/toolchain/x86_64-aros-gcc --sysroot=/opt/aros/Development "$@"
```
Dzięki temu `AROS_SYSROOT` w Makefile ma domyślnie `/opt/aros/Development`
(bez żadnej ścieżki użytkownika), a nadpisanie per-build działa tak:
`make cross_aros_x86_64 AROS_SYSROOT=/custom`. Sprawdzenie: `x86_64-aros-gcc --version`.

**6. Test loop:** skopiuj zbudowany binarny do `C:` (katalog AROS) i uruchom z
Shella po nazwie.

> **Do zrobienia przez agenta:** zapoznaj się ze ścieżkami `Development/include`
> (nagłówki AROS) i sprawdź, gdzie w SDK AROS znajdują się nagłówki Zune/MUI oraz
> biblioteka do linkowania (`muimaster.library`). Potwierdź nazwę flagi linkera
> (spodziewane `-lmui`).

> **Znany problem środowiska (zweryfikowano 2026-08):** build `core-linux-x86_64`
> (DEBUG) potrafi paść w `workbench/devs/AHI` — reguła `$(MODEFILE).o` w
> `Drivers/Common/Makefile.common.in` przekazuje gołe `--defsym CPU=x86_64 ...`
> (z `@ASFLAGS@`) do `$(CC)`, a GCC 10.5 odrzuca `--defsym` bez prefiksu `-Wa,`
> (hostowy gcc również). Objaw:
> `x86_64-aros-gcc: error: unrecognized command-line option '--defsym'`.
> Poprawka zastosowana na `~/Aros/arosbuilds` (source `.in` + wygenerowany
> `Makefile.common`):
> ```makefile
> 	$(CC) $(shell echo '$(ASFLAGS)' | sed 's/--defsym /-Wa,--defsym,/g') \
> 	       -c - -o $@
> ```
> (nie używaj `$(subst --defsym ,-Wa,--defsym,,...)` — make rozbija argumenty po
> przecinkach). Po patchu buduj dalej przez `make -jN` w katalogu build.

---

## Etap 2 – Detekcja platformy w kodzie

Wersja MUI jest wykrywana w:
`wrappers/src/MUI/Core/MUICompileConfig.hpp`

Obecna logika: `#ifdef __MORPHOS__` → `MOS_MUI_VERSION_5`,
`#elif defined(MUIMASTER_VLATEST) && MUIMASTER_VLATEST == 19` → `AOS_MUI_VERSION_3_8`,
`#elif ... == 20` → `AOS_MUI_VERSION_5`, `#else #error`.

AROS definiuje `__AROS__` i **nie** dostarcza `MUIMASTER_VLATEST` w sposób
gwarantowany przez własne nagłówki Zune. Do zrobienia:

1. Dodaj nową gałąź w `MUICompileConfig.hpp`:
   ```cpp
   #elif defined(__AROS__)
   // AROS Zune - API kompatybilne z MUI 3.x
   #define AROS_ZUNE_VERSION
   ```
   (z `#pragma message` dla DEBUG, jak w pozostałych gałęziach).

2. **Decyzja projektowa — jak potraktować Zune w istniejących guardach:**
   Zune jest najbliższy **MUI 3.8** (API MUI 3.x). Atrybuty/metody
   specyficzne dla MUI 5.0 (`AOS_MUI_VERSION_5` / `MOS_MUI_VERSION_5`) w Zune
   **nie istnieją**. Zaproponuj i zastosuj spójną strategię, np.:
   - **Zalecane:** w gałęzi `__AROS__` zdefiniuj dodatkowo `AOS_MUI_VERSION_3_8`
     (lub wprowadź wspólną cechę-funkcję), tak aby istniejące guardy
     `#if defined(AOS_MUI_VERSION_3_8) || ...` działały bez masowych zmian w
     pozostałych plikach; guardy na `*_MUI_VERSION_5` automatycznie wyłączą
     funkcje niedostępne w Zune.
   - Alternatywnie: przeaudytuj każdy z 19 plików używających makr wersji i
     dopisz `AROS_ZUNE_VERSION` tam, gdzie Zune faktycznie wspiera daną cechę.
   W obu przypadkach **zweryfikuj na realnej kompilacji**, że wybrana strategia
   kompiluje się dla AROS.

3. **Audyt plików z guardami wersji** (znajdź wszystkie `#if defined(AOS_MUI_VERSION_5)`,
   `MOS_MUI_VERSION_5`, `AOS_MUI_VERSION_3_8`) i opisz w podsumowaniu, które
   elementy są dostępne/nieobecne w Zune.

### Wynik Etapu 2 (zweryfikowano 2026-08)

Wybrano podejście **zalecane**: gałąź `__AROS__` definiuje `AROS_ZUNE_VERSION`
**oraz** `AOS_MUI_VERSION_3_8`. Skutek:

- Gwardy `AOS_MUI_VERSION_3_8` aktywne dla Zune → **dostępne**:
  `RGBColor.hpp:31`, `RGBColor.cpp:38`, `Pendisplay.cpp:27`, `Pendisplay.cpp:62`
  (ścieżki używające `struct MUI_RGBcolor { ULONG red, green, blue; }` — typ
  zdefiniowany identycznie w SDK AROS, potwierdzone w `Development/include/libraries/mui.h`).
  Uwaga: `MUI_RGBColor` (duże `C`) w Zune **nie istnieje** — dlatego Zune nie
  może iść ścieżką `#else`.
- Gwardy `*_MUI_VERSION_5` dla Zune **nieaktywne** → cechy wyłączone (bezpieczne,
  Zune to API MUI 3.x). Niewystawione przez wrapper dla AROS m.in.:
  atrybuty MUI5 w `Image`, `Window`, `List`, `Cycle`, `Text`, `Register`,
  `MUIA_Dirlist_AcceptPattern` (warunek `AOS_MUI_VERSION_5 && MUIA_Dirlist_AcceptPattern`),
  oraz własna definicja `struct MUI_RGBcolor` w `RGBColor.hpp:11` (zarezerwowana
  dla `AOS_MUI_VERSION_5` — w Zune dostarcza ją SDK).
- **Brak** wersjonowanych `#include` w całym `wrappers/src` (audyt: zero trafień),
  więc mapowanie nie wciąga nagłówków specyficznych dla AmigaOS.
- Kompilator AROS definiuje `__AROS__` (potwierdzone `-dM`), hostowy gcc nie —
  gałęzie AmigaOS/MorphOS bez zmian (regresja do zweryfikowania w Etapie 6).

---

## Etap 3 – Includes i makra platformowe

1. Kod używa `#include <proto/muimaster.h>` oraz `"mui.hpp"`
   (`mui.hpp` pochodzi z `AmigaOS.cpp.wrapper`, ścieżka `-I${AOSCPP_PATH}/wrappers/src`).
   Sprawdź, czy w SDK AROS te ścieżki/nagłówki istnieją (AROS historycznie używa
   ścieżek typu `zune/muimaster.h` w `Development/include`). Jeśli się różnią —
   dodaj mapowanie include'ów (np. warunkowe `#include`) tak, aby nie psuć
   pozostałych platform. Zweryfikuj też dostępność `MUIMASTER_NAME` / `MUIMASTER_VMIN`.

2. **`wrappers/src/SDI/platform_macros.hpp`** — obecnie rozróżnia tylko
   `__MORPHOS__` vs reszta. Gałąź `#else` używa makr dyspozytora w stylu 68k
   (`ASM`/`SAVEDS`), które są **niepoprawne dla AROS x86_64**. Dodaj obsługę
   `__AROS__` (AROS ma własną konwencję dyspozytora — patrz gotowe makra w
   `wrappers/src/SDI/SDI_hook.h`, które już zawierają gałąź `#elif defined(__AROS__)`
   z makrami `AROS_UFH3`, `AROS_UFPA` itd.).

3. Sprawdź `wrappers/src/SDI/SDI_compiler.h` — ma już obsługę AROS
   (`__AROS__`), potwierdź że dla `x86_64` nic nie wymaga poprawek.

---

## Etap 4 – Makefile: nowy target `cross_aros_x86_64`

Dodaj target zgodny z istniejącą konwencją (nazwy zmiennych, struktura).

**Główny `Makefile`:**
```makefile
cross_aros_x86_64: sub_projects_cross_aros_x86_64

sub_projects_cross_aros_x86_64: BUILD_TARGET=cross_aros_x86_64
sub_projects_cross_aros_x86_64: sub_projects_build
```
+ wpis w helpie (`all:`).

**`wrappers/Makefile`:** (wzoruj się na `cross_morphos_ppc` / `cross_amigaos_m68k`)
```makefile
cross_aros_x86_64: TARGET="Cross AROS x86_64"
cross_aros_x86_64: SUB_BUILD_PATH=aros/x86_64
cross_aros_x86_64: CPPC=x86_64-aros-g++
cross_aros_x86_64: AR=x86_64-aros-ar
cross_aros_x86_64: MORE_CPP_FLAGS="-DAROS_ZUNE"
cross_aros_x86_64: LIB_MUICPP_NAME=libMUIcpp_zune.a
cross_aros_x86_64: build
```
+ dodaj `cross_aros_x86_64` do `.PHONY` i helpu.

**`examples/Makefile`:** analogiczny target z `STRIP=x86_64-aros-strip`,
`OBJDUMP=x86_64-aros-objdump` oraz `MORE_LFLAGS` (spodziewane
`-lMUIcpp_zune -lstdc++ -lmui ...`) — **zweryfikuj faktyczną nazwę biblioteki
Zune w SDK AROS**.

**`tests/Makefile`:** dodaj `cross_aros_x86_64` z wpisem `TODO tests` (jak reszta).

**Struktura build:** dodaj katalogi w strukturze (obok `amigaos/m68k`, `morphos/ppc`):
```
obj -> aros  -> x86_64 -> *.o
lib -> aros  -> x86_64 -> libMUIcpp_zune.a
```

**Uwagi techniczne:**
- Wrapper musi linkować się z `x86_64-aros-g++` — `makefile.generic.gcc.mk` dla
  `wrappers` nie wymaga zmian poza parametrami (sprawdź, czy `-flto` działa z
  `x86_64-aros-g++`; jeśli nie — zostaw bez `-flto` dla AROS).
- `examples/makefile.generic.gcc.mk` linkuje `-lamiga_std_light`
  (`AmigaOS.cpp.wrapper`) — potwierdź, że ta biblioteka buduje się również dla
  AROS lub warunkowo ją pomiń.

---

## Etap 5 – Dokumentacja (README.md)

Dodaj sekcję **"Linux cross compilation for AROS"** (wzorowaną na istniejącej
sekcji dla MorphOS), zawierającą:
- linki: repozytorium `deadwood2/AROS`, `scripts/rebuild.sh`,
- polecenia instalacji zależności (Etap 1),
- kroki budowy toolchaina i hosted AROS,
- komendę budowy: `make cross_aros_x86_64`,
- notkę, że AROS używa Zune (MUI 3.x-kompatybilny) i że detekcja opiera się na `__AROS__`.

Zaktualizuj też listę "Requirements for build" o wymagania dla AROS.

---

## Etap 6 – Weryfikacja

1. `make cross_aros_x86_64` — biblioteka + przykłady budują się bez błędów dla AROS.
2. **Regresja:** `make cross_aos_m68k` i `make cross_mos_ppc` dalej budują się
   (bez zmian w tych ścieżkach).
3. Uruchom w hosted AROS: skopiuj `examples/out/aros/x86_64/basic.example.bin`
   do `C:` i sprawdź, że okno się otwiera.
4. Jeśli to możliwe, uruchom przykładowe elementy korzystające z dyspozytora
   (custom classes) — potwierdź, że makra dla `__AROS__` działają poprawnie.

### Wynik Etapu 6 (zweryfikowano 2026-08-18, hosted AROS x86_64)

Wszystkie trzy programy przykładowe uruchamiają się w hosted AROS:

- `stream.tests.bin` — działa (test strumieni siblinga).
- `basic.example.bin` — okno otwiera się poprawnie.
- `advanced.example.bin` — okno otwiera się poprawnie; **nie wszystkie opcje
  przykładu działają w Zune**, ale to kwestia przebudowy przykładu — poza
  zakresem tego zadania.

**Pułapki wykryte podczas weryfikacji runtime:**

- **Na AROS kopiuj do `C:` wersję `*_nonstripped`, nie stripped.**
  `examples/Makefile` produkuje obie: `advanced.example.bin_nonstripped`
  (2.2 MB, `file`: "with debug_info, not stripped") i stripped
  `advanced.example.bin` (548 KB, `file`: "stripped"). AROS-owy ELF jest
  relocatable — stripped binarka crashuje natychmiast (trap z `RIP=0` /
  "call through NULL"). Z `_nonstripped` działa.
- **`tagTitle(true)` = crash w Zune.** `MUIA_NList_Title` to w dokumentacji
  NList `char *` (MCC_NList.doc) — wartość BOOL/LONG jest dozwolona **tylko
  gdy używany jest display hook**. W `examples/advanced/.../CustomClassesTab.cpp`
  `.tagTitle(true)` (w połączeniu z `tagConstructHookString()`, bez display
  hooka) przekazywało `MUIA_NList_Title = 1` → Zune traktował to jako
  wskaźnik tytułu → `NL_GetDisplayArray` (`useptr = (char *)data->NList_Title`)
  → dereferencja adresu 1 w `ParseColumn` (NList_mcc4.c) → SIGSEGV.
  Kod Zune i oryginalnego `amiga-mui/nlist` jest w tym miejscu identyczny —
  to nie bug Zune. Poprawka: tytuł jako string z kolumnami tabulatorem
  (`.tagTitle("Nazwa\tSystem\tKlasa")`) lub wyłączenie tytułu.
- **Config w `ENVARC:Zune/`**: AROS zapisuje config programu
  (`ENVARC:Zune/advanced.example.bin.1.cfg`, prawie pusty FORM) — nie jest
  przyczyną crashów, można go usunąć między testami.

---

## Etap 7 – Wnioski z portowania (learning notes, zweryfikowano 2026-08)

Ustalenia z praktycznej kompilacji wrapperów (MUI + sibling `AmigaOS.cpp.wrapper`)
dla AROS x86_64. **Czytaj przed dalszymi zmianami AROS** — unikniesz regresji
na m68k/MorphOS.

### 1. `IPTR` NIE istnieje w SDK AmigaOS m68k
- Brak go w `ndk-include/exec/types.h` i całym NDK 68k. Jest na MorphOS
  (`typedef unsigned long IPTR`) i AROS (64-bit `AROS_INTPTR_TYPE`).
- Fallback `#define IPTR ULONG` istnieje tylko w `wrappers/src/SDI/SDI_compiler.h:240`
  (gałąź `!__AROS__ && !__MORPHOS__ && !IPTR`), ale **nie każdy TU go includuje**,
  a sibling (`AmigaOS.cpp.wrapper`) **nie ma SDI w ogóle**.
- **Zasada:** we wspólnym kodzie (MUI + sibling) **nie używaj gołego `IPTR`**:
  - przekazuj wskaźniki przez varargs/`DoMethod` **wprost (bez rzutowania)** —
    pola `MUIP_*` w mui.h są typowane wskaźnikowo (`Object *obj`, `APTR entry`,
    `APTR *entries`, `CONST_STRPTR Text`), a AROS-owy `DoMethod` i tak
    normalizuje argumenty przez `AROS_PP_VARIADIC_CAST2IPTR` → `(IPTR)(...)`.
    Surowy wskaźnik kompiluje się na wszystkich targetach (m68k/MorphOS/AROS)
    bez rzutowań. Zastosowano w: `MUI/{List,Group,Family,Floattext}.cpp`.
  - wartości intowe (np. `MUIM_List_Jump` `LONG pos`, `MUIM_TextEditor_InsertText`)
    — `(long)`/`(ULONG)` wg pola; to nie są wskaźniki.
  - `GetAttr`: patrz pkt 7 (`AOS_GETATTR_STORAGE`).
  - sibling `AOS/ValueObject.{hpp,cpp}`: alias `AOS::TagData` —
    `IPTR` tylko pod `#ifdef __AROS__`, poza `ULONG` (wartość trafia do `tag.ti_Data`).

### 2. Enumy z wartościami `MUIV_*` — nie używaj `: IPTR`
`MUIV_Font_*` są typowane różnie:
- AmigaOS/MorphOS: zwykłe `-1`, `-2`, … (signed int)
- AROS Zune: `((IPTR)-1)` → 64-bit unsigned `0xFF..FF`
Sprzeczność: unsigned `IPTR` nie trzyma gołego `-1`, a signed `long` nie trzyma
surowego `0xFF..FF`. **Rozwiązanie (wzorzec do powtórzenia):**
```cpp
enum class Font // domyślna baza int
{
    Normal = static_cast<int>(MUIV_Font_Normal), // normalizuje AROS 0xFF..FF -> -1
    ...
};
```

### 3. `std::optional` (sibling `wrappers/src/std/optional.hpp`)
- Fallbackowy `std::optional` był redefiniowany pod prawdziwym `<optional>` przy
  `-std=gnu++17`. Guard: `#if defined(__MORPHOS__) || __cplusplus >= 201703L`
  → `#include <optional>`, poza → własna implementacja.
- **AROS buduj z `-std=gnu++17`** (nie C++14).

### 4. Biblioteki PCI nie istnieją w AROS
`PCIX`, `Picasso96`, `Identify` (zależy od `openpci`), `PCIIDS` — brak nagłówków
w SDK AROS. W nagłówkach `*BaseScope.hpp` i `Library.hpp` dodano:
```cpp
#ifdef __AROS__
#error "AOS::<Xxx> wrapper is not available on AROS - <lib> does not exist on AROS"
#endif
```
(po `#pragma once`, przed includami → jasny komunikat zamiast krypticznego
"No such file"). Katalogi leżą w podkatalogach `src/AOS/*/` — makefile zbierają
tylko `src/AOS/*.cpp` (wierzch), więc te moduły nie wchodzą do zwykłego builda.

### 5. Kolizje nazw z makrami/globalami AROS
- Makra w `proto/dos.h` (np. 3-argumentowe `NameFromLock`, `Write`) "zjadały"
  metody klas o tej samej nazwie → `#undef NameFromLock` / `#undef Write` po include.
- AROS `proto/{expansion,rexxsyslib}.h` deklarują własne globals `ExpansionBase`
  / `RexxSysBase` → sibling zmienił swoje globals na `static sExpansionBase`
  / `static sRxsSysBase` (i dodał `#include <rexx/rxslib.h>` dla `RXSNAME`).
- Brak `MA_EngineClock` w AROS → `#ifdef MA_EngineClock` wokół `GetAttr`.
- **`DoMethod` w AROS to makro variadic** (`clib/alib_protos.h`), używające
  `AROS_PP_VARIADIC_CAST2IPTR` → `(IPTR)(arg)` per argument. Nie rozwija pack-ów
  szablonowych (`args...`), więc szablony `MUI::Notify`/`Application::PushMethod`
  wołają funkcję przez `(DoMethod)(...)` (paren-theza pomija ekspansję makra).
  Realna funkcja `IPTR DoMethod(Object*, STACKULONG, ...)` (`clib/alib_protos.h`)
  czyta varargs jako `IPTR`. Wymaga widocznej deklaracji funkcji w punkcie
  definicji szablonu (brak ADL) → `#include <proto/alib.h>` PRZED szablonami.
  `CallHook` to w AROS też makro → `#undef CallHook` pod `#ifdef __AROS__`.
  Na m68k/MorphOS `DoMethod` to zwykła funkcja — paren-theza jest bezpieczna.

### 6. `--sysroot` jest obowiązkowy dla `x86_64-aros-g++`
Bez `--sysroot` kompilator podpina hostowe nagłówki Linuxa. W sibling
`wrappers/Makefile` target (`AROS_SYSROOT` domyślnie `/opt/aros/Development` —
konwencja maszynowo-niezależna, patrz Etap 1 krok 5):
```makefile
AROS_SYSROOT ?= /opt/aros/Development
cross_aros_x86_64: MORE_CPP_FLAGS="-std=gnu++17 --sysroot=$(AROS_SYSROOT)"
```
Nadpisanie: `make cross_aros_x86_64 AROS_SYSROOT=/custom`.

### 7. Uwagi do API AROS SDK
- Zune header: `Development/include/libraries/mui.h` (klasy jak `MUIC_Gadget`
  NIE istnieją — guardy `#ifdef MUIA_Gadget_*` / fallback `#define MUIC_Gadget`).
- AROS ma variadic `NewRawDoFmt` + `RAWFMTFUNC_STRING` (`exec/rawfmt.h`) —
  nie używaj `RawDoFmt`/`RAWARG` (przy 64-bit wymaga wrappera `RAWARG_s`).
- `GetAttr(...)` storage jest pointer-sized. NIE używaj gołego `(long *)` —
  na AROS `ULONG` to 32 bity (storage jest `IPTR*`), na m68k/MorphOS `ULONG*`.
  Sibling: makro `AOS_GETATTR_STORAGE` (`__AROS__`→`IPTR`, poza→`ULONG`) + cast
  `(AOS_GETATTR_STORAGE *)&pXxx` (dos/Intuition).
- `RXSNAME` jest w `rexx/rxslib.h`, nie w `proto/rexxsyslib.h`.

### 7b. AROS nagłówki używają gołego `UBYTE*` zamiast `CONST_STRPTR`
- W C++ `CONST_STRPTR` = `const char*` na WSZYSTKICH platformach (AROS przez
  `__AROS_CPP_BYTE`). ALE AROS deklaruje `FindResident`, `CreateArgstring`,
  `CreateRexxMsg`, `DeleteArgstring` jako `const UBYTE*`/`UBYTE*` — twardo, nie
  przez `CONST_STRPTR` (nie inline-vs-clib, obie wersje tak mają).
- Więc przekazując `std::string::c_str()` na AROS potrzebny cast `(const UBYTE *)`,
  na m68k/MorphOS nie. **Zasada:** casty `(UBYTE*)`-klasy zamykaj w
  `#ifdef __AROS__` (a `DeleteArgstring` — w `#ifdef __MORPHOS__`, bo m68k/AOS też
  chcą `UBYTE*`); reszta platform dostaje `c_str()` bez castu. To samo dla
  `FindToolType` (`__MORPHOS__||__AROS__`→`(char*const*)`, m68k→`(CONST_STRPTR*)`).

### 8. Stan weryfikacji (stan na 2026-08, zmiany niezacommitowane)
- MUI wrapper: AROS sweep 106 plików `.cpp` czysto; target `cross_aros_x86_64`
  (w `wrappers/Makefile`, `LIB_MUICPP_NAME=libMUIcpp.a`, z `AROS_SYSROOT`) —
  exit 0; **m68k** (`cross_amigaos_m68k`, MUI38+MUI5) exit 0 (177 jednostek);
  **MorphOS** (`cross_morphos_ppc`) exit 0.
- **Top-level `Makefile`** (repo root): `cross_aros_x86_64` buduje pełny łańcuch
  wrappers + tests + examples (basic i advanced) — exit 0 na m68k/MorphOS/AROS
  (`cross_aos_m68k`, `cross_mos_ppc`, `cross_aros_x86_64`).
- AROS-specific fixes: `DoMethod`/`CallHook` w `Notify.hpp` (patrz pkt 5);
  `examples/advanced` — guardy `#ifdef MUIA_Title_Closable/Newable` (Zune nie ma
  `MUIA_Title_*`) i `#ifdef MUIA_List_MaxColumns`.
- Sibling `amiga_std_light`: targety `cross_amigaos_m68k`, `cross_morphos_ppc`,
  `cross_aros_x86_64` — exit 0 (także z top-level `Makefile` siblinga, któremu
  dodano `cross_aros_x86_64` + help; `tests/Makefile`: AROS target z
  `--no-gc-sections` — Zune/AROS ld wymaga entry/undefined symbol przy
  `--gc-sections`; `iostream.{hpp,cpp}`: na 64-bit `long` aliassuje
  `int64_t`/`uint64_t`, ale `long long` jest typem odrębnym → guard
  `#if ULONG_MAX == UINT64_MAX` dodaje overloady `long long`/`unsigned long long`).
- Konsumenci siblinga (pliki w podkatalogach `src/AOS/*/`): `Exec/Library.cpp`,
  `Rexxsyslib/*`, `Intuition/Library.cpp`, `Icon/DiskObjectScope.cpp`,
  `Dos/{Library,LockScope,FileHandleScope}.cpp`, `DataTypes/Library.cpp`,
  `Expansion/ExpansionBaseScope.cpp` — 0 błędów na m68k/MorphOS/AROS po guardach
  platformowych (m68k `Intuition/Library.cpp`=1: brak `intuition/monitorclass.h`
  w NDK 68k — dotyczy tylko MorphOS/AROS).
- Pre-existing błędy poza portem (identyczne na HEAD): ASL/* (kolizja makra
  `AslRequest`), PCIX/*/Picasso96 (brak SDK) — NIE dotknięte.

---

## Zasady pracy

- **Działaj autonomicznie** — nie pytaj o pozwolenie przed każdą zmianą.
- **Nie psuj istniejących targetów** — zmiany platformowe zamykaj w `#ifdef __AROS__`
  lub nowych targetach Makefile.
- **Komentuj zmiany** — dodawaj krótki komentarz `// AROS ZUNE: powód` przy istotnych zmianach.
- **Nie zmieniaj logiki** istniejących platform — tylko dodajesz nowe ścieżki.
- Jeśli nie masz dostępu do pełnego SDK AROS — opisz w podsumowaniu, co było
  niemożliwe do zweryfikowania (np. nazwa biblioteki linkera) i czego dokładnie
  potrzebujesz.
- Docelowy toolchain: **`x86_64-aros-g++` / hosted AROS x86_64**.
