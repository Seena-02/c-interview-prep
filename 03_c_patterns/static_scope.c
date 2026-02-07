// TODO: Understand static keyword in C (different from C++!)

#include <stdio.h>

// 1. Static local variable - persists across function calls
int counter(void)
{
    static int count = 0; // Initialized once, persists
    return ++count;
}

// 2. Static global variable - file scope only (internal linkage)
static int module_state = 0; // Can't be accessed from other .c files

// 3. Static function - file scope only (like private in C++)
static void helper_function(void)
{

}

// TODO: Create a simple module demonstrating encapsulation:
// - Static global for state
// - Static helper functions
// - Public functions (non-static) as the API

// Example: Simple ID generator module
static int next_id = 1;
static int validate_id(int id)
{
    if (id < 0 || 100 < id) return -1;
    else return 0;
}

int generate_id(void)
{
    if (validate_id(next_id) != 0) return -1;
    return next_id++;
}

int is_valid_id(int id)
{
    return validate_id(id);
}


// Interview question: What's the difference between:
// static int x;     // File scope, internal linkage, zero-initialized
// int x;            // File scope, external linkage, zero-initialized
// void f() { static int x; }  // Block scope, static storage duration

// C++ difference: In C++, static also has class member meaning

int main(void)
{
    printf("%d\n", counter()); // 1
    printf("%d\n", counter()); // 2
    printf("%d\n", counter()); // 3

    const int id = generate_id();
    int result = is_valid_id(id);

    if (result == 0)
    {
        printf("\nValid ID!\n");
    }
    else
    {
        printf("\nInvalid ID!\n");
    }

    return 0;
}
