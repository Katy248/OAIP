EXE = output
SOURCES = main.cpp matrix.cpp
all: $(EXE)

$(EXE): $(SOURCES)
	g++ $(SOURCES) -o $(EXE)

run: $(EXE)
	./$(EXE)

clear:
	rm -f ./$(EXE)
