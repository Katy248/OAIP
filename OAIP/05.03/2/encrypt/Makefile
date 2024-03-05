SOURCES = main.cpp
BIN_DIR = bin
TEST_INPUT = test
EXE = $(BIN_DIR)/output

build: $(EXE)

$(EXE): $(BIN_DIR) $(SOURCES)
	g++ $(SOURCES) -o $(EXE)

$(BIN_DIR):
	mkdir $@

test: $(EXE) $(TEST_INPUT)
	$(EXE) < $(TEST_INPUT)

clear:
	rm -rf $(BIN_DIR)
