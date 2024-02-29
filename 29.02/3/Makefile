EXE = output
all: $(EXE)

$(EXE): main.cpp matrix.cpp
	g++ main.cpp matrix.cpp -o $(EXE)

run: $(EXE)
	./$(EXE)

clear:
	rm -f ./$(EXE)
