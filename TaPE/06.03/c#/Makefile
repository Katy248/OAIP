BIN_DIR = bin
EXE = $(BIN_DIR)/output-
SOURCES = src/Program.cs src/Game.cs src/Card.cs src/Random.cs

all: build

build: $(EXE)

$(EXE): $(SOURCES) $(BIN_DIR)
	bflat build $(SOURCES) -o $(EXE) --no-globalization --no-debug-info

run: $(EXE)
	./$(EXE)

test: $(EXE)
	./$(EXE) 100


$(BIN_DIR):
	mkdir $@
