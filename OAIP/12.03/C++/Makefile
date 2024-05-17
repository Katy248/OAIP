CC = g++
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OUTPUT = $(BIN_DIR)/sudoku
SUDOKU_FILE_SRC = $(SRC_DIR)/sudoku.txt
SUDOKU_FILE_BIN = $(BIN_DIR)/sudoku.txt

.PHONY: run build test

$(OUTPUT): $(OBJECTS) $(BIN_DIR) $(SUDOKU_FILE_BIN)
	@echo "Linking files"
	$(CC) $(OBJECTS) -o $(OUTPUT)

$(SUDOKU_FILE_BIN): $(SUDOKU_FILE_SRC)
	@echo "Copy sudoku file"
	cp $(SUDOKU_FILE_SRC) $(SUDOKU_FILE_BIN)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(OBJ_DIR)
	@echo "Compile file $< to $@"
	$(CC) -c $< -o $@

build: $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT) $(SUDOKU_FILE_BIN)

clear:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

# DIRS
$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@
