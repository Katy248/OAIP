APP_NAME = num-game

CC = g++
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
PO_DIR = po
MO_DIR = mo
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OUTPUT = $(BIN_DIR)/$(APP_NAME)
POS = $(wildcard $(PO_DIR)/*.po)
MOS = $(patsubst $(PO_DIR)/%.po, $(MO_DIR)/%/$(APP_NAME).mo, $(POS))

LOCALE_DIR = /usr/share/locale
LOCALES_PATHS = $(patsubst $(PO_DIR)/%.po, $(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo, $(POS))

CFLAGS += -O3
CXXFLAGS += -Wall

SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .o .d
.PHONY: run build test

$(OUTPUT): $(OBJECTS) $(BIN_DIR) $(SUDOKU_FILE_BIN)
	@echo "Linking files"
	$(CC) $(OBJECTS) $(CXXFLAGS) $(CFLAGS) -o $(OUTPUT)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	@echo "Compile file $< to $@"
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

# Compile locales
$(MO_DIR)/%/$(APP_NAME).mo: $(PO_DIR)/%.po $(MO_DIR)/%/ $(MO_DIR)
	msgfmt $< -o $@
# Copy locales
$(LOCALE_DIR)/%/LC_MESSAGES/$(APP_NAME).mo: $(MO_DIR)/%/$(APP_NAME).mo $(LOCALE_DIR)/%/LC_MESSAGES
	cp $< $@

# DIRS
$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@
$(MO_DIR):
	mkdir $@
$(MO_DIR)/%/:
	mkdir $@
$(LOCALE_DIR)/%/LC_MESSAGES: $(LOCALE_DIR)/%/
	mkdir $@
$(LOCALE_DIR)/%/:
	mkdir $@


build: $(OUTPUT) $(MOS)

run: $(OUTPUT)
	./$(OUTPUT)

install: $(OUTPUT) $(LOCALES_PATHS)
	cp $(OUTPUT) /usr/bin/$(APP_NAME)

uninstall:
	rm -f /usr/bin/$(APP_NAME)

clear:
	rm -rf $(OBJ_DIR) $(BIN_DIR) $(MO_DIR)
