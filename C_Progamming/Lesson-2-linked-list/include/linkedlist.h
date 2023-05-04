/**
 * @file linkedlist.h
 * @author Bruno Alves (bruno.ferreirasg@hotmail.com)
 * @brief
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node_t;

void printlist(Node_t *head);
Node_t *create_new_node(int value);
void insert_at_head(Node_t **head, Node_t *node_to_insert);
Node_t *find_node(Node_t *head, int value);
void insert_after_node(Node_t *node_to_insert_after, Node_t *newnode);
void remove_node(Node_t **head, Node_t *node_to_remove);

#endif