APP_NAME ?= num-game

CC ?= gcc

OBJ_DIR		?= obj
BIN_DIR		?= bin
DEPS_DIR	?= deps
SRC_DIR		?= src
PO_DIR		?= po
MO_DIR		?= mo
POT_FILE	:= $(PO_DIR)/messages.pot
SOURCES		:= $(wildcard $(SRC_DIR)/*.c)
OBJECTS		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
DEPENDENCIES:= $(patsubst $(SRC_DIR)/%.c, $(DEPS_DIR)/%.d, $(SOURCES))
BIN_FILE	:= $(BIN_DIR)/$(APP_NAME)
POS			:= $(wildcard $(PO_DIR)/*.po)
MOS			:= $(patsubst $(PO_DIR)/%.po, $(MO_DIR)/%.mo, $(POS))

# Installation
LOCALE_DIR ?= /usr/share/locale
LOCALE_FILES := $(patsubst $(PO_DIR)/%.po, $(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo, $(POS))
INSTALLATION_DIR ?= /usr/bin
INSTALLED_FILE := $(INSTALLATION_DIR)/$(APP_NAME)

CFLAGS += -O3 -Wall

SHELL ?= /bin/sh
NODEPS := all help uninstall clear

.SUFFIXES:
.SUFFIXES: .c .h .o .d .po .mo .pot
.PHONY: all help run build test install uninstall clear generate-pot

all: help
help:
	@echo "Makefile for $(APP_NAME)"
	@echo ""
	@echo "Available recipes:"
	@echo "  build"
	@echo "  run"
	@echo "  install"
	@echo "  uninstall"
	@echo "  generate-pot"
	@echo "  clear"

build: $(BIN_FILE) $(MOS)
	@echo "Build complete"

run: build
	@./$(BIN_FILE)

install: $(INSTALLED_FILE) $(LOCALE_FILES)
	@echo "Installation complete"

uninstall:
	@rm -rf $(INSTALLED_FILE) $(LOCALE_FILES)
	@echo "Uninstalled"

generate-pot: $(POT_FILE)
	@echo "Generated into '$(POT_FILE)'"

clear:
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(MO_DIR) $(DEPS_DIR)
	@echo "Cleared"


# FILES

ifeq (0, $(words $(findstring $(MAKECMDGOALS), $(NODEPS))))
	-include $(DEPENDENCIES)
endif

# Binary file from objects
$(BIN_FILE): $(OBJECTS) $(BIN_DIR)
	@echo "Linking files '$(OBJECTS)'"
	@$(CC) $(OBJECTS) $(CFLAGS) -o $(BIN_FILE)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@echo "Compile file '$<' to '$@'"
	@$(CC) $(CFLAGS) -c $< -o $@

# Deps file from source file
$(DEPS_DIR)/%.d: $(SRC_DIR)/%.c $(DEPS_DIR)
	@echo "Generationg dependencies file for '$<'"
	$(CC) $(CFLAGS) -MM $< -o $@

# Compile locales
$(MO_DIR)/%.mo: $(PO_DIR)/%.po $(MO_DIR)
	@echo "Compile translation file '$<' to '$@'"
	@msgfmt $< -o $@

# Copy locales
$(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo: $(MO_DIR)/%.mo $(LOCALE_DIR)/%/LC_MESSAGES
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

$(OBJ_DIR):
	@echo "Creating objects directory '$@'"
	@mkdir -p $@
$(BIN_DIR):
	@echo "Creating binaries directory '$@'"
	@mkdir -p $@
$(MO_DIR):
	@echo "Creating directory for .mo files '$@'"
	@mkdir -p $@
$(DEPS_DIR):
	@echo "Creating dependencies directory '$@'"
	@mkdir -p $@
$(LOCALE_DIR)/%/LC_MESSAGES:
	@echo "Creating LC_MESSAGES directory '$@'"
	@mkdir -p $@
