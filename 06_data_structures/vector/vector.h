#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h> // for size_t

/* =========================
   Vector data structure
   ========================= */
typedef struct {
    int *data;          // pointer to heap memory
    size_t size;        // number of elements currently stored
    size_t capacity;    // total allocated capacity
} Vector;

/* =========================
   Core API
   ========================= */

// Initialize vector
void vector_init(Vector *v);

// Add element to end
void vector_push_back(Vector *v, int value);

// Remove last element
void vector_pop_back(Vector *v);

// Get element at index (with bounds checking)
int vector_get(const Vector *v, size_t index);

// Set element at index
void vector_set(Vector *v, size_t index, int value);

// Free all allocated memory
void vector_free(Vector *v);

/* =========================
   Utility
   ========================= */

// Returns 1 if empty, 0 otherwise
int vector_is_empty(const Vector *v);

// Returns current size
size_t vector_size(const Vector *v);

void print_vector(const Vector *v);

#endif // VECTOR_H
