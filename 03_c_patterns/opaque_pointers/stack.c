// TODO: Implement the stack with opaque pointer pattern

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

// Private struct definition - only visible in this file
struct Stack
{
    int *data;
    size_t capacity;
    size_t top;
};

// TODO: Implement all functions declared in stack.h
Stack *stack_create(size_t capacity)
{
    // Allocate Stack struct
    Stack *stack = malloc(sizeof(Stack));
    if (stack == NULL)
        return NULL;

    // Allocate data array
    stack->data = malloc(sizeof(int) * capacity);
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }
    // Initialize members

    stack->top = 0;
    stack->capacity = capacity;

    // Return pointer (or NULL on failure)
    return stack;
}

void stack_destroy(Stack *s)
{
    // Free data array
    // Free Stack struct
    // Handle NULL input gracefully
    if (s == NULL)
        return;
    free(s->data);
    free(s);
}

bool stack_push(Stack *s, int value)
{
    if (s == NULL)
        return false;

    if (s->top == s->capacity)
    {
        size_t new_capacity = s->capacity * 2;
        int *new_data = realloc(s->data, sizeof(int) * new_capacity);
        if (new_data == NULL)
        {
            return false;
        }
        s->data = new_data;
        s->capacity = new_capacity;
    }

    s->data[s->top++] = value;
    return true;
}

bool stack_pop(Stack *s, int *out_value)
{
    if (s->top == 0)
        return false;
    *out_value = s->data[--s->top];
    return true;
}

bool stack_peek(const Stack *s, int *out_value)
{
    if (s->top == 0)
        return false;
    *out_value = s->data[s->top - 1];
    return true;
}

size_t stack_size(const Stack *s)
{
    return (s->top);
}

bool stack_is_empty(const Stack *s)
{
    if (stack_size(s) == 0)
        return true;
    return false;
}

bool stack_is_full(const Stack *s)
{
    return s->top == s->capacity;
}

void print_stack(const Stack *s)
{
    size_t len_stack = stack_size(s);

    for (size_t i = 0; i < len_stack; ++i)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

void my_print(int value, void *ctx)
{
    printf("%d ", value);
}

// Bonus: Add a stack_for_each function with callback:
void stack_for_each(const Stack *s, void (*callback)(int value, void *ctx), void *ctx)
{
    for (size_t i = 0; i < s->top; ++i)
    {
        callback(s->data[i], ctx);
    }
    printf("\n");
}

int main(void)
{
    Stack *s = stack_create(5);
    printf("Created stack with size %zu.\n", stack_size(s));
    int a = 3, b = 9, c = 2, d = 1, e = 7, f = 4;
    printf("Append %d to top of stack.\n", a);
    stack_push(s, a);
    print_stack(s);

    printf("Append %d to top of stack.\n", b);
    stack_push(s, b);
    print_stack(s);

    printf("Append %d to top of stack.\n", c);
    stack_push(s, c);
    print_stack(s);

    printf("Append %d to top of stack.\n", d);
    stack_push(s, d);
    print_stack(s);

    printf("Append %d to top of stack.\n", e);
    stack_push(s, e);
    print_stack(s);

    int out_value;
    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);

    printf("Append %d to top of stack.\n", f);
    stack_push(s, f);
    print_stack(s);

    bool result = stack_is_full(s);
    printf("Is the stack full?: %s\n", result ? "true" : "false");

    printf("%s", "Printing elements with callack: ");
    stack_for_each(s, my_print, NULL);

    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);
    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);
    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);
    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);
    stack_pop(s, &out_value);
    printf("Popping top of stack... Popped %d.\n", out_value);
    print_stack(s);
    result = stack_is_empty(s);
    printf("Is the stack empty?: %s\n", result ? "true" : "false");
}
