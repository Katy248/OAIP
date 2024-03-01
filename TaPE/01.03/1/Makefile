EXE = output
SOURCES = main.cpp
all: $(EXE)

$(EXE): $(SOURCES)
	g++ $(SOURCES) -o $(EXE)

run: $(EXE)
	./$(EXE)

test: $(EXE) test.test
	./$(EXE) < test.test

clear:
	rm -f ./$(EXE)
