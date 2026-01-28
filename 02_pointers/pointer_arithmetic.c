// TODO: Master pointer arithmetic

#include <stdio.h>
#include <stdint.h>

// 1. Given int arr[5], explain what each expression evaluates to:
//    - arr
//    - &arr
//    - arr + 1
//    - &arr + 1
//    Key: arr+1 moves by sizeof(int), &arr+1 moves by sizeof(arr)

// 2. Implement strlen using pointer arithmetic only (no indexing)
//    size_t my_strlen(const char* s);

// 3. Implement memcpy using pointer arithmetic
//    void* my_memcpy(void* dest, const void* src, size_t n);

// 4. Given a struct, use pointer arithmetic to access members
//    (This is what offsetof() does internally)

// 5. EMBEDDED PATTERN: Pointer arithmetic for buffer manipulation
//    Implement: void process_packet(uint8_t* buffer, size_t len)
//    - Read a 2-byte header
//    - Skip to payload at offset 4
//    - Process remaining bytes

// 6. What's the difference between these?
//    int* p; p++;      // Moves by sizeof(int)
//    char* c; c++;     // Moves by 1 byte
//    void* v; v++;     // ILLEGAL in standard C (GCC allows as 1 byte)

int main(void) {
    int arr[] = {10, 20, 30, 40, 50};
    printf("arr = %p\n", (void*)arr);
    printf("arr + 1 = %p\n", (void*)(arr + 1));
    printf("&arr + 1 = %p\n", (void*)(&arr + 1));
    return 0;
}
