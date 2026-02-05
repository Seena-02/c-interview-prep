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
    // TODO
    return false;
}

// Access
bool list_get(const LinkedList *list, size_t index, int *out_value)
{
    // TODO
    return false;
}

int list_find(const LinkedList *list, int value)
{
    // TODO
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
    // TODO
    return NULL;
}

Node *list_reverse_recursive(Node *head)
{
    // TODO
    return NULL;
}

bool list_has_cycle(Node *head)
{
    // TODO
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

int add_two(int x, int y)
{
    return x + y;
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

    printf("\nInserting 3 at index 1...\n");
    list_insert_at(list, 1, 3);
    list_print(list);

    printf("\nRemoving first element...\n");
    int out_value;                       // Fixed: declare as int, not int*
    list_remove_first(list, &out_value); // Fixed: pass address
    list_print(list);
    printf("Removed value: %d\n", out_value);

    printf("\nRemove 4 at index 1...\n");
    list_remove_at(list, 1, &out_value);
    list_print(list);
    printf("Removed value: %d\n", out_value);

    list_destroy(list); // Don't forget cleanup!
}