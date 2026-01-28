// TODO: Find and fix the memory leaks in each function
// Run with: valgrind --leak-check=full ./memory_leaks

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Leak 1: Early return without free
char* process_data(const char* input) {
    // Could also do a check for input before allocating...
    if (input == NULL)
    {
        return NULL;
    }
    char* buffer = malloc(100);
    if (input == NULL) {
        free(buffer); // I added this line to fix this.
        return NULL;  // BUG: buffer leaked
    }
    strcpy(buffer, input);
    return buffer;
}

// Leak 2: Reassignment without free
void update_buffer(void) {
    char* ptr = malloc(50);
    ptr = realloc(ptr, 100);
    //ptr = malloc(100);  // BUG: first allocation leaked
    free(ptr);
}

// Leak 3: Lost pointer in function
void create_and_forget(void) {
    void *ptr = malloc(200);  // BUG: no pointer to free
    free(ptr);
}

// TODO: Fix all leaks and add a main() to test


int main(void)
{
    printf("=== Test 1: process_data ===\n");
    
    // Test with NULL
    char *result1 = process_data(NULL);
    printf("process_data(NULL) = %s\n", result1 == NULL ? "NULL" : result1);
    
    // Test with valid string
    char *result2 = process_data("hello");
    if (result2 != NULL) {
        printf("process_data(\"hello\") = \"%s\"\n", result2);
        free(result2);
        printf("freed result\n");
    }
    
    printf("\n=== Test 2: update_buffer ===\n");
    update_buffer();
    printf("update_buffer completed\n");
    
    printf("\n=== Test 3: create_and_forget ===\n");
    create_and_forget();
    printf("create_and_forget completed\n");
    
    printf("\n=== All tests done ===\n");
    return 0;
}
