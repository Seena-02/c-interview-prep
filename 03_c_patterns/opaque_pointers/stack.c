// TODO: Implement the stack with opaque pointer pattern

#include "stack.h"
#include <stdlib.h>

// Private struct definition - only visible in this file
struct Stack {
    int* data;
    size_t capacity;
    size_t top;
};

// TODO: Implement all functions declared in stack.h

Stack* stack_create(size_t capacity) {
    // Allocate Stack struct
    // Allocate data array
    // Initialize members
    // Return pointer (or NULL on failure)
    return NULL;
}

void stack_destroy(Stack* s) {
    // Free data array
    // Free Stack struct
    // Handle NULL input gracefully
}

// ... implement remaining functions

// Bonus: Add a stack_for_each function with callback:
// void stack_for_each(const Stack* s, void (*callback)(int value, void* ctx), void* ctx);
