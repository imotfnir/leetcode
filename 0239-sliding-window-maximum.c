#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/sliding-window-maximum/
#define MAX_SIZE 100

typedef struct deque deque;
typedef struct deque mono_queue;

struct deque {
    int data[MAX_SIZE];
    int head;
    int tail;
};

void init_deque(deque *d);
bool is_empty(deque *d);
bool is_full(deque *d);
bool is_in_deque(deque *d, int index);
void push_front(deque *d, int x);
void push_back(deque *d, int x);
void pop_front(deque *d);
void pop_back(deque *d);
int front(deque *d);
int back(deque *d);
void push(mono_queue *d, int x);
void pop(mono_queue *d);
void print_deque(deque *d);
int get_max(mono_queue *d);
int *max_sliding_window(int arr[], int arr_len, int window_size);

void init_deque(deque *d) {
    d->head = -1;
    d->tail = -1;
}

bool is_empty(deque *d) {
    return (d->head == -1 && d->tail == -1);
}

bool is_full(deque *d) {
    return (((d->tail + 1) % MAX_SIZE) == d->head);
}

bool is_in_deque(deque *d, int index) {
    if(d->tail >= d->head) {
        if(index < d->head) { return false; }
        if(index > d->tail) { return false; }
        return true;
    } else {
        if(index >= d->head) { return true; }
        if(index <= d->tail) { return true; }
        return false;
    }
}

void push_front(deque *d, int x) {
    if(is_full(d)) {
        fprintf(stderr, "deque is full, can not push");
        return;
    }

    if(is_empty(d)) {
        d->head = 0;
        d->tail = 0;
    } else if(d->head == 0) {
        d->head = MAX_SIZE - 1;
    } else {
        d->head--;
    }

    d->data[d->head] = x;
}

void push_back(deque *d, int x) {
    if(is_full(d)) {
        fprintf(stderr, "deque is full, can not push");
        return;
    }

    if(is_empty(d)) {
        d->head = 0;
        d->tail = 0;
    } else if(d->tail == MAX_SIZE - 1) {
        d->tail = 0;
    } else {
        d->tail++;
    }

    d->data[d->tail] = x;
}
void pop_front(deque *d) {
    if(is_empty(d)) {
        fprintf(stderr, "deque is empty, can not pop");
        return;
    }

    if(d->head == d->tail) {
        d->head = -1;
        d->tail = -1;
        return;
    }
    if(d->head == MAX_SIZE - 1) {
        d->head = 0;
        return;
    }
    d->head++;
    return;
}

void pop_back(deque *d) {
    if(is_empty(d)) {
        fprintf(stderr, "deque is empty, can not pop");
        return;
    }

    if(d->head == d->tail) {
        d->head = -1;
        d->tail = -1;
        return;
    }
    if(d->tail == 0) {
        d->tail = MAX_SIZE - 1;
        return;
    }
    d->tail--;
    return;
}

int front(deque *d) {
    return d->data[d->head];
}
int back(deque *d) {
    return d->data[d->tail];
}

void push(mono_queue *d, int x) {
    while(!is_empty(d) && (x > back(d))) {
        pop_back(d);
    }
    push_back(d, x);
}

void pop(mono_queue *d) {
    pop_front(d);
}

void print_deque(deque *d) {
    int i = d->head;
    while(is_in_deque(d, i)) {
        printf("%d, ", d->data[i]);
        if(i == MAX_SIZE - 1) {
            i = 0;
        } else {
            i++;
        }
    }
}

int get_max(mono_queue *d) {
    return front(d);
}

int *max_sliding_window(int arr[], int arr_len, int window_size) {
    int *result = calloc(arr_len, sizeof(int));

    return result;
}

int main(int argc, char const *argv[]) {
    int nums[8] = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int len = sizeof(nums) / sizeof(int);
    // int *result = NULL;
    deque dq = { 0 };

    init_deque(&dq);

    for(size_t i = 0; i < 8; i++) {
        push(&dq, nums[i]);
    }

    print_deque(&dq);

    // result = max_sliding_window(nums, len, 3);

    // for(size_t i = 0; i < len; i++) {
    //     printf("%d, ", result[i]);
    // }

    // free(result);

    return 0;
}
