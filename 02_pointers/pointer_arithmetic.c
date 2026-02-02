// TODO: Master pointer arithmetic

#include <stdio.h>
#include <stdint.h>


// 1. Given int arr[5], explain what each expression evaluates to:
//    - arr // Decays to &arr[0]
//    - &arr // Address of whole array (different type)
//    - arr + 1 //0x1004 moves 4 bytes (1 int)
//    - &arr + 1 //0x1014 moves 20 bytes (5 ints)
//    Key: arr+1 moves by sizeof(int), &arr+1 moves by sizeof(arr)



// 2. Implement strlen using pointer arithmetic only (no indexing)
size_t my_strlen(const char* s)
{
    size_t len = 0;
    while(s[len] != '\0')
    {
        len++;
    }
    return len;
}

// 3. Implement memcpy using pointer arithmetic
void* my_memcpy(void* dest, const void* src, size_t n)
{
    char *d = (char*)dest;
    char *s = (char*)src;

    for(size_t i = 0; i < n; ++i)
    {
        d[i] = s[i];
    }

    return dest;
}

// 4. Given a struct, use pointer arithmetic to access members
//    (This is what offsetof() does internally)

typedef struct Person {
    char* name;
    char* address;
    int age;
} Person;


// 5. EMBEDDED PATTERN: Pointer arithmetic for buffer manipulation
//    Implement: void process_packet(uint8_t* buffer, size_t len)
//    - Read a 2-byte header
//    - Skip to payload at offset 4
//    - Process remaining bytes
void process_packet(uint8_t* buffer, size_t len)
{
    uint16_t header = (buffer[1] << 8 | buffer[0]);
    printf("Header: 0x%04x\n", header);

    uint8_t *payload = buffer + 4;
    uint8_t *end = buffer + len;

    while (payload < end)
    {
        printf("%02x ", *payload);
        payload++;
    }
    printf("\n");
}


// 6. What's the difference between these?
//    int* p; p++;      // Moves by sizeof(int)
//    char* c; c++;     // Moves by 1 byte
//    void* v; v++;     // ILLEGAL in standard C (GCC allows as 1 byte)

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    printf("arr = %p\n", (void*)arr);
    printf("arr + 1 = %p\n", (void*)(arr + 1));
    printf("&arr + 1 = %p\n", (void*)(&arr + 1));

    printf("Question 1:\n");
    const char *s = "Seena";
    printf("The length of %s is %zu\n", s, my_strlen(s));

    size_t offset = ((size_t)&((Person*)0)->address);
    Person p = { "Seena", "123 Main St", 24};

    char *base = (char*)&p;

    char **addr_ptr = (char **)(base + offset);
    printf("%s\n", *addr_ptr);  // "123 Main St"

    uint8_t buffer[] = {
        0xAB, 0xCD,             // Header (0xABCD big-endian)
        0x00, 0x00,             // Padding (bytes 2-3)
        0x48, 0x65, 0x6C, 0x6C, // Payload: "Hell"
        0x6F, 0x21              // Payload: "o!"
    };

    size_t len = sizeof(buffer);
    
    process_packet(buffer, len);

    return 0;
}
