// TODO: Master preprocessor macros (used heavily in C)

#include <stdio.h>

// Basic macros
#define PI 3.14159
#define MAX_BUFFER_SIZE 1024

// Function-like macros (be careful with these!)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))

// Why all the parentheses? Without them:
// SQUARE(1+2) would become 1+2*1+2 = 5, not 9

// Stringification: # converts argument to string
#define STRINGIFY(x) #x
#define TO_STRING(x) STRINGIFY(x)

// Token pasting: ## concatenates tokens
#define DECLARE_PAIR(type) \
    typedef struct { type first; type second; } type##_pair

// Multi-line macros use backslash
#define LOG(fmt, ...) \
    do { \
        printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
    } while(0)

// Why do-while(0)? Allows macro to work in if/else without braces

// TODO: Implement these common macros:
// 1. ARRAY_SIZE(arr) - get array element count
// 2. CONTAINER_OF(ptr, type, member) - get struct from member pointer
// 3. ASSERT(condition) - custom assert with file/line info
// 4. STATIC_ASSERT(expr, msg) - compile-time assertion

// Useful predefined macros:
// __FILE__, __LINE__, __func__, __DATE__, __TIME__

// Interview questions:
// 1. Why prefer inline functions over macros in modern C?
// 2. When are macros still necessary? (Conditional compilation, stringification)
// 3. What's wrong with: #define DOUBLE(x) x + x

int main(void) {
    int a = 5, b = 10;
    printf("Max: %d\n", MAX(a, b));
    
    // Gotcha: side effects evaluated multiple times
    // printf("Max: %d\n", MAX(a++, b++));  // UNDEFINED!
    
    LOG("Testing %d", 42);
    
    return 0;
}
