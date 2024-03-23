#
#  MakeFile for "AmigaOS MUI C++ wrapper" project
#
# (c) 2022-2024 TDolphin
#

SUB_PROJECTS = wrappers tests examples

all:
	@echo "make aos_m68k - AmigaOS m68k build (cross compilation on linux)"
	@echo "make mos_ppc - MorphOS PowerPC build"
	@echo "make clean - remove all obj files and lib file"

aos_m68k: sub_projects_aos_m68k

mos_ppc: sub_projects_mos_ppc

sub_projects_aos_m68k:
	@echo "------------------------------------------------"
	@date
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) amigaos_m68k -C $$dir; \
	done
	@date
	@echo "------------------------------------------------"

sub_projects_mos_ppc:
	@echo "------------------------------------------------"
	@date
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) morphos_ppc -C $$dir; \
	done
	@date
	@echo "------------------------------------------------"

clean_examples:
	$(MAKE) clean -C examples

clean:
	@for dir in $(SUB_PROJECTS); do \
		$(MAKE) clean -C $$dir; \
	done

rebuild_aos_m68k: clean aos_m68k

rebuild_mos_ppc: clean mos_ppc
