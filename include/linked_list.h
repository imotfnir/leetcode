#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct node node;

void append_node(node **head, int value);
void print_list(node *list);
void reverse_list(node **head);
node *new_list(int *data_list, size_t len);
node *merge_two_list(node *list1, node *list2);

struct node {
    int data;
    node *next;
};

#endif