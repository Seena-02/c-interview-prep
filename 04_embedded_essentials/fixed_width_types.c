// TODO: Understand fixed-width types (portable embedded code)

#include <stdio.h>
#include <stdint.h>   // Fixed-width types
#include <inttypes.h> // Printf format macros
#include <stdbool.h>  // bool type (C99)

// PROBLEM: int, long, etc. sizes vary by platform
// - int is 16-bit on some embedded, 32-bit on desktop
// - long is 32-bit on 32-bit systems, 64-bit on 64-bit Linux

// SOLUTION: Fixed-width types from <stdint.h>
// Exact width (guaranteed size):
//   int8_t, int16_t, int32_t, int64_t
//   uint8_t, uint16_t, uint32_t, uint64_t

// Minimum width (at least N bits, may be larger):
//   int_least8_t, int_least16_t, etc.

// Fastest with at least N bits:
//   int_fast8_t, int_fast16_t, etc.

// Pointer-sized integer:
//   intptr_t, uintptr_t

// TODO: Implement a portable struct for a sensor reading
typedef struct {
    uint32_t timestamp_ms;
    int16_t  temperature;    // 0.01 degree units
    uint16_t humidity;       // 0.01 % units
    uint8_t  sensor_id;
    uint8_t  status_flags;
} SensorReading;

// Printf format macros from <inttypes.h>
void print_reading(const SensorReading* r) {
    // PRIu32, PRIx16, etc. are portable format specifiers
    printf("Time: %" PRIu32 " ms\n", r->timestamp_ms);
    printf("Temp: %" PRId16 "\n", r->temperature);
}

// TODO: Implement functions to:
// 1. Initialize a SensorReading
// 2. Serialize to byte array (consider endianness!)
// 3. Deserialize from byte array

// Interview question: What's the difference between size_t and uint32_t?
// (size_t is platform's native size for sizes, may be 32 or 64 bit)

int main(void) {
    printf("sizeof(int): %zu\n", sizeof(int));
    printf("sizeof(int32_t): %zu\n", sizeof(int32_t));
    printf("sizeof(size_t): %zu\n", sizeof(size_t));
    printf("sizeof(intptr_t): %zu\n", sizeof(intptr_t));
    return 0;
}
