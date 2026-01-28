// TODO: Master bitwise operations (essential for embedded)

#include <stdio.h>
#include <stdint.h>

// Common operations you MUST know:

// 1. Set a bit:       value |= (1 << bit_pos)
// 2. Clear a bit:     value &= ~(1 << bit_pos)
// 3. Toggle a bit:    value ^= (1 << bit_pos)
// 4. Check a bit:     (value >> bit_pos) & 1  OR  value & (1 << bit_pos)

// TODO: Implement these macros
#define SET_BIT(val, bit)     // Your implementation
#define CLEAR_BIT(val, bit)   // Your implementation  
#define TOGGLE_BIT(val, bit)  // Your implementation
#define CHECK_BIT(val, bit)   // Your implementation

// 5. Extract a bit field: (value >> start) & ((1 << width) - 1)
// TODO: Implement
#define EXTRACT_BITS(val, start, width)  // Your implementation

// 6. Insert a bit field
// TODO: Implement
#define INSERT_BITS(val, start, width, new_val)  // Your implementation

// Practical exercise: Implement a simple flag register
typedef enum {
    FLAG_READY   = (1 << 0),
    FLAG_ERROR   = (1 << 1),
    FLAG_BUSY    = (1 << 2),
    FLAG_TIMEOUT = (1 << 3)
} StatusFlags;

// TODO: Implement
void set_flag(uint8_t* flags, StatusFlags flag);
void clear_flag(uint8_t* flags, StatusFlags flag);
int has_flag(uint8_t flags, StatusFlags flag);

// Interview question: Implement without branching:
// int abs(int x);
// int min(int a, int b);
// int is_power_of_two(unsigned int x);

int main(void) {
    uint8_t status = 0;
    set_flag(&status, FLAG_READY);
    set_flag(&status, FLAG_BUSY);
    printf("Status: 0x%02X\n", status);
    printf("Is ready? %d\n", has_flag(status, FLAG_READY));
    return 0;
}
