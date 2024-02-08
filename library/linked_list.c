#include <linked_list.h>

#include <stdio.h>

void append_node(node **head, int value) {
    node *tail = (node *)malloc(sizeof(node));
    node *current = *head;

    tail->data = value;
    tail->next = NULL;

    if(*head == NULL) {
        *head = tail;
        return;
    }

    while(current->next != NULL) {
        current = current->next;
    }
    current->next = tail;
    return;
}

void print_list(node *list) {
    node *current = list;

    while(current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

void reverse_list(node **head) {
    node *prev = NULL;
    node *next = NULL;
    node *current = *head;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return;
}

node *new_list(int *data_list, size_t len) {
    node *head = NULL;
    for(size_t i = 0; i < len; i++) {
        append_node(&head, data_list[i]);
    }

    return head;
}

node *merge_two_list(node *list1, node *list2) {
    node *head = NULL;
    node *current1 = list1;
    node *current2 = list2;

    if(list1 == NULL) {
        return list2;
    }

    if(list2 == NULL) {
        return list1;
    }

    while((current1 != NULL) || (current2 != NULL)) {
        if(current2 == NULL) {
            append_node(&head, current1->data);
            current1 = current1->next;
            continue;
        }

        if(current1 == NULL) {
            append_node(&head, current2->data);
            current2 = current2->next;
            continue;
        }

        if(current1->data <= current2->data) {
            append_node(&head, current1->data);
            current1 = current1->next;
            continue;
        }

        if(current2->data <= current1->data) {
            append_node(&head, current2->data);
            current2 = current2->next;
            continue;
        }
    }
    return head;
}
