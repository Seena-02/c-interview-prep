#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    size_t size;
} LinkedList;

// Creation/destruction
LinkedList* list_create(void);
void list_destroy(LinkedList* list);

// Basic operations
bool list_prepend(LinkedList* list, int value);  // O(1)
bool list_append(LinkedList* list, int value);   // O(n) - or keep tail pointer
bool list_insert_at(LinkedList* list, size_t index, int value);

// Removal (note: double pointer needed to modify head)
bool list_remove_first(LinkedList* list, int* out_value);
bool list_remove_at(LinkedList* list, size_t index, int* out_value);
bool list_remove_value(LinkedList* list, int value);  // First occurrence

// Access
bool list_get(const LinkedList* list, size_t index, int* out_value);
int list_find(const LinkedList* list, int value);  // Returns index or -1

// Utility
size_t list_size(const LinkedList* list);
bool list_is_empty(const LinkedList* list);
void list_print(const LinkedList* list);

// Interview favorites:
// 1. Reverse a linked list (iterative and recursive)
Node* list_reverse_iterative(Node* head);
Node* list_reverse_recursive(Node* head);

// 2. Detect cycle (Floyd's algorithm)
bool list_has_cycle(Node* head);

// 3. Find middle element (slow/fast pointer)
Node* list_find_middle(Node* head);

// 4. Merge two sorted lists
Node* merge_sorted_lists(Node* l1, Node* l2);


#endif // LINKED_LIST_H