APP_NAME = my-program

CC = g++
FILE_EXTENSION = cpp

OBJ_DIR ?= obj
BIN_DIR ?= bin
SRC_DIR ?= src
PO_DIR ?= po
MO_DIR ?= mo
SOURCES := $(wildcard $(SRC_DIR)/*.$(FILE_EXTENSION))
OBJECTS := $(patsubst $(SRC_DIR)/%.$(FILE_EXTENSION), $(OBJ_DIR)/%.o, $(SOURCES))
BIN_FILE := $(BIN_DIR)/$(APP_NAME)
POS := $(wildcard $(PO_DIR)/*.po)
MOS := $(patsubst $(PO_DIR)/%.po, $(MO_DIR)/%/$(APP_NAME).mo, $(POS))
CFLAGS += -O3
CXXFLAGS += -Wall
# Installation
LOCALE_DIR ?= /usr/share/locale
LOCALE_FILES := $(patsubst $(PO_DIR)/%.po, $(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo, $(POS))
INSTALLATION_DIR ?= /usr/bin
INSTALLED_FILE := $(INSTALLATION_DIR)/$(APP_NAME)

CFLAGS += -O3
CXXFLAGS += -Wall

SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .o .d .po .mo
.PHONY: all help run build test install uninstall

all: help
help:
	@echo "Makefile for $(APP_NAME)"
	@echo ""
	@echo "Available recipes:"
	@echo "  build"
	@echo "  run"
	@echo "  install"
	@echo "  uninstall"
	@echo "  clear"

build: $(BIN_FILE) $(MOS)
	@echo "Build complete"

run: build
	./$(BIN_FILE)

install: $(INSTALLED_FILE) $(LOCALE_FILES)
	@echo "Installation complete"

uninstall:
	@rm -rf $(INSTALLED_FILE) $(LOCALE_FILES)
	@echo "Uninstalled"

clear:
	@rm -rf $(OBJ_DIR) $(BIN_DIR) $(MO_DIR)
	@echo "Cleared"



$(BIN_FILE): $(OBJECTS) $(BIN_DIR) $(SUDOKU_FILE_BIN)
	@echo "Linking files"
	@$(CC) $(OBJECTS) $(CXXFLAGS) $(CFLAGS) -o $(BIN_FILE)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	@echo "Compile file $< to $@"
	@$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

# Compile locales
$(MO_DIR)/%/$(APP_NAME).mo: $(PO_DIR)/%.po $(MO_DIR)/%/
	@echo "Compile translation file $< to $@"
	@msgfmt $< -o $@
# Copy locales
$(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo: $(MO_DIR)/%/$(APP_NAME).mo $(LOCALE_DIR)/%/LC_MESSAGES
	@echo "Copy target locale file $< to $@"
	@cp $< $@

$(INSTALLED_FILE): $(BIN_FILE) $(INSTALLATION_DIR)
	@echo "Installing $(APP_NAME) to $(INSTALLATION_DIR)"
	@echo "Copy binary $(BIN_FILE) to $(INSTALLED_FILE)"
	@cp $(BIN_FILE) $(INSTALLED_FILE)

# DIRS
$(OBJ_DIR):
	@echo "Creating objects directory $@"
	@mkdir -p $@
$(BIN_DIR):
	@echo "Creating binaries directory $@"
	@mkdir -p $@
$(MO_DIR)/%/:
	@echo "Creating locale subdirectory $@ in $<"
	@mkdir -p $@
$(LOCALE_DIR)/%/LC_MESSAGES:
	@echo "Creating LC_MESSAGES directory $@"
	@mkdir -p $@
