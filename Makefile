# C Interview Prep Makefile
# Usage: make <target> or make all

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -g
LDFLAGS = 

# Directory structure
DIRS = 01_memory_management 02_pointers 03_c_patterns 04_embedded_essentials \
       05_preprocessor 06_data_structures 07_networking_basics

# Find all .c files
SOURCES := $(wildcard */*.c) $(wildcard */*/*.c)
TARGETS := $(SOURCES:.c=)

# Default: list available targets
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  make all          - Build all exercises"
	@echo "  make clean        - Remove all binaries"
	@echo "  make <filename>   - Build specific exercise (without .c extension)"
	@echo ""
	@echo "Examples:"
	@echo "  make 01_memory_management/malloc_free_basics"
	@echo "  make 04_embedded_essentials/bitwise_operations"
	@echo ""
	@echo "To run with Valgrind (memory check):"
	@echo "  valgrind --leak-check=full ./01_memory_management/memory_leaks"

.PHONY: all
all: $(TARGETS)

# Generic rule for single-file programs
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

# Opaque pointer example needs both files
03_c_patterns/opaque_test: 03_c_patterns/opaque_pointers/stack.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Header guards example needs main
05_preprocessor/header_test: 05_preprocessor/header_guards/module.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS) -DTEST_MAIN

.PHONY: clean
clean:
	find . -type f -executable -delete 2>/dev/null || true
	rm -f $(TARGETS)

# Additional flags for specific targets
07_networking_basics/%: LDFLAGS += -lpthread

.PHONY: list
list:
	@echo "Source files:"
	@for f in $(SOURCES); do echo "  $$f"; done
