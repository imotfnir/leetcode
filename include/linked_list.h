#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct Node Node;

void append_node(Node **head, int value);
void print_list(Node *list);
void reverse_list(Node **head);
Node *new_list(int *data_list, size_t len);
Node *merge_two_list(Node *list1, Node *list2);

struct Node {
    int data;
    Node *next;
};

#endif