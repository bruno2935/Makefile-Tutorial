#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Struct that define my list element
 *
 */
typedef struct Node {
    int value;
    struct Node *next;
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
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

Node_t *create_new_node(int value) {
    Node_t *result = malloc(sizeof(Node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

/**
 * @brief Insert new element in to the head
 * the new element [next] will have to point to the head
 * Then, the Head will be update with new element address
 * @param head
 * @param node_to_insert
 * @return Node_t*
 */
void insert_at_head(Node_t **head, Node_t *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
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

    tmp = find_node(head, 13);
    printf("Found node with value %p\n", (void *)tmp);

    printlist(head);

    return 0;
}