// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_NAME 256
// #define TABLE_SIZE 10
// /**
//  * @brief Used to inform users when a node was deleted. Then, there is no node after that.
//  *
//  */
// #define DELETED_NODE (Person_t*)(0xFFFFFFFFFFFFFFFFUL)

// typedef struct Person {
//     char name[MAX_NAME];
//     int age;
//     //..add other stuff later, maybe
// } Person_t;

// Person_t* hash_table[TABLE_SIZE];

// unsigned int hash(char* name) {
//     int length = strnlen(name, MAX_NAME);
//     unsigned int hash_value = 0;
//     for (size_t i = 0; i < length; i++) {
//         hash_value += name[i];
//         hash_value = (hash_value * name[i]) % TABLE_SIZE;
//     }
//     return hash_value;
// }

// void init_hash_table() {
//     for (size_t i = 0; i < TABLE_SIZE; i++) {
//         hash_table[i] = NULL;
//     }
//     // Table is empty
// }

// void print_table() {
//     for (size_t i = 0; i < TABLE_SIZE; i++) {
//         if (hash_table[i] == NULL) {
//             printf("\t%i\t---\n", i);
//         } else if (hash_table[i] == DELETED_NODE) {
//             printf("\t%i\t---<deleted>\n", i);
//         } else {
//             printf("\t%i\t%s\n", i, hash_table[i]->name);
//         }
//     }
//     printf("--------------------------\n");
// }

// bool hash_table_insert(Person_t* p) {
//     /*Check if the P is not Null pointer*/
//     if (p == NULL) return false;
//     /*Index to store de person in the table*/
//     int index = hash(p->name);
//     /*Search in the entire array of a available space*/
//     /*Open Addressing Method*/
//     for (size_t i = 0; i < TABLE_SIZE; i++) {
//         int try = (i + index) % TABLE_SIZE;
//         if ((hash_table[try] == NULL) || hash_table[try] == DELETED_NODE) {
//             hash_table[try] = p;
//             return true;
//         }
//     }
//     return false;
// }

// /**
//  * @brief Find a person in the table by their name
//  * In this algorithm, there is no loop; we don't search in empty slots.
//  * Constant time operation O(1)
//  * We search every element for the matching name.
//  * @param name
//  * @return Person_t*
//  */
// Person_t* hash_table_lookup(char* name) {
//     int index = hash(name);

//     for (size_t i = 0; i < TABLE_SIZE; i++) {
//         int try = (index + i) % TABLE_SIZE;
//         // In case we don't find the element. In the first interration, with null, we know that there is no element in the table.
//         if (hash_table[try] == NULL) return NULL;  // Not here
//         if (hash_table[try] == DELETED_NODE) continue;
//         if ((hash_table[try] != NULL) && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
//             return hash_table[try];
//         }
//     }
//     return NULL;
// }

// Person_t* hash_table_delete(char* name) {
//     int index = hash(name);

//     for (size_t i = 0; i < TABLE_SIZE; i++) {
//         int try = (index + i) % TABLE_SIZE;
//         if (hash_table[try] == NULL) return NULL;  // Not here
//         if (hash_table[try] == DELETED_NODE) continue;
//         if ((hash_table[try] != NULL) && strncmp(hash_table[try]->name, name, TABLE_SIZE) == 0) {
//             /*In case we dynamically allocate(In the Heap), we need to free this later.*/
//             hash_table[try] = NULL;
//             Person_t* tmp = hash_table[try];
//             return tmp;
//         }
//     }
//     return NULL;
// }

// int main() {
//     init_hash_table();
//     print_table();

//     Person_t jacob = {.name = "jacob", .age = 52};
//     Person_t mario = {.name = "mario", .age = 27};
//     Person_t jessica = {.name = "jessica", .age = 17};
//     Person_t robert = {.name = "robert", .age = 22};
//     Person_t pedro = {.name = "pedro", .age = 25};
//     Person_t marco = {.name = "marco", .age = 37};
//     Person_t juarez = {.name = "juarez", .age = 12};
//     Person_t silva = {.name = "silva", .age = 77};
//     Person_t tristan = {.name = "tristan", .age = 67};

//     hash_table_insert(&jacob);
//     hash_table_insert(&mario);
//     hash_table_insert(&robert);
//     hash_table_insert(&jessica);
//     hash_table_insert(&pedro);
//     hash_table_insert(&marco);
//     hash_table_insert(&juarez);
//     hash_table_insert(&silva);
//     hash_table_insert(&tristan);

//     print_table();

//     // Person_t* tmp = hash_table_lookup("Msk");
//     // printf("Address %p\n", (void*)tmp);

//     // tmp = hash_table_lookup("mario");
//     // printf("Address %p\n", (void*)tmp);
//     // // hash_table_delete("mario");
//     // print_table();
//     return 0;
// }