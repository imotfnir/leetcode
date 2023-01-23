#include <linked_list.h>

#include <stdio.h>

int main() {
    Node* list1=new_list((int[5]){ 1, 2, 3, 2, 0 }, 5U);
    print_list(list1);

    return 0;
}