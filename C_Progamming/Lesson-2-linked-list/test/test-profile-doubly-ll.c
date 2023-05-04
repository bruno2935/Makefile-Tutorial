#include <stdio.h>
#include <stdlib.h>

#include "../include/linkedlist.h"

int main() {
    Node_t *head = NULL;
    Node_t *tmp;

    /*
     * Each new element is add to the front of the list
     */
    for (size_t i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }

    tmp = find_node(head, 15);
    insert_after_node(tmp, create_new_node(99));
    printlist(head);
    remove_node(&head, find_node(head, 2));
    printlist(head);
    return 0;
}