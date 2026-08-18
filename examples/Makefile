#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2026 TDolphin
#

all:
	@echo "# Available actions:"
	@echo "make cross_amigaos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make morphos_ppc - MorphOS PowerPC build"
	@echo "make cross_morphos_ppc - MorphOS PowerPC build (cross compilation on linux)"
	@echo "make cross_aros_x86_64 - AROS x86_64 build (cross compilation on linux)"
	@echo "make clean - remove all obj files"

cross_amigaos_m68k: TARGET="Cross AmigaOS m68k"
cross_amigaos_m68k: SUB_BUILD_PATH=amigaos/m68k
cross_amigaos_m68k: CPPC=m68k-amigaos-g++
cross_amigaos_m68k: AR=m68k-amigaos-ar
cross_amigaos_m68k: STRIP=m68k-amigaos-strip
cross_amigaos_m68k: OBJDUMP=m68k-amigaos-objdump
cross_amigaos_m68k: MORE_CPP_FLAGS="-DAOS_MUI5 -flto"
cross_amigaos_m68k: MORE_LFLAGS="-lMUIcpp5 -lstdc++ -lmui -flto"
cross_amigaos_m68k: build

morphos_ppc: TARGET="MorphOS PPC"
morphos_ppc: SUB_BUILD_PATH=morphos/ppc
morphos_ppc: CPPC=g++
morphos_ppc: AR=ar
morphos_ppc: STRIP=strip
morphos_ppc: OBJDUMP=objdump
morphos_ppc: MORE_CPP_FLAGS="-noixemul -flto"
morphos_ppc: MORE_LFLAGS="-lMUIcpp -lauto -noixemul -flto"
morphos_ppc: build

cross_morphos_ppc: TARGET="Cross MorphOS PPC"
cross_morphos_ppc: SUB_BUILD_PATH=morphos/ppc
cross_morphos_ppc: CPPC=ppc-morphos-g++
cross_morphos_ppc: AR=ppc-morphos-ar
cross_morphos_ppc: STRIP=ppc-morphos-strip
cross_morphos_ppc: OBJDUMP=ppc-morphos-objdump
cross_morphos_ppc: MORE_CPP_FLAGS="-noixemul -flto"
cross_morphos_ppc: MORE_LFLAGS="-lMUIcpp -lauto -noixemul -flto"
cross_morphos_ppc: build

# AROS "Development" tree (sysroot with Zune headers/libs). Machine-independent
# path: on machines that follow the convention it is /opt/aros/Development.
# Override per-build with:
#   make cross_aros_x86_64 AROS_SYSROOT=/custom/path
AROS_SYSROOT ?= /opt/aros/Development

cross_aros_x86_64: TARGET="Cross AROS x86_64"
cross_aros_x86_64: SUB_BUILD_PATH=aros/x86_64
cross_aros_x86_64: CPPC=x86_64-aros-g++
cross_aros_x86_64: AR=x86_64-aros-ar
cross_aros_x86_64: STRIP=x86_64-aros-strip
cross_aros_x86_64: OBJDUMP=x86_64-aros-objdump
cross_aros_x86_64: MORE_CPP_FLAGS="-std=gnu++17 --sysroot=$(AROS_SYSROOT)"
cross_aros_x86_64: MORE_LFLAGS="-lMUIcpp -lstdc++ -lmui --sysroot=$(AROS_SYSROOT)"
cross_aros_x86_64: build

build:
	@echo "# Build ... $(TARGET) ... $(SUB_BUILD_PATH)"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) \
	CPPC=$(CPPC) AR=$(AR) STRIP=$(STRIP) OBJDUMP=$(OBJDUMP) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) MORE_LFLAGS=$(MORE_LFLAGS) all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs,Components/MCC,Components/Menus \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) \
	CPPC=$(CPPC) AR=$(AR) STRIP=$(STRIP) OBJDUMP=$(OBJDUMP) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) MORE_LFLAGS=$(MORE_LFLAGS) all
	mkdir -p out/$(SUB_BUILD_PATH)
	cp advanced/img/* out/$(SUB_BUILD_PATH)

clean.obj:
	rm -f -R obj/*

clean: clean.obj
	rm -f -R out/*
