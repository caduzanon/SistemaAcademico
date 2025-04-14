# Enforce the presence of the GIT repository
# We depend on our submodules, so we have to prevent attempts to
# compile without it being present.
ifeq ($(wildcard .git),)
    $(error YOU HAVE TO USE GIT TO DOWNLOAD THIS REPOSITORY. ABORTING.)
endif


all:
	gcc -o exe-name exe-name.c headerfile.c -lm
clean:
	rm exe-name1 exe-name2
distclean:
	@git submodule deinit --force $(SRC_DIR)
	@rm -rf "$(SRC_DIR)/build"
# Get -j or --jobs argument as suggested in:
# https://stackoverflow.com/a/33616144/8548472
MAKE_PID := $(shell echo $$PPID)
j := $(shell ps T | sed -n 's|.*$(MAKE_PID).*$(MAKE).* \(-j\|--jobs\) *\([0-9][0-9]*\).*|\2|p')

# Default j for clang-tidy
j_clang_tidy := $(or $(j),4)

