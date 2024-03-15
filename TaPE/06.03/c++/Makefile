CC				:= g++
# Directories
OBJ_DIR			:= obj
BIN_DIR			:= bin
DEPS_DIR		:= deps
SRC_DIR			:= src
# Files
SOURCES			:= $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS			:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
DEPENDENCIES	:= $(patsubst $(SRC_DIR)/%.cpp, $(DEPS_DIR)/%.d, $(SOURCES))
OUTPUT			:= $(BIN_DIR)/bingo

.PHONY: run build test

$(OUTPUT): $(OBJECTS) $(BIN_DIR)
	@echo "Linking files"
	@$(CC) $(OBJECTS) -o $(OUTPUT)

# Object file from source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS_DIR)/%.d $(OBJ_DIR)
	@echo "Compile file $< to $@"
	@$(CC) -c $< -o $@

include $(DEPENDENCIES)

$(DEPS_DIR)/%.d: $(SRC_DIR)/%.cpp $(DEPS_DIR)
	@echo "Generationg dependencies for $< into $@"
	@$(CC) -M $< -o $@


build: $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT) $(SUDOKU_FILE_BIN)

# DIRS
$(OBJ_DIR):
	mkdir $@
$(BIN_DIR):
	mkdir $@
$(DEPS_DIR):
	mkdir $@

clear:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(DEPS_DIR)
