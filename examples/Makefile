#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2024 TDolphin
#

all:
	@echo "# to build Examples"
	@echo "make amigaos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make morphoss_ppc - MorphOS PowerPC build"
	@echo "make clean - remove all obj files"

amigaos_m68k:
	@echo "# Build for AmigaOS m68k"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip OBJDUMP=m68k-amigaos-objdump all
	cp advanced/img/* out/amigaos/m68k

morphos_ppc:
	@echo "# Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul OBJDUMP=objdump all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul OBJDUMP=objdump all
	cp advanced/img/* out/morphos/ppc

clean:
	rm -f -R obj/*
