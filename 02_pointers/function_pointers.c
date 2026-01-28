// TODO: Master function pointers (C's version of callbacks/polymorphism)

#include <stdio.h>

// 1. Declare a function pointer type for: int func(int, int)
//    typedef int (*operation_t)(int, int);

// 2. Implement add, subtract, multiply functions matching that signature

// 3. Implement a calculator that takes a function pointer:
//    int calculate(int a, int b, operation_t op);

// 4. Create an array of function pointers and iterate through them

// 5. EMBEDDED PATTERN: Implement a simple callback registration system
//    - typedef void (*event_callback_t)(int event_id);
//    - void register_callback(event_callback_t cb);
//    - void trigger_event(int event_id);
//    This pattern is EVERYWHERE in embedded (interrupt handlers, event loops)

// 6. Interview question: How would you implement polymorphism in C?
//    Hint: struct with function pointers (vtable pattern)

int main(void) {
    // Your tests here
    return 0;
}
