CC = g++
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OUTPUT = $(BIN_DIR)/parser

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

build: $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT) $(SUDOKU_FILE_BIN)

clear:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# DIRS
$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@
