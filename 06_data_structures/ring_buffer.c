// TODO: Implement a ring buffer (circular buffer)
// THIS IS EXTREMELY COMMON IN EMBEDDED SYSTEMS
// Used for: UART buffers, audio streams, sensor data, logging

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    uint8_t* buffer;
    size_t capacity;    // Must be power of 2 for optimization
    size_t head;        // Write position
    size_t tail;        // Read position
    // Alternative: store count instead of head/tail
} RingBuffer;

// TODO: Implement all functions

RingBuffer* ring_create(size_t capacity);
void ring_destroy(RingBuffer* rb);

// Single byte operations
bool ring_write(RingBuffer* rb, uint8_t byte);
bool ring_read(RingBuffer* rb, uint8_t* out_byte);
bool ring_peek(const RingBuffer* rb, uint8_t* out_byte);

// Bulk operations (for efficiency)
size_t ring_write_bulk(RingBuffer* rb, const uint8_t* data, size_t len);
size_t ring_read_bulk(RingBuffer* rb, uint8_t* out_data, size_t max_len);

// Status
size_t ring_available(const RingBuffer* rb);   // Bytes available to read
size_t ring_free_space(const RingBuffer* rb);  // Bytes available to write
bool ring_is_empty(const RingBuffer* rb);
bool ring_is_full(const RingBuffer* rb);

// Optimization: If capacity is power of 2, use bitwise AND instead of modulo
// head = (head + 1) & (capacity - 1)  instead of  head = (head + 1) % capacity

// IMPORTANT: Full vs Empty detection
// Problem: head == tail could mean full OR empty
// Solutions:
// 1. Waste one slot (full when head+1 == tail)
// 2. Keep separate count variable
// 3. Keep "full" flag

// Interview question: How would you make this thread-safe?
// - For single producer, single consumer: volatile may be enough
// - For multiple: need mutex or lock-free atomic operations

// Advanced: Implement for arbitrary struct, not just uint8_t
// Hint: Store void* and element size, use memcpy

int main(void) {
    RingBuffer* rb = ring_create(16);
    
    // Simulate UART: write some bytes
    const char* msg = "Hello";
    for (int i = 0; msg[i]; i++) {
        ring_write(rb, msg[i]);
    }
    
    // Read them back
    uint8_t byte;
    while (ring_read(rb, &byte)) {
        putchar(byte);
    }
    putchar('\n');
    
    ring_destroy(rb);
    return 0;
}
