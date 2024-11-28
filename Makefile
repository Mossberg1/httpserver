# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -Isrc -g
LDFLAGS = 

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Output binary
TARGET = $(BIN_DIR)/httpserver

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(dir $*)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)


