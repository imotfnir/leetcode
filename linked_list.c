#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

void append_node(Node **list, int num);
void print_list(Node *list);

struct Node {
    int data;
    Node *next;
};

void append_node(Node **list, int num) {
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *current = *list;

    tail->data = num;
    tail->next = NULL;

    if(list == NULL) {
        printf("a");
        *list = tail;
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

int main() {
    Node *list_a = NULL;

    list_a = &(Node){ 2, list_a };
    list_a = &(Node){ 3, list_a };
    list_a = &(Node){ 4, list_a };

    append_node(&list_a, 1);
    append_node(&list_a, 2);
    append_node(&list_a, 3);

    print_list(list_a);
    return 0;
}