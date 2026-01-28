// TODO: Implement protocol serialization/deserialization
// This is CRITICAL for embedded networking

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// Example: Simple IoT protocol message format
// [1 byte: message type]
// [2 bytes: payload length, big endian]
// [4 bytes: sequence number, big endian]
// [N bytes: payload]
// [2 bytes: CRC-16]

typedef enum {
    MSG_HEARTBEAT = 0x01,
    MSG_SENSOR_DATA = 0x02,
    MSG_COMMAND = 0x03,
    MSG_ACK = 0x04
} MessageType;

typedef struct {
    uint8_t type;
    uint16_t payload_length;
    uint32_t sequence;
    uint8_t payload[256];  // Max payload
    uint16_t crc;
} Message;

// TODO: Implement portable serialization (handles endianness)

// Write multi-byte integers in network byte order (big endian)
void write_u16_be(uint8_t* buf, uint16_t val) {
    buf[0] = (val >> 8) & 0xFF;
    buf[1] = val & 0xFF;
}

void write_u32_be(uint8_t* buf, uint32_t val) {
    buf[0] = (val >> 24) & 0xFF;
    buf[1] = (val >> 16) & 0xFF;
    buf[2] = (val >> 8) & 0xFF;
    buf[3] = val & 0xFF;
}

uint16_t read_u16_be(const uint8_t* buf) {
    return ((uint16_t)buf[0] << 8) | buf[1];
}

uint32_t read_u32_be(const uint8_t* buf) {
    return ((uint32_t)buf[0] << 24) | 
           ((uint32_t)buf[1] << 16) |
           ((uint32_t)buf[2] << 8) | 
           buf[3];
}

// TODO: Serialize message to byte buffer
// Returns number of bytes written, or -1 on error
int message_serialize(const Message* msg, uint8_t* buf, size_t buf_size) {
    // Check buffer size
    // Write type (1 byte)
    // Write payload_length (2 bytes, big endian)
    // Write sequence (4 bytes, big endian)
    // Write payload (N bytes)
    // Calculate and write CRC (2 bytes)
    return -1;  // TODO
}

// TODO: Deserialize message from byte buffer
// Returns 0 on success, error code on failure
int message_deserialize(const uint8_t* buf, size_t buf_len, Message* out_msg) {
    // Parse header
    // Validate payload_length fits in buffer
    // Copy payload
    // Verify CRC
    return -1;  // TODO
}

// TODO: Implement CRC-16 (common in embedded protocols)
uint16_t crc16(const uint8_t* data, size_t len) {
    // Simple CRC-16-CCITT or CRC-16-IBM
    return 0;  // TODO
}

// Interview questions:
// 1. Why use big endian for network protocols?
// 2. How do you handle variable-length messages?
// 3. What's the purpose of the CRC?
// 4. How do you handle message framing over a stream (TCP)?

int main(void) {
    Message msg = {
        .type = MSG_SENSOR_DATA,
        .sequence = 42,
        .payload_length = 4,
        .payload = {0x01, 0x02, 0x03, 0x04}
    };
    
    uint8_t buffer[300];
    int len = message_serialize(&msg, buffer, sizeof(buffer));
    
    if (len > 0) {
        printf("Serialized %d bytes:\n", len);
        for (int i = 0; i < len; i++) {
            printf("%02X ", buffer[i]);
        }
        printf("\n");
    }
    
    return 0;
}
