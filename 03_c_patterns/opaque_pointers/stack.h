// TODO: Implement opaque pointer pattern (C's encapsulation)

#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

// Opaque type - user can't see internals
// Definition is in stack.c only
typedef struct Stack Stack;

// Public API - user only works through these functions
Stack* stack_create(size_t capacity);
void stack_destroy(Stack* s);

bool stack_push(Stack* s, int value);
bool stack_pop(Stack* s, int* out_value);
bool stack_peek(const Stack* s, int* out_value);

size_t stack_size(const Stack* s);
bool stack_is_empty(const Stack* s);
bool stack_is_full(const Stack* s);

#endif // STACK_H

// Interview question: What are the benefits of opaque pointers?
// 1. Implementation hiding (can change internals without breaking API)
// 2. Forces heap allocation (pointer is always same size)
// 3. No header dependencies on implementation details
// 4. Clear ownership semantics (create/destroy pair)
