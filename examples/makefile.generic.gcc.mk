#
#  AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2024 TDolphin
#
#  generic makefile for gcc
#
#  for MorphOS (host) (ppc)
#
#    requires: MUI dev (MorphOS SDK)
#
#  for Linux (host) x86_64 (64-bit)
#
# cross compilation setup from -> https://github.com/bebbo/amiga-gcc
#
#  	  requires: MUI5 dev
#

# replace , => space
MORE_CPP_FLAGS_X = $(shell echo $(MORE_CPP_FLAGS) | tr ',' ' ')
MORE_LFLAGS_X = $(shell echo $(MORE_LFLAGS) | tr ',' ' ')

CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS_X) -std=c++17 -I$(PROJECT) -I../wrappers/src -O1
LFLAGS = -L../wrappers/lib/$(SUB_BUILD_PATH) -lMUIcpp $(MORE_LFLAGS_X) -lstdc++ -noixemul

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

SRC_DIRS = $(shell echo $(MODULES) | tr ',' ' ')
SRCS = $(wildcard $(PROJECT)/*.cpp) $(foreach sdir,$(SRC_DIRS),$(wildcard $(PROJECT)/$(sdir)/*.cpp))
OBJS = $(patsubst %.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))

all: $(BINPATH)/$(APP_EXAMPLE)

$(BINPATH)/$(APP_EXAMPLE): $(OBJS)
	$(dir_guard)
	@echo "## Linking example ..."
	$(CPPC) $^ $(LFLAGS) -o $@_nonstripped
	@echo "## Stripping ..."
	$(STRIP) --remove-section=.comment $@_nonstripped -o $@
	rm $@_nonstripped
	@echo "## Finished."

obj/$(SUB_BUILD_PATH)/%.o: %.cpp %.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -f obj/$(SUB_BUILD_PATH)/*.o
	rm -f -R out/$(SUB_BUILD_PATH)/*

rebuild : clean all
