// TODO: Understand struct padding and alignment

#include <stdio.h>
#include <stddef.h>  // for offsetof()

// 1. Predict the size of these structs BEFORE running:

struct BadLayout {
    char a;      // 1 byte
    int b;       // 4 bytes
    char c;      // 1 byte
};
// Predicted size: ___  Actual: ___

struct GoodLayout {
    int b;       // 4 bytes
    char a;      // 1 byte
    char c;      // 1 byte
};
// Predicted size: ___  Actual: ___

// 2. Use offsetof() macro to print the offset of each member

// 3. Create a packed struct (compiler-specific):
//    __attribute__((packed)) on GCC
//    Explain when you'd use this (hint: network protocols, file formats)

// 4. Interview question: Why does alignment matter on embedded systems?
//    (Hint: some architectures fault on unaligned access)

int main(void) {
    printf("sizeof(BadLayout): %zu\n", sizeof(struct BadLayout));
    printf("sizeof(GoodLayout): %zu\n", sizeof(struct GoodLayout));
    // Add offsetof prints
    return 0;
}
