# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -std=c11
LDFLAGS =

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/strutil_test

# Default rule
all: $(TARGET)

# Link the target executable
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Run tests
test: all
	./$(TARGET)

.PHONY: all clean test
