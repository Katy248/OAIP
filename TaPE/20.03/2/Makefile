CC = g++
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
OUTPUT = $(BIN_DIR)/parser

.PHONY: run build test

$(OUTPUT): $(OBJECTS) $(BIN_DIR) $(SUDOKU_FILE_BIN)
	@echo "Linking files"
	$(CC) $(OBJECTS) -o $(OUTPUT)

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
