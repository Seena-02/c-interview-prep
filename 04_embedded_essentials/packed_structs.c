// TODO: Understand packed structs and memory-mapped I/O

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Packed struct - no padding, members at exact offsets
// USE CASES: Network protocols, file formats, hardware registers

// GCC/Clang syntax:
struct __attribute__((packed)) NetworkHeader {
    uint8_t  version;      // Offset 0
    uint8_t  type;         // Offset 1
    uint16_t length;       // Offset 2 (would normally be at 2 anyway)
    uint32_t sequence;     // Offset 4 (would normally be at 4 anyway)
    uint8_t  flags;        // Offset 8
    uint32_t checksum;     // Offset 9 (UNALIGNED without packing!)
};

// TODO: Verify size is 13, not 16 (padded) or more

// Memory-mapped I/O pattern
// Imagine this is a UART peripheral register block
struct __attribute__((packed)) UART_Regs {
    volatile uint32_t DATA;      // 0x00: Data register
    volatile uint32_t STATUS;    // 0x04: Status register
    volatile uint32_t CONTROL;   // 0x08: Control register
    volatile uint32_t BAUDRATE;  // 0x0C: Baud rate register
};

// #define UART0 ((struct UART_Regs*)0x40000000)
// Usage: UART0->DATA = 'A';

// TODO: Implement packet serialization
// void serialize_header(const struct NetworkHeader* h, uint8_t* buffer);
// void deserialize_header(const uint8_t* buffer, struct NetworkHeader* h);

// WARNING: Packed structs have gotchas:
// 1. Unaligned access may be slow or cause faults on some architectures
// 2. Taking address of packed struct member is dangerous
// 3. Not portable between compilers

// Interview questions:
// 1. When would you NOT want to use packed structs?
// 2. How do you handle endianness with packed structs?
// 3. What's the alternative to packed structs? (Manual byte packing)

int main(void) {
    printf("sizeof(NetworkHeader): %zu\n", sizeof(struct NetworkHeader));
    return 0;
}
