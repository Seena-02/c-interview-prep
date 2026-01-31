// TODO: Understand stack vs heap allocation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// 1. Why does this function have undefined behavior?
char* get_greeting(void) {
    //char local[] = "Hello";  // Stack allocated
    char *local = "Hello"; // string literal here (thread safe)
    return local;         // BUG: returning stack address
}

// 2. Fix it two ways:
//    a) Using static (tradeoff: not thread-safe)
//    b) Using heap allocation (tradeoff: caller must free)

// 3. Implement a function that demonstrates:
//    - Stack is faster (no syscall for small allocations)
//    - Stack has limited size (try to cause stack overflow)
//    - Heap persists beyond function scope

void tradeoff()
{
    int i;
    clock_t start, end;

    start = clock();
    for(int i = 0; i < 1000000; ++i)
    {
        char str[11] = "HelloWorld";
    }
    end = clock();
    printf("Stack: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for(int i = 0; i < 1000000; ++i)
    {
        char *str = malloc(11);
        free(str);
    }
    end = clock();
    printf("Heap: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    printf("\nNow we will perform stack overflow...\n");

    //Uncomment to show stack overflow.
    //char hello[10000000];
    //printf("Assume overflow here....");

}

char* CreateStringHeap()
{
    char *str = malloc(sizeof(char) * (strlen("Hello World") + 1));
    if (str == NULL)
    {
        perror("Memory allocation failed");
    }
    strcpy(str, "Hello World");
    return str;
}

// 4. Interview question: When would you choose stack over heap?
//    Write your answer as a comment
// Stack is the default choice in C — it's fast, automatic, and safe from leaks. 
// Use heap only when you need dynamic sizing, large allocations, or data that outlives the function.

int main(void) {
    // Your tests here
    char* result = get_greeting();
    printf("%s\n", result);

    tradeoff();


    char *heap_str = CreateStringHeap();
    printf("Heap String: %s\n", heap_str);
    return 0;
}
