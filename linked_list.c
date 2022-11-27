#include <stdint.h>
#include <stdio.h>

typedef struct node node;

void append_node(node *list, int num);
void print_list(node *list);

struct node {
    int data;
    node *next;
};

void append_node(node *list, int num) {
    node tail = {
        .data = num,
        .next = NULL,
    };

    if(list == NULL) {
        printf("a");
        list = &tail;
    }
    printf("%p", list);

    // while(current->next != NULL) {
    //     current = current->next;
    // }
    // current->next = &tail;

    return;
}

void print_list(node *list) {
    node *current = list;

    while(current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }

    return;
}

int main() {
    node *list_a = NULL;

    // if(list_a == NULL) {
    //     printf("b");
    //     return 0;
    // }

    append_node(list_a, 1);
    append_node(list_a, 2);
    append_node(list_a, 3);
    // append_node(list_a, 4);
    // append_node(list_a, 5);

    printf("%d, ", list_a->data);
    printf("%d, ", list_a->next->data);
    printf("%d, ", list_a->next->next->data);
    printf("%d, ", list_a->next->next->next->data);

    // print_list(list_a);
    return 0;
}