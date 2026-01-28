// TODO: Understand endianness (critical for networking/embedded)

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ENDIANNESS: Byte order of multi-byte values in memory
// 
// Big Endian (Network byte order): MSB first
//   0x12345678 stored as: [0x12][0x34][0x56][0x78]
//
// Little Endian (x86, ARM default): LSB first  
//   0x12345678 stored as: [0x78][0x56][0x34][0x12]

// Detect endianness at runtime
int is_little_endian(void) {
    uint16_t val = 0x0001;
    uint8_t* bytes = (uint8_t*)&val;
    return bytes[0] == 0x01;
}

// TODO: Implement byte swap functions
uint16_t swap16(uint16_t val);  // Hint: shift and OR
uint32_t swap32(uint32_t val);

// TODO: Implement host-to-network and network-to-host conversions
// (Network byte order is big endian)
uint16_t htons(uint16_t host);   // host to network short
uint16_t ntohs(uint16_t net);    // network to host short
uint32_t htonl(uint32_t host);   // host to network long
uint32_t ntohl(uint32_t net);    // network to host long

// Better approach: Portable serialization (endian-independent)
void write_uint32_be(uint8_t* buf, uint32_t val) {
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] = val & 0xFF;
}

uint32_t read_uint32_be(const uint8_t* buf) {
    return ((uint32_t)buf[0] << 24) |
           ((uint32_t)buf[1] << 16) |
           ((uint32_t)buf[2] << 8) |
           (uint32_t)buf[3];
}

// TODO: Implement write_uint32_le and read_uint32_le

// Interview question: Why is the portable serialization approach better
// than using byte swaps? (Works regardless of host endianness)

int main(void) {
    printf("System is %s endian\n", 
           is_little_endian() ? "little" : "big");
    
    uint32_t val = 0x12345678;
    uint8_t buf[4];
    write_uint32_be(buf, val);
    printf("BE bytes: %02X %02X %02X %02X\n", 
           buf[0], buf[1], buf[2], buf[3]);
    
    return 0;
}
