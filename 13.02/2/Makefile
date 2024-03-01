EXE = output
CC = gcc
FILES = main.c

all: build $(EXE)

build: main.c
	$(CC) $(FILES) -o $(EXE)

run: build $(EXE)
	./$(EXE)