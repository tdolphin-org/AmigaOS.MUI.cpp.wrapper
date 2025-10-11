#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  (c) 2022-2025 TDolphin
#

all:
	@echo "make cross_amigaos_m68k - cross compilation on linux"
	@echo "make morphos_ppc - build on MorphOS"
	@echo "make cross_morphos_ppc - cross compilation on linux"
	@echo "make clean - remove all .o and .lib files"

cross_amigaos_m68k: TARGET="Cross AmigaOS m68k"
cross_amigaos_m68k: SUB_BUILD_PATH=amigaos/m68k
cross_amigaos_m68k: CPPC=m68k-amigaos-g++
cross_amigaos_m68k: AR=m68k-amigaos-ar
cross_amigaos_m68k: MORE_CPP_FLAGS="-fno-rtti -ffunction-sections -fdata-sections"
cross_amigaos_m68k: build

morphos_ppc: TARGET="MorphOS PPC"
morphos_ppc: SUB_BUILD_PATH=morphos/ppc
morphos_ppc: CPPC=g++
morphos_ppc: AR=ar
morphos_ppc: MORE_CPP_FLAGS="-noixemul -fno-threadsafe-statics -D_GLIBCXX_HAS_GTHREADS=0"
morphos_ppc: build

cross_morphos_ppc: TARGET="Cross MorphOS PPC"
cross_morphos_ppc: SUB_BUILD_PATH=morphos/ppc
cross_morphos_ppc: CPPC=ppc-morphos-g++
cross_morphos_ppc: AR=ppc-morphos-ar
cross_morphos_ppc: MORE_CPP_FLAGS="-noixemul"
cross_morphos_ppc: build

build:
	@echo "# Build ... $(TARGET) ... $(SUB_BUILD_PATH)"
	$(MAKE) -f makefile.generic.gcc.mk \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) CPPC=$(CPPC) AR=$(AR) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) \
	all

clean.obj:
	rm -f -R ../../AmigaOS.cpp.wrapper/wrappers/obj/*
	rm -f -R obj/*

clean: clean.obj
	rm -f -R obj/*
	rm -f -R lib/*
