BIN_DIR = bin
EXE = $(BIN_DIR)/output
SOURCES = src/main.cpp src/game.cpp src/card.cpp src/rand_card.cpp

all: build

build: $(EXE)

$(EXE): $(SOURCES) $(BIN_DIR)
	g++ $(SOURCES) -o $(EXE)

run: $(EXE)
	./$(EXE)

test: $(EXE)
	./$(EXE) 100


$(BIN_DIR):
	mkdir $@
