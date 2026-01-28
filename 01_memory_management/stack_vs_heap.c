// TODO: Understand stack vs heap allocation

// 1. Why does this function have undefined behavior?
char* get_greeting(void) {
    char local[] = "Hello";  // Stack allocated
    return local;            // BUG: returning stack address
}

// 2. Fix it two ways:
//    a) Using static (tradeoff: not thread-safe)
//    b) Using heap allocation (tradeoff: caller must free)

// 3. Implement a function that demonstrates:
//    - Stack is faster (no syscall for small allocations)
//    - Stack has limited size (try to cause stack overflow)
//    - Heap persists beyond function scope

// 4. Interview question: When would you choose stack over heap?
//    Write your answer as a comment

int main(void) {
    // Your tests here
    return 0;
}
