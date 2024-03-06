BIN_DIR = bin
EXE = $(BIN_DIR)/output
SOURCES = src/main.cpp src/game.cpp src/card.cpp src/rand_card.cpp

all: build $(EXE)

build: $(SOURCES) $(BIN_DIR)
	g++ $(SOURCES) -o $(EXE)

run: build $(EXE)
	./$(EXE)


$(BIN_DIR):
	mkdir $@
