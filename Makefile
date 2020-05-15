COMPILER = g++
OPTIONS = -std=c++17 -Wall --pedantic-errors

TARGET = program

SRC_EXT = .cc
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*$(SRC_EXT))

HEADER_DIR = $(SRC_DIR)
HEADERS = $(wildcard $(HEADER_DIR)/*.h)
PRECOMPILED_HEADER_EXT = .gch
PRECOMPILED_HEADERS = $(addsuffix $(PRECOMPILED_HEADER_EXT), $(HEADERS))

.PHONY: run
run: $(TARGET)
	./$(TARGET) $(ARGS)

.PHONY: build
build: $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -f $(PRECOMPILED_HEADERS)

$(TARGET): $(PRECOMPILED_HEADERS) $(SRCS)
	$(COMPILER) $(OPTIONS) -o $@ $(SRCS)

$(PRECOMPILED_HEADERS): $(HEADERS)
	$(COMPILER) $(OPTIONS) -x c++-header -o $@ $^