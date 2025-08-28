#
#  AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2025 TDolphin
#
#  generic makefile for gcc
#

CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS) -I${AOSCPP_PATH}/wrappers/src -I$(PROJECT) -I../wrappers/src -O3
LFLAGS = -L../wrappers/lib/$(SUB_BUILD_PATH) $(MORE_LFLAGS) -lstdc++ -noixemul -Os

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
	$(OBJDUMP) --syms --reloc --disassemble-all $@_nonstripped > $@_disassembled
	@echo "## Finished."

obj/$(SUB_BUILD_PATH)/%.o: %.cpp %.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

clean :
	rm -f obj/$(SUB_BUILD_PATH)/*.o
	rm -f -R out/$(SUB_BUILD_PATH)/*

rebuild : clean all
