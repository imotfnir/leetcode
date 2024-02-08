#include <linked_list.h>

#include <stdio.h>

int main() {
    node *list1 = new_list((int[3]){ 1, 2, 3}, 3U);
    node *list2 = new_list((int[5]){ 0, 2, 5, 6, 7 }, 5U);
    node *list3 = NULL;

    print_list(list1);
    print_list(list2);

    list3 = merge_two_list(list1, list2);
    print_list(list3);

    return 0;
}