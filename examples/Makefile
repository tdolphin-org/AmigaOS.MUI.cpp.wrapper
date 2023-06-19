#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2023 TDolphin
#

amigaos_m68k:
	@echo "# Build for AmigaOS m68k"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin MODULES=basic \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin MODULES=advanced \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar STRIP=m68k-amigaos-strip all

morphos_ppc:
	@echo "# Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=basic.example.bin MODULES=basic \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul all
	$(MAKE) -f makefile.generic.gcc.mk APP_EXAMPLE=advanced.example.bin MODULES=advanced \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar STRIP=strip MORE_CPP_FLAGS=-noixemul all

clean:
	rm -f -R obj/*
