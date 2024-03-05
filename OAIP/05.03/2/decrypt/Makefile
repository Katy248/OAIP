SOURCES = main.cpp
BIN_DIR = ./bin
EXE = $(BIN_DIR)/output

build: $(EXE)

$(EXE): $(BIN_DIR) $(SOURCES)
	g++ $(SOURCES) -o $(EXE) -ggdb

$(BIN_DIR):
	mkdir $@

clear:
	rm -rf $(BIN_DIR)
