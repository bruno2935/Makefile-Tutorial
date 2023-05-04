/**
 * @file test-profile-cmp-list-array.c
 * @author Bruno Alves (bruno.ferreirasg@hotmail.com)
 * @brief The porpose of this file is to make a comparison between linked list and arrray. 
 * Some defines will be used to generate the codes using arrays and linked list
 * @version 0.1
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */

// #define USE_LINKED_LIST // This use the linked functions
// #define WASTE_MEMORY    // This use the array functions

#ifdef USE_LINKED_LIST
#define add_number(v) add_number_ll(v)
#define delete_number(v) delete_number_ll(v)
#else
#ifdef WASTE_MEMORY
#define add_number(v) add_number_array_wasteful(v)
#else
#define add_number(v) add_number_array_reuse()
#endif
#define delete_number(v) delete_number_array(v)
#endif

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/linkedlist.h"

#define AVAILABLE INT_MIN       // To represent a empty slot in the array
#define NOT_FOUND (-1)          // Return value, when can't be found
#define INITIAL_ARRAY_SIZE 100  // Size of the array
#define ARRAY_INCREMENT 1000    // Increment for this amount when we run out of space
#define MAX_VALUE 500000        // Maximum value limit of the array elements
#define NUM_INTERRATIONS 2000   // Loopt that adds and deletes elements for this amaount number of times
#define INSERT_NUM 100          // Each interation we insert this amount of random numbers
#define DELETE_NUM 50           // Each interation we try to delete this amount of random numbers
#define TRAVERSALS 1            // TRAVERSALS: refer to the process of visiting all the nodes of a data structure in a systematic way. It is a fundamental operation performed on various data structures such as trees, graphs, and linked lists. The goal of traversals is to visit every node of the data structure and perform some operations on each node or extract useful information from it.

// Head of my linked list
Node_t *head = NULL;

// The array
int *myvalues = NULL;
int listlength = INITIAL_ARRAY_SIZE;

void add_number_ll(int value) {
    Node_t *newnode = create_new_node(value);
    insert_at_head(&head, newnode);
}

int find_value(int value) {
    for (size_t i = 0; i < listlength; i++) {
        if (myvalues[i] == value) {
            return i;
        }
    }
    return NOT_FOUND;
}

void add_number_array_wasteful(int value) {
    // don't bother reusing memory. Just stick the value
    // at the end.

    static int last_loc = -1;

    last_loc++;
    if (last_loc >= listlength) {
        // Grow the array
        int newlength = listlength + ARRAY_INCREMENT;
        myvalues = (int *)realloc(myvalues, newlength * sizeof(int));
        for (size_t i = listlength; i < newlength; i++) {
            myvalues[i] = AVAILABLE;
        }
        listlength = newlength;
    }
    myvalues[last_loc] = value;
}

void add_number_array_reuse(int value) {
    // is there an empty location int loc = find_value(AVAILABLE);
    int loc = find_value(AVAILABLE);

    if (loc == NOT_FOUND) {
        // grow the array
        int newlength = listlength + ARRAY_INCREMENT;
        myvalues = realloc(myvalues, newlength * sizeof(int));
        myvalues[listlength] = value;  // take the first available slot
        for (int i = listlength + 1; i < newlength; i++) {
            myvalues[i] = AVAILABLE;
        }
        listlength = newlength;
    } else {
        myvalues[loc] = value;
    }

    return;
}

void delete_number_ll(int value) { remove_value(&head, value); }

void delete_number_array(int value) {
    int loc = find_value(value);
    if (loc != NOT_FOUND) {
        myvalues[loc] = AVAILABLE;
    }
}

long double tv_to_seconds(struct timeval *tv) {
    long double result = tv->tv_sec;
    result += ((long double)tv->tv_usec) / 1000000.0;
    return result;
}

int main() {
#ifndef USE_LINKED_LIST
    // initialize array
    myvalues = (int *)malloc(listlength * sizeof(int));
    for (size_t i = 0; i < listlength; i++) {
        myvalues[i] = AVAILABLE;
    }
#endif
    // ! [LEARN THIS] https://www.youtube.com/watch?v=Os5cK0H8EOA&t=0s
    struct rusage myusage;
    getrusage(RUSAGE_SELF, &myusage);
    long baseline_memory = myusage.ru_maxrss;
    long double start_time = tv_to_seconds(&myusage.ru_utime);

    // use the same randon seed, so that the behavior is the same for all.
    srand(0);

    long double last_time = start_time, insert_time = 0.0, delete_time = 0.0;
    long double traversal_time = 0.0;
    for (size_t i = 0; i < NUM_INTERRATIONS; i++) {
        // add 100 numbers
        for (size_t j = 0; j < INSERT_NUM; j++) {
            add_number(rand() % MAX_VALUE);
        }
    }

    for (size_t i = 0; i < NUM_INTERRATIONS; i++) {
        // delete 100 numbers
        for (size_t j = 0; j < DELETE_NUM; j++) {
            delete_number(rand() % MAX_VALUE);
        }
    }

    return 0;
}