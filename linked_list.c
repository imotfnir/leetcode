#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

void append_node(Node **head, int value);
void print_list(Node *list);
void reverse_list(Node **head);

struct Node {
    int data;
    Node *next;
};

void append_node(Node **head, int value) {
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *current = *head;

    tail->data = value;
    tail->next = NULL;

    if(head == NULL) {
        printf("a");
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

int main() {
    Node *list_a = NULL;

    list_a = &(Node){ 1, list_a };
    list_a = &(Node){ 2, list_a };
    list_a = &(Node){ 3, list_a };

    append_node(&list_a, 4);
    append_node(&list_a, 5);
    append_node(&list_a, 6);
    print_list(list_a);
    printf("\n");

    reverse_list(&list_a);
    print_list(list_a);
    return 0;
}