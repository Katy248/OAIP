SOURCES = ./main.cpp
BIN = ./bin
TEST_INPUT = ./tests/test
EXE = $(BIN)/output

all: $(EXE)

$(EXE): $(BIN) $(SOURCES)
	@echo "Current OS: $(OS)"
	@echo "Executable name: $(EXE)"
	g++ $(SOURCES) -o $(EXE) -ggdb

$(BIN):
	mkdir $@

run: $(EXE)
	$(EXE)

test: $(EXE) $(TEST_INPUT)
	$(EXE) < $(TEST_INPUT)

clear:
	rm -rf $(BIN)

# test-win: $(EXE) $(TEST_INPUT)
# 	pwsh -NoProfile -NonInteractive -NoLogo -CommandWithArgs " Start-Process -FilePath ./output.exe -RedirectStandardInput ./test.test -NoNewWindow "
