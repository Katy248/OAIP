CC = gcc
OBJ_DIR = obj
BIN_DIR = bin
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
OUTPUT = $(BIN_DIR)/sudoku

.PHONY: run build

$(OUTPUT): $(OBJECTS) $(BIN_DIR)
	@echo "Linking files"
	$(CC) $(OBJECTS) -o $(OUTPUT)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(OBJ_DIR)
	@echo "Compile file $< to $@"
	$(CC) -c $< -o $@

build: $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

test: $(OUTPUT) sudoku
	./$(OUTPUT) < sudoku

clear:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)

# DIRS
$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@
