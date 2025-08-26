#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2024 TDolphin
#

all:
	@echo "# Available actions:"
	@echo "make cross_amigaos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make morphos_ppc - MorphOS PowerPC build"
	@echo "make cross_morphos_ppc - MorphOS PowerPC build (cross compilation on linux)"
	@echo "make clean - remove all obj files"

cross_amigaos_m68k:
	@echo "# Build for AmigaOS m68k"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=amigaos/m68k \
	CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump \
	MORE_CPP_FLAGS=-DSTD_LIGHT MORE_LFLAGS=-lMUIcpp.light all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=amigaos/m68k \
	CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump \
	MORE_CPP_FLAGS=-DSTD_LIGHT MORE_LFLAGS=-lMUIcpp.light all
	cp advanced/img/* out/amigaos/m68k

morphos_ppc:
	@echo "# Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip OBJDUMP=objdump \
	MORE_CPP_FLAGS=-noixemul MORE_LFLAGS=-lMUIcpp all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip OBJDUMP=objdump \
	MORE_CPP_FLAGS=-noixemul MORE_LFLAGS=-lMUIcpp all
	cp advanced/img/* out/morphos/ppc

cross_morphos_ppc:
	@echo "# Cross Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc \
	CPPC=ppc-morphos-g++ AR=ppc-morphos-ar STRIP=ppc-morphos-strip OBJDUMP=ppc-morphos-objdump \
	MORE_CPP_FLAGS=-noixemul MORE_LFLAGS=-lMUIcpp all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc \
	CPPC=ppc-morphos-g++ AR=ppc-morphos-ar STRIP=ppc-morphos-strip OBJDUMP=ppc-morphos-objdump \
	MORE_CPP_FLAGS=-noixemul MORE_LFLAGS=-lMUIcpp all
	cp advanced/img/* out/morphos/ppc

clean:
	rm -f -R obj/*
