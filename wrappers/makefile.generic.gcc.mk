#
#  AmigaOS MUI C++ wrapper
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

# trace flags
# TRACE_MUI - trace MUI (-DTRACE_MUI)
# TRACE_SSC - trace String Storage Collector (-DTRACE_SSC)
DEBUG_FLAGS = #-ggdb -g3 

# compiler/linker flags
# WARNING: use the same -Ox option for this lib and Your application, differnet values can case linking errors
CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS_X) -std=c++17 -Isrc -O1
AFLAGS = rcs

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

MODULES = AOS Core MUI MUI/Context MUI/Core MUI/MCC MUI/Notifier MUI/Notifier/Core MUI/Notifier/Dest MUI/Notifier/Source
SRC_DIRS = src $(addprefix src/,$(MODULES))
SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/%.o,$(SRCS))

# target lib
LIB_MUICPP = lib/$(SUB_BUILD_PATH)/libMUIcpp.a

all: $(LIB_MUICPP)

obj/$(SUB_BUILD_PATH)/%.o: src/%.cpp src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

$(LIB_MUICPP): $(OBJS) 
	$(dir_guard)
	$(AR) $(AFLAGS) $@ $^

clean :
	rm -f obj/$(SUB_BUILD_PATH)/*.o
	rm -f lib/$(SUB_BUILD_PATH)/*.a

rebuild : clean all
