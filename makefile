# Makefile for building the project and running tests

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BIN_DIR = bins
LIB_DIR = libs

# Source files (excluding main.c)
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES = $(patsubst %.c, $(BIN_DIR)/%.o, $(SRC_FILES))

# Executable names
EXECUTABLE = $(BIN_DIR)/byte

# Targets
all: build

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BIN_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)