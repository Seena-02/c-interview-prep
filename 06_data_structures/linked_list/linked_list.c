// TODO: Implement a singly linked list in C

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: Implement all functions

// Creation/destruction
LinkedList *list_create(void)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList *list)
{
    if (list == NULL)
        return;

    Node *current = list->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// Basic operations
bool list_prepend(LinkedList *list, int value)
{
    if (list == NULL)
        return false;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = value;
    new_node->next = list->head;

    list->head = new_node;
    list->size++;

    return true;
}

bool list_append(LinkedList *list, int value)
{
    if (list == NULL)
        return false;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = value;
    new_node->next = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
        list->size++;
        return true;
    }

    Node *current = list->head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
    list->size++;

    return true;
}

bool list_insert_at(LinkedList *list, size_t index, int value)
{
    // 4 -> 4 -> 5 -> NULL
    // APPEND # AT 1
    // 4 -> 3 -> 4 -> 5 -> NULL

    if (list == NULL)
        return false;
    if (index > list->size)
        return false;
    Node *previous = NULL;
    Node *current = list->head;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        return false;

    new_node->data = value;

    if (index == 0)
    {
        new_node->next = current;
        list->head = new_node;
        list->size++;
        return true;
    }

    for (size_t i = 0; i < index; ++i)
    {
        previous = current;
        current = current->next;
    }

    previous->next = new_node;
    new_node->next = current;

    list->size++;

    return true;
}

// Removal
bool list_remove_first(LinkedList *list, int *out_value)
{
    if (list == NULL || list->head == NULL)
        return false; // Add this

    Node *previous = NULL;
    Node *current = list->head;

    previous = current;
    current = current->next;

    *out_value = previous->data;

    free(previous);
    list->head = current;
    list->size--;

    return true;
}

bool list_remove_at(LinkedList *list, size_t index, int *out_value)
{
    if (list == NULL || index > list->size)
        return false;

    Node *previous = NULL;
    Node *current = list->head;

    if (index == 0)
    {
        return list_remove_first(list, out_value);
    }

    for (size_t i = 0; i < index; ++i)
    {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    if (current != NULL)
    {
        *out_value = current->data;
    }
    else
    {
        return false;
    }

    free(current);
    list->size--;

    return true;
}

bool list_remove_value(LinkedList *list, int value)
{
    if (list == NULL)
        return false;

    Node *previous = NULL;
    Node *current = list->head;

    while (current != NULL)
    {
        int num = current->data;
        if (num == value)
        {
            if (current == list->head)
            {
                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }

            free(current);
            list->size--;
            return true;
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }
    return false;
}

// Access
bool list_get(const LinkedList *list, size_t index, int *out_value)
{
    if (list == NULL || index >= list->size)
        return false;

    Node *current = list->head;

    for (size_t i = 0; i < index; ++i)
    {
        current = current->next;
    }

    *out_value = current->data;
    return true;
}

int list_find(const LinkedList *list, int value)
{
    if (list == NULL)
        return -1;
    Node *current = list->head;

    size_t index = 0;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

// Utility
size_t list_size(const LinkedList *list)
{
    return list->size;
}

bool list_is_empty(const LinkedList *list)
{
    return list->size == 0;
}

void list_print(const LinkedList *list)
{
    if (list == NULL || list->head == NULL)
    {
        printf("(empty)\n");
        return;
    }

    Node *current = list->head;
    while (current != NULL)
    {
        int value = current->data;
        printf("%d", value);

        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL");
    printf("\n");
}

// Interview favorites
Node *list_reverse_iterative(Node *head)
{
    Node *previous = NULL;
    Node *current = head;

    while (current != NULL)
    {
        Node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

Node *list_reverse_recursive(Node *head)
{
    // TODO
    return NULL;
}

bool list_has_cycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

Node *list_find_middle(Node *head)
{
    // TODO
    return NULL;
}

Node *merge_sorted_lists(Node *l1, Node *l2)
{
    // TODO
    return NULL;
}

int main(void)
{
    LinkedList *list = list_create();

    printf("Prepending 4...\n");
    list_prepend(list, 4);
    list_print(list);

    printf("Prepending 4...\n");
    list_prepend(list, 4);
    list_print(list);

    printf("\nAppending 5...\n");
    list_append(list, 5);
    list_print(list);

    printf("\nAppending 2...\n");
    list_append(list, 2);
    list_print(list);

    printf("\nAppending 9...\n");
    list_append(list, 9);
    list_print(list);

    printf("\nAppending 8...\n");
    list_append(list, 8);
    list_print(list);

    printf("\nAppending 7...\n");
    list_append(list, 7);
    list_print(list);

    printf("\nInserting 3 at index 1...\n");
    list_insert_at(list, 1, 3);
    list_print(list);

    printf("\nRemoving first element...\n");
    int out_value;
    list_remove_first(list, &out_value);
    list_print(list);
    printf("Removed value: %d\n", out_value);

    printf("\nRemove 4 at index 1...\n");
    list_remove_at(list, 1, &out_value);
    list_print(list);
    printf("Removed value: %d\n", out_value);

    printf("\nRemove value 3 in linked list...\n");
    list_remove_value(list, 3);
    list_print(list);

    printf("\nRemove value 9 in linked list...\n");
    list_remove_value(list, 9);
    list_print(list);

    // Additional test cases
    printf("\n=== Additional Tests ===\n");

    printf("\nTest list_get - getting value at index 2...\n");
    int get_value;
    if (list_get(list, 2, &get_value))
    {
        printf("Value at index 2: %d\n", get_value);
    }
    else
    {
        printf("Failed to get value at index 2\n");
    }

    printf("\nTest list_find - finding value 8...\n");
    int find_index = list_find(list, 8);
    if (find_index != -1)
    {
        printf("Found 8 at index: %d\n", find_index);
    }
    else
    {
        printf("Value 8 not found\n");
    }

    printf("\nTest list_find - finding non-existent value 99...\n");
    find_index = list_find(list, 99);
    if (find_index != -1)
    {
        printf("Found 99 at index: %d\n", find_index);
    }
    else
    {
        printf("Value 99 not found (expected)\n");
    }

    printf("\nTest list_size...\n");
    printf("Current list size: %zu\n", list_size(list));

    printf("\nTest list_is_empty...\n");
    printf("Is list empty? %s\n", list_is_empty(list) ? "Yes" : "No");

    printf("\nTest insert at end (index == size)...\n");
    list_insert_at(list, list_size(list), 100);
    list_print(list);

    printf("\nTest insert at beginning (index 0)...\n");
    list_insert_at(list, 0, 1);
    list_print(list);

    printf("\nTest remove_at last element...\n");
    list_remove_at(list, list_size(list) - 1, &out_value);
    list_print(list);
    printf("Removed value: %d\n", out_value);

    printf("\nRemoving all elements one by one...\n");
    while (!list_is_empty(list))
    {
        list_remove_first(list, &out_value);
        printf("Removed: %d, remaining list: ", out_value);
        list_print(list);
    }

    printf("\nTest operations on empty list...\n");
    printf("Is list empty? %s\n", list_is_empty(list) ? "Yes" : "No");
    printf("Attempting to remove from empty list: %s\n",
           list_remove_first(list, &out_value) ? "Success" : "Failed (expected)");
    printf("Attempting to get from empty list: %s\n",
           list_get(list, 0, &get_value) ? "Success" : "Failed (expected)");

    printf("\nTest rebuild list and check bounds...\n");
    list_append(list, 10);
    list_append(list, 20);
    list_append(list, 30);
    list_print(list);

    printf("Attempting to get out of bounds (index 10): %s\n",
           list_get(list, 10, &get_value) ? "Success" : "Failed (expected)");
    printf("Attempting to insert out of bounds (index 10): %s\n",
           list_insert_at(list, 10, 999) ? "Success" : "Failed (expected)");

    list_destroy(list);
    printf("\nAll tests completed!\n");

    return 0;
}