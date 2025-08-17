#
#  AmigaOS MUI C++ wrapper
#
#  (c) 2022-2025 TDolphin
#
#  generic makefile for gcc
#
#  for MorphOS (host) (ppc)
#
#    requires: MUI dev (MorphOS SDK) + NList Dev, TextEditor Dev 
#
#  for Linux (host) x86_64 (64-bit)
#
#  1. AmigaOS m68k cross compilation setup from -> https://github.com/bebbo/amiga-gcc
#
#    requires: MUI3.8 or MUI5 dev + NList Dev, TextEditor Dev
#
#  2. MorphOS cross compilation setup from -> https://morph.zone/modules/newbb_plus/viewtopic.php?topic_id=13308&forum=12
#
#    requires: MUI dev (MorphOS SDK) + NList Dev, TextEditor Dev
#

# replace , => space
MORE_CPP_FLAGS_X = $(shell echo $(MORE_CPP_FLAGS) | tr ',' ' ')

# trace flags
# TRACE_MUI - trace MUI (-DTRACE_MUI)
# TRACE_SSC - trace String Storage Collector (-DTRACE_SSC)
DEBUG_FLAGS = #-ggdb -g3 

# compiler/linker flags
# WARNING: use the same -Ox option for this lib and Your application, diffrent values can cause linking errors
# -fno-rtti disables RTTI (Run-Time Type Information) support, which is not needed for MUI C++ wrapper
CPP_FLAGS = $(DEBUG_FLAGS) $(MORE_CPP_FLAGS_X) -I${AOSCPP_PATH}/wrappers/src -Isrc\
	-fno-rtti -ffunction-sections -fdata-sections -Os
CPP_FLAGS_LIGHT = $(CPP_FLAGS) -DSTD_LIGHT
AFLAGS = rcs

dir_guard = mkdir -p $(@D)

BINPATH = out/$(SUB_BUILD_PATH)

AOS_WRAPPER_PATH = ${AOSCPP_PATH}/wrappers
AOS_WRAPPER_MODULES = Core AOS amiga_std_light
AOS_WRAPPER_SRC_DIRS = $(addprefix $(AOS_WRAPPER_PATH)/src/,$(AOS_WRAPPER_MODULES))
AOS_WRAPPER_SRCS = $(foreach sdir,$(AOS_WRAPPER_SRC_DIRS),$(wildcard $(sdir)/*.cpp))
AOS_WRAPPER_CPP_FLAGS = $(CPP_FLAGS) -DDEBUG_TAG_SYMBOLS
AOS_WRAPPER_CPP_FLAGS_LIGHT = $(CPP_FLAGS) -DSTD_LIGHT

MODULES = Core MUI MUI/Context MUI/Core MUI/MCC MUI/Notifier MUI/Notifier/Core MUI/Notifier/Dest MUI/Notifier/Source
SRC_DIRS = src $(addprefix src/,$(MODULES))
SRCS = $(foreach sdir,$(SRC_DIRS),$(wildcard $(sdir)/*.cpp))
OBJS = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/normal/%.o,$(SRCS))\
	$(patsubst $(AOS_WRAPPER_PATH)/src/%.cpp,$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/normal/%.o,$(AOS_WRAPPER_SRCS))
OBJS_LIGHT = $(patsubst src/%.cpp,obj/$(SUB_BUILD_PATH)/light/%.o,$(SRCS))\
	$(patsubst $(AOS_WRAPPER_PATH)/src/%.cpp,$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/light/%.o,$(AOS_WRAPPER_SRCS))

# target libs
LIB_MUICPP = lib/$(SUB_BUILD_PATH)/libMUIcpp.a
LIB_MUICPP_LIGHT = lib/$(SUB_BUILD_PATH)/libMUIcpp.light.a

all: $(LIB_MUICPP) $(LIB_MUICPP_LIGHT)

obj/$(SUB_BUILD_PATH)/normal/%.o: src/%.cpp src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS) -c $< -o $@

obj/$(SUB_BUILD_PATH)/light/%.o: src/%.cpp src/%.hpp
	$(dir_guard)
	$(CPPC) $(CPP_FLAGS_LIGHT) -c $< -o $@

$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/normal/%.o: $(AOS_WRAPPER_PATH)/src/%.cpp $(AOS_WRAPPER_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(AOS_WRAPPER_CPP_FLAGS) -c $< -o $@

$(AOS_WRAPPER_PATH)/obj/$(SUB_BUILD_PATH)/light/%.o: $(AOS_WRAPPER_PATH)/src/%.cpp $(AOS_WRAPPER_PATH)/src/%.hpp
	$(dir_guard)
	$(CPPC) $(AOS_WRAPPER_CPP_FLAGS_LIGHT) -c $< -o $@

$(LIB_MUICPP): $(OBJS) 
	$(dir_guard)
	$(AR) $(AFLAGS) $@ $^

$(LIB_MUICPP_LIGHT): $(OBJS_LIGHT) 
	$(dir_guard)
	$(AR) $(AFLAGS) $@ $^
