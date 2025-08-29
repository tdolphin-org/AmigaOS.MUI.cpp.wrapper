#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2025 TDolphin
#

all:
	@echo "# Available actions:"
	@echo "make cross_amigaos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make morphos_ppc - MorphOS PowerPC build"
	@echo "make cross_morphos_ppc - MorphOS PowerPC build (cross compilation on linux)"
	@echo "make clean - remove all obj files"

cross_amigaos_m68k: TARGET="Cross AmigaOS m68k"
cross_amigaos_m68k: SUB_BUILD_PATH=amigaos/m68k
cross_amigaos_m68k: CPPC=m68k-amigaos-g++
cross_amigaos_m68k: AR=m68k-amigaos-ar
cross_amigaos_m68k: STRIP=m68k-amigaos-strip
cross_amigaos_m68k: OBJDUMP=m68k-amigaos-objdump
cross_amigaos_m68k: MORE_CPP_FLAGS="-DSTD_LIGHT -fno-rtti -ffunction-sections -fdata-sections"
cross_amigaos_m68k: MORE_LFLAGS="-lMUIcpp.light -Wl,--gc-sections"
cross_amigaos_m68k: build

morphos_ppc: TARGET="MorphOS PPC"
morphos_ppc: SUB_BUILD_PATH=morphos/ppc
morphos_ppc: CPPC=g++
morphos_ppc: AR=ar
morphos_ppc: STRIP=strip
morphos_ppc: OBJDUMP=objdump
morphos_ppc: MORE_CPP_FLAGS="-noixemul"
morphos_ppc: MORE_LFLAGS="-lMUIcpp"
morphos_ppc: build

cross_morphos_ppc: TARGET="Cross MorphOS PPC"
cross_morphos_ppc: SUB_BUILD_PATH=morphos/ppc
cross_morphos_ppc: CPPC=ppc-morphos-g++
cross_morphos_ppc: AR=ppc-morphos-ar
cross_morphos_ppc: STRIP=ppc-morphos-strip
cross_morphos_ppc: OBJDUMP=ppc-morphos-objdump
cross_morphos_ppc: MORE_CPP_FLAGS="-noixemul"
cross_morphos_ppc: MORE_LFLAGS="-lMUIcpp"
cross_morphos_ppc: build

build:
	@echo "# Build ... $(TARGET) ... $(SUB_BUILD_PATH)"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) \
	CPPC=$(CPPC) AR=$(AR) STRIP=$(STRIP) OBJDUMP=$(OBJDUMP) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) MORE_LFLAGS=$(MORE_LFLAGS) all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) \
	CPPC=$(CPPC) AR=$(AR) STRIP=$(STRIP) OBJDUMP=$(OBJDUMP) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) MORE_LFLAGS=$(MORE_LFLAGS) all
	cp advanced/img/* out/morphos/ppc

clean:
	rm -f -R obj/*
