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

**5. PATH + wrapper z `--sysroot`:**
```bash
echo 'export PATH="$HOME/Aros/arosbuilds/toolchain-core-x86_64:$PATH"' >> ~/.bashrc
source ~/.bashrc
```
Bez `--sysroot` kompilator podłączy hostowe nagłówki Linuxa zamiast AROS — zawsze
kompiluj z `--sysroot`. Najwygodniej przez skrypt-wrappper:
```sh
#!/bin/sh
exec /home/<user>/Aros/arosbuilds/toolchain-core-x86_64/x86_64-aros-gcc \
     --sysroot=/home/<user>/Aros/arosbuilds/core-linux-x86_64-d/bin/linux-x86_64/AROS/Development "$@"
```
Sprawdzenie: `x86_64-aros-gcc --version`.

**6. Test loop:** skopiuj zbudowany binarny do `C:` (katalog AROS) i uruchom z
Shella po nazwie.

> **Do zrobienia przez agenta:** zapoznaj się ze ścieżkami `Development/include`
> (nagłówki AROS) i sprawdź, gdzie w SDK AROS znajdują się nagłówki Zune/MUI oraz
> biblioteka do linkowania (`muimaster.library`). Potwierdź nazwę flagi linkera
> (spodziewane `-lmui`).

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
