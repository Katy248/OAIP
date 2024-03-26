SOURCES = main.cpp
BIN_DIR = bin
OUTPUT = $(BIN_DIR)/output

build: $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

$(OUTPUT): $(SOURCES) $(BIN_DIR)
	g++ $(SOURCES) -o $(OUTPUT)

$(BIN_DIR):
	mkdir $@
