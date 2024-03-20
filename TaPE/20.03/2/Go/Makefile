BIN_DIR = bin
OUTPUT = $(BIN_DIR)/parser
SOURCES = $(wildcard *.go)

$(OUTPUT): $(SOURCES) $(BIN_DIR)
	go build -o $(OUTPUT) $(SOURCES)

$(BIN_DIR):
	mkdir $@

run: $(OUTPUT)
	./$(OUTPUT)

build: $(OUTPUT)

test: $(OUTPUT) test.txt
	@echo 
	@echo "Test with cli args input"
	@echo "---"
	./$(OUTPUT) 12,2,sdf,,-12.3 3 3 3 333
	@echo 
	@echo "Test with stdin input"
	@echo "---"
	./$(OUTPUT) < test.txt
