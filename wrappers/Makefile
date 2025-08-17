#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  (c) 2022-2025 TDolphin
#

all:
	@echo "make amigaos_m68k - cross compilation on linux"
	@echo "make morphos_ppc - build on MorphOS"
	@echo "make cross_morphos_ppc - cross compilation on linux"
	@echo "make clean - remove all .o and .lib files"

amigaos_m68k:
	@echo "# Build for AmigaOS m68k"
	$(MAKE) -f makefile.generic.gcc.mk \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=amigaos/m68k CPPC=m68k-amigaos-g++ AR=m68k-amigaos-ar all

morphos_ppc:
	@echo "# Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc CPPC=g++ AR=ar MORE_CPP_FLAGS=-noixemul all

cross_morphos_ppc:
	@echo "# Cross Build for MorphOS PowerPC"
	$(MAKE) -f makefile.generic.gcc.mk \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=morphos/ppc CPPC=ppc-morphos-g++ AR=ppc-morphos-ar MORE_CPP_FLAGS=-noixemul all

clean.obj:
	rm -f -R ../../AmigaOS.cpp.wrapper/wrappers/obj/*
	rm -f -R obj/*

clean: clean.obj
	rm -f -R obj/*
	rm -f -R lib/*
