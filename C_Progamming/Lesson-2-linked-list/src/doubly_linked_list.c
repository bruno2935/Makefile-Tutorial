#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Struct that define my list element
 *
 */
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node_t;

/**
 * @brief Prints all elements in the list
 * As each element is read, the address of the next element in the list is stored in
 * a temporary variable
 * @param head
 */
void printlist(Node_t *head) {
    Node_t *temporary = head;

    while (temporary != NULL) {
        printf(" Prev[%p] - Current:[%p] - Next[%p] -- Val: %d \n ", temporary->prev, temporary, temporary->next, temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

Node_t *create_new_node(int value) {
    Node_t *result = malloc(sizeof(Node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

/**
 * @brief Insert new element in to the head
 *
 * @param head
 * @param node_to_insert
 * @return Node_t*
 */
void insert_at_head(Node_t **head, Node_t *node_to_insert) {
    /*The new element.next element has to point to the element that head points to*/
    node_to_insert->next = *head;
    /**If the head points to a null element (a list), we need to update the prev
     *of the head to point to the new node. This is because the old pointer pointed to the first element, and this element has prev = null.
     *but now it has to point to the first new element.
     */
    if (*head != NULL) {
        (*head)->prev = node_to_insert;
    }
    /*Update the new head to point to the new node address*/
    *head = node_to_insert;
    /*Set the new node prev to null because its the first element*/
    node_to_insert->prev = NULL;
}

/**
 * @brief Search for the value in the list and then then return its address
 *
 * @param head
 * @param value
 * @return Node_t*
 */
Node_t *find_node(Node_t *head, int value) {
    Node_t *tmp = head;
    while (tmp != NULL) {
        if (tmp->value == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

/**
 * @brief Insert a new node after node_to_insert_after
 *  save the value
 * @param node_to_insert_after
 * @param newnode
 */
/* [NULL][N1][N] - [P][N2][N] - [P][N3][N] - [P][N4][NULL] */
void insert_after_node(Node_t *node_to_insert_after, Node_t *newnode) {
    /* [NULL][B][NULL] */
    /* [NULL][B][N2.N] */
    newnode->next = node_to_insert_after->next;
    /* [NULL][B][N2.N] */
    /* Update prev pointer of the node after new_node, if it exists*/
    if (newnode->next != NULL) {
        /*[B][N3][N]*/
        (newnode->next)->prev = newnode;
    }
    newnode->prev = node_to_insert_after;
    node_to_insert_after->next = newnode;
}

/**
 * @brief Remove a node from the doubly linked list
 *
 * @param head
 * @param node_to_remove
 */
void remove_node(Node_t **head, Node_t *node_to_remove) {
    /*Check if we are  remove the head of the list*/
    if (*head == node_to_remove) {
        /*If is the head, then change the head to the next element that it's pointed*/
        *head = node_to_remove->next;
        /*If the list is not empty, we need to set the new head prev to NULL, because it already point to the old node that we remove*/
        if (*head != NULL) {
            (*head)->prev = NULL;
        }

    } else {
        /*Here, we simply remove the node in case we aren't dealing with the head*/
        (node_to_remove->prev)->next = node_to_remove->next;
        if (node_to_remove->next != NULL) {
            (node_to_remove->next)->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
}

/*
 * [N1]{&N2} - [N2]{&N3} - [N3]{NULL}
 */
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