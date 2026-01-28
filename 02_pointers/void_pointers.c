// TODO: Understand void pointers (generic programming in C)

#include <stdio.h>
#include <string.h>

// 1. Implement a generic swap function:
//    void swap(void* a, void* b, size_t size);
//    Should work for any type

// 2. Implement a generic print array function:
//    void print_array(void* arr, size_t count, size_t elem_size, 
//                     void (*print_elem)(void*));
//    Provide print functions for int, float, char*

// 3. Why can't you dereference a void pointer directly?
//    What must you do first?

// 4. Implement a simple "any" container:
//    struct Any {
//        void* data;
//        size_t size;
//        // How would you track the type?
//    };

// 5. Interview question: What are the dangers of void pointers?
//    (No type safety, easy to cast incorrectly)

int main(void) {
    int a = 5, b = 10;
    // swap(&a, &b, sizeof(int));
    // printf("a=%d, b=%d\n", a, b);
    return 0;
}
