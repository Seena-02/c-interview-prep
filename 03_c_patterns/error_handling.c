// TODO: Master C error handling patterns (no exceptions!)

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Pattern 1: Return error code, out parameter for result
//   Returns 0 on success, error code on failure
int parse_int(const char* str, int* out_value)
{
    if (str == NULL || out_value == NULL) return -1;
    if (str[0] == '\0') return -1;
    int result = 0;
    int negative = 1;
    size_t i = 0;
    if (str[0] == '-')
    {
        if (str[1] == '\0') return -1;  // Just "-" with no digits
        negative = -1;
        i++;
    };
    for(; i < strlen(str); ++i)
    {
        if (str[i] < '0' || str[i] > '9') return -1;
        result = result * 10 + (str[i] - '0');
    }
    *out_value = result * negative;

    return 0;
}

// Pattern 2: Return NULL/invalid value on error, set errno
//   void* my_malloc(size_t size);  // Returns NULL on failure
//   FILE* fopen(const char* path, const char* mode);

void* my_malloc(size_t size)
{
    void* allocation = malloc(size);
    if(allocation == NULL) return NULL;
    return allocation;
}

FILE* fopen(const char* path, const char* mode)
{
    if (path == NULL || mode == NULL) return NULL;
    return fopen(path, mode);
}

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



// TODO: Create an error enum for your stack module:
typedef enum {
    STACK_OK = 0,
    STACK_ERR_NULL,
    STACK_ERR_FULL,
    STACK_ERR_EMPTY,
    STACK_ERR_NOMEM
} StackError;

const char* stack_error_string(StackError err)
{
    switch(err)
    {
        case STACK_OK:        return "Success";
        case STACK_ERR_NULL:  return "Null pointer";
        case STACK_ERR_FULL:  return "Stack is full";
        case STACK_ERR_EMPTY: return "Stack is empty";
        case STACK_ERR_NOMEM: return "Memory allocation failed";
        default:              return "Unknown error";
    }
}

// Interview question: Why is goto considered acceptable for cleanup in C?
// (Single exit point, cleaner than nested if/else, Linux kernel style)

int main(void) {
    const char* strs[] = {"-123", "231", "222", "9822"};

    size_t strs_len = sizeof(strs) / sizeof(strs[0]);
    for(size_t i = 0; i < strs_len; ++i)
    {
        int out_value;
        int result = parse_int(strs[i], &out_value);
        if(result == 0)
        {
            printf("'%s' -> %d\n", strs[i], out_value);
        }
        else
        {
            printf("'%s' -> parse failed\n", strs[i]);
        }

    }

    const char* result = stack_error_string(STACK_ERR_EMPTY);
    printf("%s\n", result);
    return 0;
}
