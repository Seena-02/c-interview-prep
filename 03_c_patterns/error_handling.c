// TODO: Master C error handling patterns (no exceptions!)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Pattern 1: Return error code, out parameter for result
//   int parse_int(const char* str, int* out_value);
//   Returns 0 on success, error code on failure

// Pattern 2: Return NULL/invalid value on error, set errno
//   void* my_malloc(size_t size);  // Returns NULL on failure
//   FILE* fopen(const char* path, const char* mode);

// Pattern 3: Goto cleanup (VERY common in Linux kernel, embedded)
int process_file(const char* path) {
    int result = -1;
    FILE* f = NULL;
    char* buffer = NULL;

    f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Failed to open: %s\n", strerror(errno));
        goto cleanup;
    }

    buffer = malloc(1024);
    if (!buffer) {
        goto cleanup;
    }

    // Do work...
    result = 0;  // Success

cleanup:
    free(buffer);  // free(NULL) is safe
    if (f) fclose(f);
    return result;
}

// TODO: Implement a function using each pattern

// TODO: Create an error enum for your stack module:
// typedef enum {
//     STACK_OK = 0,
//     STACK_ERR_NULL,
//     STACK_ERR_FULL,
//     STACK_ERR_EMPTY,
//     STACK_ERR_NOMEM
// } StackError;
// const char* stack_error_string(StackError err);

// Interview question: Why is goto considered acceptable for cleanup in C?
// (Single exit point, cleaner than nested if/else, Linux kernel style)

int main(void) {
    return 0;
}
