// TODO: Understand array-to-pointer decay

#include <stdio.h>

// 1. What's the difference between these function signatures?
//    void func1(int arr[10]);
//    void func2(int arr[]);
//    void func3(int* arr);
//    Answer: They're ALL equivalent! The size is ignored.

// 2. How do you pass array size in C?
//    - Separate size parameter (most common)
//    - Sentinel value (like '\0' in strings)
//    - Struct with array and size

// 3. Why does sizeof(arr) work differently inside vs outside functions?
void demonstrate_decay(int arr[]) {
    // sizeof(arr) here is sizeof(int*), NOT sizeof the array
}

// 4. How do you prevent decay? Pass pointer to array:
//    void func(int (*arr)[10]);  // Pointer to array of 10 ints
//    Now sizeof(*arr) is correct

// 5. 2D array parameter gotcha:
//    void process_matrix(int mat[][3], size_t rows);
//    Why can you omit first dimension but not second?

int main(void) {
    int arr[10] = {0};
    printf("sizeof(arr) in main: %zu\n", sizeof(arr));  // 40 on 32-bit
    demonstrate_decay(arr);
    return 0;
}
