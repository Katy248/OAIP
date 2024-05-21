APP_NAME ?= num-game

CC ?= gcc

CONFIGURATION ?=

BUILD_DIR	= ./build

OUT_DIR		= $(BUILD_DIR)/out
OBJ_DIR		= $(BUILD_DIR)/obj
DEPS_DIR	= $(BUILD_DIR)/deps
SRC_DIR		= ./src
PO_DIR		= ./po
LOCALES_DIR	= $(OUT_DIR)/locale
POT_FILE	= $(PO_DIR)/messages.pot
SOURCES		= $(wildcard $(SRC_DIR)/*.c)
POS			= $(wildcard $(PO_DIR)/*.po)
OBJECTS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
DEPENDENCIES= $(patsubst $(SRC_DIR)/%.c, $(DEPS_DIR)/%.d, $(SOURCES))
BIN_FILE	= $(OUT_DIR)/$(APP_NAME)
LOCALES		= $(patsubst $(PO_DIR)/%.po, $(LOCALES_DIR)/%/LC_MESSAGES/$(APP_NAME).mo, $(POS))

# Installation
INSTALLED_LOCALE_DIR ?= /usr/share/locale
INSTALLED_LOCALES := $(patsubst $(PO_DIR)/%.po, $(INSTALLED_LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo, $(POS))
INSTALLATION_DIR ?= /usr/bin
INSTALLED_FILE := $(INSTALLATION_DIR)/$(APP_NAME)

CFLAGS += -O3 -Wall

SHELL ?= /bin/zsh
NODEPS := all help uninstall clear

.SUFFIXES:
.SUFFIXES: .c .h .o .d .po .mo .pot
.PHONY: all help run build build-release build-debug test install uninstall clear generate-pot

all: help
help:
	@echo "Makefile for $(APP_NAME)"
	@echo ""
	@echo "Available recipes:"
	@echo "  build"
	@echo "  build-release"
	@echo "  build-debug"
	@echo "  build"
	@echo "  run"
	@echo "  install"
	@echo "  uninstall"
	@echo "  generate-pot"
	@echo "  clear"

build-release: CONFIGURATION = release
build-release: CFLAGS +=
build-release: build

build-debug: CONFIGURATION = debug
build-debug: CFLAGS += -g -ggdb -Og
build-debug: build

build: $(BIN_FILE) $(LOCALES)
	@echo "Build complete"

run: 
	@echo "Building '$(APP_NAME)'"
	@make build
	@echo "Running '$(APP_NAME)'"
	@echo ""
	@echo ""
	@./$(BIN_FILE)

install: $(INSTALLED_FILE) $(INSTALLED_LOCALES)
	@echo "Installation complete"

uninstall:
	@rm -rf $(INSTALLED_FILE) $(INSTALLED_LOCALES)
	@echo "Uninstalled"

generate-pot: $(POT_FILE)
	@echo "Generated into '$(POT_FILE)'"

clear:
	@rm -rf $(BUILD_DIR)
	@echo "Cleared"


# FILES

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
	-include $(DEPENDENCIES)
endif

# Binary file from objects
$(BIN_FILE): $(OBJECTS) $(OUT_DIR)
	@echo "Current configuration: '$(CONFIGURATION)'"
	@echo "Using CFLAGS = '$(CFLAGS)'"
	@echo "Linking object files '$(OBJECTS)' to $(BIN_FILE)"
	@$(CC) $(OBJECTS) $(CFLAGS) -o $(BIN_FILE)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@echo "Compile source file '$<' to object file '$@'"
	@$(CC) $(CFLAGS) -c $< -o $@

# Deps file from source file
$(DEPS_DIR)/%.d: $(SRC_DIR)/%.c $(DEPS_DIR)
	@echo "Generationg dependencies file for '$<'"
	$(CC) $(CFLAGS) -MM $< -o $@

# Compile locales
$(LOCALES_DIR)/%/LC_MESSAGES/$(APP_NAME).mo: $(PO_DIR)/%.po $(LOCALES_DIR)/%/LC_MESSAGES
	@echo "Compile translation file '$<' to '$@'"
	@msgfmt $< -o $@

# Copy locales
$(INSTALLED_LOCALE_DIR)/%.mo: $(LOCALES_DIR)/%.mo $(INSTALLED_LOCALE_DIR)/%/LC_MESSAGES
	@echo "Copy target locale file '$<' to '$@'"
	@cp $< $@

$(INSTALLED_FILE): $(BIN_FILE) $(INSTALLATION_DIR)
	@echo "Installing $(APP_NAME) to '$(INSTALLATION_DIR)'"
	@echo "Copy binary '$(BIN_FILE)' to '$(INSTALLED_FILE)'"
	@cp $(BIN_FILE) $(INSTALLED_FILE)

$(POT_FILE): $(SOURCES)
	@echo "Generating '$(POT_FILE)' from sources"
	@xgettext $(SOURCES) --language=c -o $(POT_FILE)

# DIRS

$(OUT_DIR):
	@echo "Creating outputs directory '$@'"
	@mkdir -p $@
$(OBJ_DIR):
	@echo "Creating object files directory '$@'"
	@mkdir -p $@
$(LOCALES_DIR)/%/LC_MESSAGES:
	@echo "Creating output directory for .mo file '$@'"
	@mkdir -p $@
$(DEPS_DIR):
	@echo "Creating dependencies directory '$@'"
	@mkdir -p $@
$(INSTALLED_LOCALE_DIR)/%/LC_MESSAGES:
	@echo "Creating LC_MESSAGES directory '$@'"
	@mkdir -p $@
