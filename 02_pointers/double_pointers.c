// TODO: Master double pointers (very common in C APIs)

#include <stdio.h>
#include <stdlib.h>

// 1. Why do you need double pointers to modify a pointer in a function?
//    Implement: void allocate_array(int** ptr, size_t n);
//    That allocates an array and sets *ptr to point to it

void allocate_array(int **ptr, size_t n)
{
    *ptr = malloc(n * sizeof(int));
}

// 2. Common pattern: Out parameters for allocated memory
//    int create_buffer(char** out_buf, size_t* out_size);
//    Returns 0 on success, fills out_buf and out_size
int create_buffer(char **out_buf, size_t *out_size)
{
    size_t size = 100;

    char *buf = malloc(size);
    if (buf == NULL)
    {
        return 1;
    }
    *out_buf = buf;
    *out_size - size;

    return 0;
}

// 3. Array of strings is char**
//    Implement: void print_strings(char** strings, size_t count);
//    Implement: char** split_string(const char* s, char delim, size_t* count);
void print_strings(char **strings, size_t count)
{
    size_t strings_length = sizeof(strings);
    for (size_t i = 0; i < count; ++i)
    {
        printf("%s\n", strings[i]);
    }
}

char **split_string(const char *s, char delim, size_t *count)
{
    int num_parts = 0;
    int parts = 0;
    int delim_count = 0;

    for(size_t i = 0; i < sizeof(s); ++i)
    {
        if (s[i] == ",")
        {
            delim_count += 1;
        }
        num_parts = delim_count + 1;
    }

    char* str_ptr = malloc(num_parts * sizeof(char*));
    int start = 0;
    int end = 0;
    
    for(size_t i = 0; i < strlen(s); ++i)
    {
        if(s[i] == ",")
        {
            start = i - 1;
            end = start;
        }
        str_ptr[num_parts - 1];
    }

}

// 4. Linked list operations need double pointers to modify head:
//    void prepend(Node** head, int value);
//    void delete_node(Node** head, int value);

// 5. Common embedded pattern - handle-based APIs:
//    typedef struct Device* DeviceHandle;
//    int device_open(DeviceHandle* handle);  // Double pointer!
//    void device_close(DeviceHandle handle);

int main(void)
{
    int *arr = NULL;
    allocate_array(&arr, 10);
    // Use arr...
    free(arr);

    return 0;
}
