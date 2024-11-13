#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  (c) 2022-2024 TDolphin
#

all:
	@echo "make amigaos_m68k <--- cross compilation on linux"
	@echo "make morphos_ppc <--- build on MorphOS"
	@echo "make clean <--- remove all .o files"

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

clean:
	rm -f -R obj/*
	rm -f -R lib/*
