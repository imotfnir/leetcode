#include <linked_list.h>

#include <stdio.h>

void append_node(Node **head, int value) {
    Node *tail = (Node *)malloc(sizeof(Node));
    Node *current = *head;

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

void print_list(Node *list) {
    Node *current = list;

    while(current != NULL) {
        printf("%d, ", current->data);
        current = current->next;
    }
    printf("\n");
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

Node *new_list(int *data_list, size_t len) {
    Node *head = NULL;
    for(size_t i = 0; i < len; i++) {
        append_node(&head, data_list[i]);
    }

    return head;
}

Node *merge_two_list(Node *list1, Node *list2) {
    Node *head = NULL;
    Node *current1 = list1;
    Node *current2 = list2;

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
