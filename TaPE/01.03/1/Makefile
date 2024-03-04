SOURCES = ./main.cpp
SOURCES_ALT = ./AlternativeSolution.cpp
BIN = ./bin
TEST_INPUT = ./test
EXE = $(BIN)/output

all: $(EXE)

$(EXE): $(BIN) $(SOURCES)
	g++ $(SOURCES) -o $(EXE) -ggdb

$(BIN):
	mkdir $@


run: $(EXE)
	$(EXE)

test: $(EXE) $(TEST_INPUT)
	$(EXE) < $(TEST_INPUT)

clear:
	rm -rf $(BIN)

# ALT version

# Build alternative version
build-alt: $(BIN) $(SOURCES_ALT)
	g++ $(SOURCES_ALT) -o $(EXE) -ggdb
run-alt: build-alt run
