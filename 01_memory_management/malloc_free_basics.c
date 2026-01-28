#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Implement the following exercises

// 1. Create a dynamic array that:
//    - Allocates memory for n integers
//    - Fills it with values 0 to n-1
//    - Prints all values
//    - Properly frees memory
//    Key: Check malloc return value for NULL

// 2. Implement a simple string duplicate function:
//    char* my_strdup(const char* src);
//    Key: strlen + malloc + strcpy, caller must free

// 3. Create a 2D array dynamically (array of pointers to arrays)
//    Key: Need to free in reverse order of allocation

int allocate_array(void)
{
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("allocate_array: malloc failed\n");
        return -1;
    }
    printf("allocate_array: allocated %d ints\n", n);

    for(int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }

    printf("allocate_array: values = ");
    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    printf("allocate_array: memory freed successfully\n");
    return 0;
}

char* my_strdup(const char* src)
{
    size_t len = strlen(src);
    char *copy = (char *)malloc(len + 1);

    if (copy == NULL)
    {
        printf("my_strdup: malloc failed\n");
        return NULL;
    }

    strcpy(copy, src);
    printf("my_strdup: duplicated \"%s\" (len=%zu)\n", copy, len);
    return copy;
}

int** create_2d_array(int rows, int cols)
{
    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("create_2d_array: outer malloc failed\n");
        return NULL;
    }
    printf("create_2d_array: allocated outer array (%d pointers)\n", rows);

    for(int i = 0; i < rows; ++i)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("create_2d_array: row %d malloc failed, cleaning up\n", i);
            for (int j = 0; j < i; ++j)
            {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }

    printf("create_2d_array: allocated %dx%d array successfully\n", rows, cols);
    return arr;
}

void free_2d_array(int **arr, int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        free(arr[i]);
    }
    free(arr);
    printf("free_2d_array: freed %d rows + outer array\n", rows);
}

int main(void)
{
    printf("=== Exercise 1: Dynamic Array ===\n");
    if (allocate_array() != 0)
    {
        printf("main: allocate_array failed\n");
        return 1;
    }

    printf("\n=== Exercise 2: String Duplicate ===\n");
    const char *original = "hello";
    char *duplicate = my_strdup(original);
    if (duplicate == NULL)
    {
        printf("main: my_strdup failed\n");
        return 1;
    }
    printf("main: duplicate = \"%s\"\n", duplicate);
    free(duplicate);
    printf("main: duplicate freed\n");

    printf("\n=== Exercise 3: 2D Array ===\n");
    int **arr = create_2d_array(5, 5);
    if (arr == NULL)
    {
        printf("main: create_2d_array failed\n");
        return 1;
    }
    free_2d_array(arr, 5);

    printf("\n=== All exercises completed successfully ===\n");
    return 0;
}