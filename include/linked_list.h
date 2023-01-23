#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct Node Node;

void append_node(Node **head, int value);
void print_list(Node *list);
void reverse_list(Node **head);

struct Node {
    int data;
    Node *next;
};

#endif