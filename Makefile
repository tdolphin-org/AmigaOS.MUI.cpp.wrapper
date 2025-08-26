#
#  MakeFile for "AmigaOS MUI C++ wrapper" project
#
# (c) 2022-2025 TDolphin
#

SUB_PROJECTS = wrappers tests examples

all:
	@echo "# Available actions:"
	@echo "make cross_aos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make mos_ppc - MorphOS PowerPC build"
	@echo "make cross_mos_ppc - MorphOS PowerPC build (cross compilation on linux)"
	@echo "make clean - remove all obj files and lib file"

cross_aos_m68k: sub_projects_cross_aos_m68k

mos_ppc: sub_projects_mos_ppc

cross_mos_ppc: sub_projects_cross_mos_ppc


sub_projects_build:
	@echo "------------------------------------------------"
	@date
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) $(BUILD_TARGET) -C $$dir; \
	done
	@date
	@echo "------------------------------------------------"

sub_projects_cross_aos_m68k: BUILD_TARGET=cross_amigaos_m68k
sub_projects_cross_aos_m68k: sub_projects_build

sub_projects_mos_ppc: BUILD_TARGET=morphos_ppc
sub_projects_mos_ppc: sub_projects_build

sub_projects_cross_mos_ppc: BUILD_TARGET=cross_morphos_ppc
sub_projects_cross_mos_ppc: sub_projects_build

clean_examples:
	$(MAKE) clean -C examples

clean:
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean -C $$dir; \
	done

rebuild_aos_m68k: clean aos_m68k

rebuild_mos_ppc: clean mos_ppc
