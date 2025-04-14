# ==========================
# Project Configuration
# ==========================
SRC_DIR := src
LIB_DIR := lib
INC_DIR := include
BUILD_DIR := build
TARGET := $(BUILD_DIR)/app.exe

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I$(INC_DIR)

# Source and object files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
LIB_FILES := $(wildcard $(LIB_DIR)/*.c)
OBJ_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRC_FILES) $(LIB_FILES)))

# Detect -j argument from make
MAKE_PID := $(shell echo $$PPID)
j := $(shell ps T | sed -n 's|.*$(MAKE_PID).*$(MAKE).* \(-j\|--jobs\) *\([0-9][0-9]*\).*|\2|p')
j_clang_tidy := $(or $(j),4)

# Enforce the presence of the GIT repository
ifeq ($(wildcard .git),)
    $(error YOU HAVE TO USE GIT TO DOWNLOAD THIS REPOSITORY. ABORTING.)
endif

# ==========================
# Build Rules
# ==========================

all: $(BUILD_DIR) $(TARGET)
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(LIB_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir $(BUILD_DIR)

clean:
	del /Q $(BUILD_DIR)\*.o $(TARGET) 2>NUL
distclean:
	@git submodule deinit --force $(SRC_DIR)
	@rmdir /S /Q $(BUILD_DIR) 2>NUL

.PHONY: all clean distclean

