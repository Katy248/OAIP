ifeq ($(OS), Windows_NT)
	EXE = ./output.exe
else
	EXE = ./output
endif

SOURCES = main.cpp
TEST_INPUT = test.test

all: $(EXE)

$(EXE): $(SOURCES)
	@echo "Current OS: $(OS)"
	@echo "Executable name: $(EXE)"
	g++ $(SOURCES) -o $(EXE)

run: $(EXE)
	$(EXE)

test: $(EXE) $(TEST_INPUT)
	$(EXE) < $(TEST_INPUT)

test-win: $(EXE) $(TEST_INPUT)
	pwsh -NoProfile -NonInteractive -NoLogo -CommandWithArgs " Start-Process -FilePath ./output.exe -RedirectStandardInput ./test.test -NoNewWindow "

clear:
	rm -f $(EXE)
