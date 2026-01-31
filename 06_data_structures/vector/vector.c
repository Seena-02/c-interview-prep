#include "vector.h"
#include <stdlib.h> // malloc, realloc, free
#include <stdio.h>  // optional: debugging

#define VECTOR_INITIAL_CAPACITY 4

/* =========================
   Initialization
   ========================= */
void vector_init(Vector *v) {
    // TODO:
    // 1. Set size to 0
    // 2. Set capacity to VECTOR_INITIAL_CAPACITY
    // 3. Allocate memory for data
    v->size = 0;
    v->capacity = VECTOR_INITIAL_CAPACITY;
    v->data = malloc(v->capacity * sizeof(int));

    if (!v->data) {
        v->capacity = 0;
        fprintf(stderr, "Failed to allocate memory\n");
        return;
    }

    return;
}

/* =========================
   Push back
   ========================= */
void vector_push_back(Vector *v, int value) {
    // TODO:
    // 1. Check if size == capacity
    // 2. If so, grow capacity (usually *2)
    // 3. Realloc safely (use temp pointer)
    // 4. Insert value
    // 5. Increment size
    if(v->size == v->capacity)
    {
        size_t new_capacity = v->capacity * 2;
        int *temp = realloc(v->data, new_capacity * sizeof(int));
        if (!temp) {
            // realloc failed, keep old data safe
            fprintf(stderr, "Failed to allocate memory\n");
            return;
        }
        v->data = temp;
        v->capacity = new_capacity;
    }
    v->data[v->size] = value;
    v->size++;
}

/* =========================
   Pop back
   ========================= */
void vector_pop_back(Vector *v) {
    // TODO:
    // 1. Check if vector is empty
    // 2. Decrement size
    // (Optional: shrink capacity)
    if(v->size != 0)
    {
        v->size--;
    }
}

/* =========================
   Get element
   ========================= */
int vector_get(const Vector *v, size_t index) {
    // TODO:
    // 1. Check bounds
    // 2. Return element
    // 3. Decide what to do on error (return sentinel / assert)
    if(v->size <= index)
    {
        fprintf(stderr, "Index out of bounds.\n");
        return -1;
    }
    return v->data[index];
}

/* =========================
   Set element
   ========================= */
void vector_set(Vector *v, size_t index, int value) {
    // TODO:
    // 1. Check bounds
    // 2. Assign value
    if (v->size <= index)
    {
        fprintf(stderr, "Index out of bounds.");
        return;
    }
    v->data[index] = value;
}

/* =========================
   Utility
   ========================= */
int vector_is_empty(const Vector *v) {
    // TODO:
    // return 1 if size == 0 else 0
    if(v->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

size_t vector_size(const Vector *v) {
    // TODO:
    // return size
    return v->size;;
}


/* =========================
   Cleanup
   ========================= */
void vector_free(Vector *v) {
    // TODO:
    // 1. Free data
    // 2. Set data to NULL
    // 3. Reset size and capacity
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void print_vector(const Vector *v)
{
    for(int i = 0; i < v->size; ++i)
    {
        printf("%d ", v->data[i]);
    }
    printf("\n");
}

int main(void)
{
    Vector v;
    vector_init(&v);
    printf("Size: %zu\n", v.size);
    printf("Capacity: %zu\n", v.capacity);
    vector_push_back(&v, 4);
    vector_push_back(&v, 9);
    vector_push_back(&v, 10);
    vector_push_back(&v, 2);
    print_vector(&v);
    printf("Size: %zu\n", v.size);
    printf("Capacity: %zu\n", v.capacity);
    printf("\n");
    vector_push_back(&v, 1);
    print_vector(&v);
    printf("Size: %zu\n", v.size);
    printf("Capacity: %zu\n", v.capacity);
    print_vector(&v);

    printf("Capacity: %zu\n", v.capacity);
    vector_pop_back(&v);
    print_vector(&v);
    printf("\n");

    printf("%s", "Replace index 0 with 100\n");
    vector_set(&v, 0, 100);
    print_vector(&v);

    printf("Element at index 2 is: %d", vector_get(&v, 2));
    printf("\n%s", "Pop Back:\n");
    vector_pop_back(&v);
    print_vector(&v);
    printf("%s", "Vector free\n");
    vector_free(&v);
    

}