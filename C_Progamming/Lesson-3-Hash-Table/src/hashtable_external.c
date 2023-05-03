#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct Person_t {
    char name[MAX_NAME];
    int age;
    //..add other stuff later, maybe
    struct Person_t* next;
} Person_t;

Person_t* hash_table[TABLE_SIZE];

unsigned int hash(char* name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (size_t i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    // Table is empty
}

void print_table() {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t ", i);
            Person_t* tmp = hash_table[i];
            while (tmp != NULL) {
                printf("\t%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("--------------------------\n");
}

bool hash_table_insert(Person_t* p) {
    /*Check if the P is not Null pointer*/
    if (p == NULL) return false;
    /*Index to store de person in the table*/
    int index = hash(p->name);
    p->next = hash_table[index];
    /*Add the person to the front of the list*/
    hash_table[index] = p;

    return true;
}

/**
 * @brief Find a person in the table by their name
 * In this algorithm, there is no loop; we don't search in empty slots.
 * Constant time operation O(1)
 * We search every element for the matching name.
 * @param name
 * @return Person_t*
 */
Person_t* hash_table_lookup(char* name) {
    int index = hash(name);
    Person_t* tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}
/**
 * @brief change to doubly linked list to this algorith be more efficient
 *
 * @param name
 * @return Person_t*
 */
Person_t* hash_table_delete(char* name) {
    int index = hash(name);
    Person_t* tmp = hash_table[index];
    Person_t* prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        // deleting from the head
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

int main() {
    init_hash_table();
    print_table();

    Person_t jacob = {.name = "jacob", .age = 52};
    Person_t mario = {.name = "mario", .age = 27};
    Person_t jessica = {.name = "jessica", .age = 17};
    Person_t robert = {.name = "robert", .age = 22};
    Person_t pedro = {.name = "pedro", .age = 25};
    Person_t marco = {.name = "marco", .age = 37};
    Person_t juarez = {.name = "juarez", .age = 12};
    Person_t silva = {.name = "silva", .age = 77};
    Person_t tristan = {.name = "tristan", .age = 67};

    hash_table_insert(&jacob);
    hash_table_insert(&mario);
    hash_table_insert(&robert);
    hash_table_insert(&jessica);
    hash_table_insert(&pedro);
    hash_table_insert(&marco);
    hash_table_insert(&juarez);
    hash_table_insert(&silva);
    hash_table_insert(&tristan);

    print_table();

    // Person_t* tmp = hash_table_lookup("Msk");
    // printf("Address %p\n", (void*)tmp);

    // tmp = hash_table_lookup("mario");
    // printf("Address %p\n", (void*)tmp);
    // // hash_table_delete("mario");
    // print_table();
    return 0;
}