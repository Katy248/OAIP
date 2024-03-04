EXE = output
all: build

build: main.cpp
	g++ main.cpp -o $(EXE)

run: build $(EXE)
	./$(EXE)

clear:
	rm -r ./$(EXE)