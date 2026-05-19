#
#  MakeFile for AmigaOS MUI C++ wrapper
#
#  (c) 2022-2026 TDolphin
#

.PHONY: all build clean clean.obj cross_amigaos_m68k_MUI38 cross_amigaos_m68k_MUI5 cross_amigaos_m68k morphos_ppc cross_morphos_ppc

all:
	@echo "make cross_amigaos_m68k - cross compilation on linux"
	@echo "make morphos_ppc - build on MorphOS"
	@echo "make cross_morphos_ppc - cross compilation on linux"
	@echo "make clean - remove all .o and .lib files"

# Why these flags for static library (.a) build:
# -ffunction-sections / -fdata-sections:
#   put each function/object into a separate ELF section so the final executable
#   can discard unused code/data from this library (with linker --gc-sections).
#   This reduces binary size when app uses only a subset of wrappers.
# -fvisibility=hidden / -fvisibility-inlines-hidden:
#   hide symbols by default to limit exported API surface and avoid accidental
#   symbol collisions when many static libs are linked together.
# -fno-rtti and (on MorphOS) -fno-threadsafe-statics:
#   cut C++ runtime overhead and dependencies, which is desirable in this low-
#   level cross-target environment.
#   (-fno-rtti -> code doesn't contains dynamic_cast/typeid)
# -noixemul (MorphOS):
#   build against native ABI/runtime (without ixemul emulation layer).

cross_amigaos_m68k:
	$(MAKE) cross_amigaos_m68k_MUI38
	$(MAKE) cross_amigaos_m68k_MUI5

cross_amigaos_m68k_MUI38: TARGET="Cross AmigaOS m68k"
cross_amigaos_m68k_MUI38: SUB_BUILD_PATH=amigaos/m68k
cross_amigaos_m68k_MUI38: CPPC=m68k-amigaos-g++
cross_amigaos_m68k_MUI38: AR=m68k-amigaos-ar
cross_amigaos_m68k_MUI38: MORE_CPP_FLAGS="-DAOS_MUI38"
cross_amigaos_m68k_MUI38: LIB_MUICPP_NAME=libMUIcpp38.a
cross_amigaos_m68k_MUI38: OBJ_PATH_SUFFIX=/MUI38
cross_amigaos_m68k_MUI38: build

cross_amigaos_m68k_MUI5: TARGET="Cross AmigaOS m68k"
cross_amigaos_m68k_MUI5: SUB_BUILD_PATH=amigaos/m68k
cross_amigaos_m68k_MUI5: CPPC=m68k-amigaos-g++
cross_amigaos_m68k_MUI5: AR=m68k-amigaos-ar
cross_amigaos_m68k_MUI5: MORE_CPP_FLAGS="-DAOS_MUI5"
cross_amigaos_m68k_MUI5: LIB_MUICPP_NAME=libMUIcpp5.a
cross_amigaos_m68k_MUI5: OBJ_PATH_SUFFIX=/MUI5
cross_amigaos_m68k_MUI5: build

morphos_ppc: TARGET="MorphOS PPC"
morphos_ppc: SUB_BUILD_PATH=morphos/ppc
morphos_ppc: CPPC=g++
morphos_ppc: AR=ar
morphos_ppc: MORE_CPP_FLAGS="-noixemul -fno-threadsafe-statics -D_GLIBCXX_HAS_GTHREADS=0"
morphos_ppc: LIB_MUICPP_NAME=libMUIcpp.a
morphos_ppc: build

cross_morphos_ppc: TARGET="Cross MorphOS PPC"
cross_morphos_ppc: SUB_BUILD_PATH=morphos/ppc
cross_morphos_ppc: CPPC=ppc-morphos-g++
cross_morphos_ppc: AR=ppc-morphos-ar
cross_morphos_ppc: MORE_CPP_FLAGS="-noixemul -fno-threadsafe-statics -D_GLIBCXX_HAS_GTHREADS=0"
cross_morphos_ppc: LIB_MUICPP_NAME=libMUIcpp.a
cross_morphos_ppc: build
	
build:
	@echo "# Build ... $(TARGET) ... $(SUB_BUILD_PATH)"
	$(MAKE) -f makefile.generic.gcc.mk \
	AOSCPP_PATH=../../AmigaOS.cpp.wrapper \
	SUB_BUILD_PATH=$(SUB_BUILD_PATH) CPPC=$(CPPC) AR=$(AR) \
	MORE_CPP_FLAGS=$(MORE_CPP_FLAGS) \
	LIB_MUICPP_NAME=$(LIB_MUICPP_NAME) \
	OBJ_PATH_SUFFIX=$(OBJ_PATH_SUFFIX) \
	all

clean.obj:
	rm -f -R ../../AmigaOS.cpp.wrapper/wrappers/obj/*
	rm -f -R obj/*

clean: clean.obj
	rm -f -R obj/*
	rm -f -R lib/*
