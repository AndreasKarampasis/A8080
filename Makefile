# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =

# Bison and Flex commands
BISON = bison -Wcounterexamples
FLEX = flex

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TESTS_DIR = tests
GRAMMAR_DIR = grammar

# Files
PARSER_SRC = $(SRC_DIR)/parser.c
SCANNER_SRC = $(SRC_DIR)/lexer.c
PARSER_OBJ = $(OBJ_DIR)/parser.o
SCANNER_OBJ = $(OBJ_DIR)/lexer.o
SOURCES := $(shell find $(SRC_DIR) -type f -name *.c) 
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))
TARGET = a8080

# Targets
.PHONY: all clean test $(TEST_PHASES)

all: $(TARGET)

$(TARGET): $(OBJECTS) $(PARSER_OBJ) $(SCANNER_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -g -o $@ $^ -g

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -g -c -o $@ $< 

$(PARSER_OBJ): $(PARSER_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(SCANNER_OBJ): $(SCANNER_SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(PARSER_SRC): $(GRAMMAR_DIR)/parser.y
	$(BISON) -d -o $@ $<

$(SCANNER_SRC): $(GRAMMAR_DIR)/lexer.l
	$(FLEX) -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(PARSER_SRC) $(SCANNER_SRC) include/parser.h include/scanner.h $(TARGET)

# Tests
TEST_FILES = $(wildcard $(TESTS_DIR)/*.al)
TEST_PHASES = 

.PHONY: $(TEST_PHASES)

test: $(TEST_PHASES)

$(TEST_PHASES): %: $(TESTS_DIR)/%
	@echo "Running tests in $@"
	@$(MAKE) -C $(TESTS_DIR)/$@
