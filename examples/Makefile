#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2024 TDolphin
#

amigaos_m68k:
	@echo "# Build for AmigaOS m68k"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip all
	cp advanced/img/* out/amigaos/m68k

morphos_ppc:
	@echo "# Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin PROJECT=basic MODULES= \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin PROJECT=advanced MODULES=Components,Components/Core,Components/Tabs \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul all
	cp advanced/img/* out/morphos/ppc

clean:
	rm -f -R obj/*
