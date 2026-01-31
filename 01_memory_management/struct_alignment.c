// TODO: Understand struct padding and alignment

#include <stdio.h>
#include <stddef.h> // for offsetof()

// 1. Predict the size of these structs BEFORE running:

struct BadLayout
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};
// Predicted size: 11  Actual: 12

struct GoodLayout
{
    int b;  // 4 bytes
    char a; // 1 byte
    char c; // 1 byte
};
// Predicted size: 8  Actual: 8

// 2. Use offsetof() macro to print the offset of each member

// 3. Create a packed struct (compiler-specific):
//    __attribute__((packed)) on GCC
//    Explain when you'd use this (hint: network protocols, file formats)

struct __attribute__((packed)) PackedLayout
{
    char a; // 1 byte
    int b;  // 4 bytes
    char c; // 1 byte
};

// 4. Interview question: Why does alignment matter on embedded systems?
//    RISC architectures (ARM, MIPS) require data to be aligned to its size
//    (e.g., 4-byte int at address divisible by 4). Unaligned access causes
//    a hardware fault/crash — unlike x86 which handles it with a performance penalty.

int main(void)
{
    printf("sizeof(BadLayout): %zu\n", sizeof(struct BadLayout));
    printf("sizeof(GoodLayout): %zu\n", sizeof(struct GoodLayout));
    printf("\n");
    printf("ofssetof(BadLayout) a: %zu\n", offsetof(struct BadLayout, a));
    printf("ofssetof(BadLayout) b: %zu\n", offsetof(struct BadLayout, b));
    printf("ofssetof(BadLayout) c: %zu\n", offsetof(struct BadLayout, c));
    printf("\n");
    printf("offsetof(GoodLayout) a: %zu\n", offsetof(struct GoodLayout, a));
    printf("offsetof(GoodLayout) b: %zu\n", offsetof(struct GoodLayout, b));
    printf("offsetof(GoodLayout) c: %zu\n", offsetof(struct GoodLayout, c));
    printf("\n");

    printf("sizeof(PackedLayout): %zu\n", sizeof(struct PackedLayout));
    printf("\n");
    printf("offsetof(PackedLayout) a: %zu\n", offsetof(struct PackedLayout, a));
    printf("offsetof(PackedLayout) b: %zu\n", offsetof(struct PackedLayout, b));
    printf("offsetof(PackedLayout) c: %zu\n", offsetof(struct PackedLayout, c));

    // Add offsetof prints
    return 0;
}
