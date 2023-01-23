#include <linked_list.h>

#include <stdio.h>

void append_node(Node **head, int value) {
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *current = *head;

    tail->data = value;
    tail->next = NULL;

    if(head == NULL) {
        *head = tail;
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = tail;

    return;
}

void print_list(Node *list) {
    Node *current = list;

    while(current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }

    return;
}

void reverse_list(Node **head) {
    Node *prev = NULL;
    Node *next = NULL;
    Node *current = *head;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return;
}
