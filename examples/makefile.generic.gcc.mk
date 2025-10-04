#
#  AmigaOS MUI C++ wrapper
#
#  Examples
#
#  (c) 2022-2025 TDolphin
#
#  generic makefile for gcc
#

CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS) -I${AOSCPP_PATH}/wrappers/src -I$(PROJECT) -I../wrappers/src -I../components/src -O3
LFLAGS = -L../wrappers/lib/$(SUB_BUILD_PATH) $(MORE_LFLAGS) -lstdc++ -noixemul -Os

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

MUI_COMPONENTS_PATH = ../components
MUI_COMPONENTS_MODULES = Components/MCC Components/MCC/Core
MUI_COMPONENTS_SRC_DIRS = $(addprefix $(MUI_COMPONENTS_PATH)/src/,$(MUI_COMPONENTS_MODULES))
MUI_COMPONENTS_SRCS = $(foreach sdir,$(MUI_COMPONENTS_SRC_DIRS),$(wildcard $(sdir)/*.cpp))

SRC_DIRS = $(shell echo $(MODULES) | tr ',' ' ')
SRCS = $(wildcard $(PROJECT)/*.cpp) $(foreach sdir,$(SRC_DIRS),$(wildcard $(PROJECT)/$(sdir)/*.cpp))
OBJS = $(patsubst %.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))\
	$(patsubst $(MUI_COMPONENTS_PATH)/src/%.cpp,$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o,$(MUI_COMPONENTS_SRCS))

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

$(MUI_COMPONENTS_PATH)/obj/$(SUB_BUILD_PATH)/%.o: $(MUI_COMPONENTS_PATH)/src/%.cpp $(MUI_COMPONENTS_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@
