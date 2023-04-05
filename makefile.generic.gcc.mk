#
#  AmigaOS MUI C++ wrapper
#
#  (c) TDolphin 2022-2023
#
#  generic makefile for gcc
#
#  for MorphOS (host) (ppc)
#
#    requires: MUI dev
#
#  for Linux (host) x86_64 (64-bit)
#
# cross compilation setup from -> https://github.com/bebbo/amiga-gcc
#
#  	  requires: MUI5 dev
#

# trace flags
# TRACE_MUI - trace MUI (-DTRACE_MUI)
DEBUG_FLAGS = #-ggdb -g3 

CPP_FLAGS = $(DEBUG_FLAGS) -std=c++17 -Isrc -O2

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

MODULES = AOS Core MUI MUI/Core MUI/MCC
SRC_DIRS = src $(addprefix src/,$(MODULES))
SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))

all: $(OBJS)

obj/$(SUB_BUILD_PATH)/%.o: src/%.cpp src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -f obj/$(SUB_BUILD_PATH)/*.o

rebuild : clean all
