# Makefile for snake_game

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Iinclude -Wall -Wextra -Werror

# Source files
SRCS = $(wildcard src/*.c) main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = snake_game

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean