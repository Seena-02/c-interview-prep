// TODO: Understand void pointers (generic programming in C)

#include <stdio.h>
#include <string.h>

typedef enum
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING
} Type;

// 1. Implement a generic swap function:
void swap(void *a, void *b, size_t size)
{
    char *pa = (char *)a;
    char *pb = (char *)b;

    for (size_t i = 0; i < size; ++i)
    {
        char temp = pa[i];
        pa[i] = pb[i];
        pb[i] = temp;
    }
}
//    Should work for any type

// 2. Implement a generic print array function:
void print_array(void *arr, size_t count, size_t elem_size, void (*print_elem)(void *))
{
    char *parr = (char *)arr;

    for (int i = 0; i < count; i++)
    {
        print_elem(parr + i * elem_size);
    }
}

void print_int(void *elem)
{
    printf("%d ", *(int *)elem);
}

void print_float(void *elem)
{
    printf("%f ", *(float *)elem);
}

void print_string(void *elem)
{
    printf("%s ", *(char **)elem);
}
//    Provide print functions for int, float, char*

// 3. Why can't you dereference a void pointer directly?
//    What must you do first?
//  You need to cast it first to know how many bytes to read.

// 4. Implement a simple "any" container:
struct Any
{
    void *data;
    size_t size;
    // How would you track the type?
    Type type;
};

// 5. Interview question: What are the dangers of void pointers?
//    (No type safety, easy to cast incorrectly)

int main(void)
{
    int a = 5, b = 10;
    swap(&a, &b, sizeof(int));
    printf("a=%d, b=%d\n", a, b);

    int nums[5] = {1, 2, 3, 4, 5};
    char *strings[] = {"Kooni", "Jendeh", "Jakesh"};
    float floats[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
    print_array(nums, 5, sizeof(int), print_int);
    printf("\n");
    print_array(strings, 3, sizeof(char *), print_string);
    printf("\n");
    print_array(floats, 5, sizeof(float), print_float);
    printf("\n");

    return 0;
}
