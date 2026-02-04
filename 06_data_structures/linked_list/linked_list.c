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
    // TODO
    return false;
}

// Removal
bool list_remove_first(LinkedList *list, int *out_value)
{
    // TODO
    return false;
}

bool list_remove_at(LinkedList *list, size_t index, int *out_value)
{
    // TODO
    return false;
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
    // TODO
    return 0;
}

bool list_is_empty(const LinkedList *list)
{
    // TODO
    return true;
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
    printf("-> NULL");
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

int main(void)
{
    LinkedList *list = list_create();
    list_prepend(list, 4);
    list_prepend(list, 4);
    list_print(list);
    list_append(list, 5);
    list_print(list);
}