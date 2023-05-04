// #include <stdbool.h>
// #include <stdint.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// /**
//  * @brief The Compiler will generate the counters with 4 bytes, because it is focus in speed
//  * if we want to reduce the use of memory, we can set
//  *
//  */
// struct counters {
//     unsigned int little : 2;
//     unsigned int medium : 4;
//     unsigned int large : 6;
// } __attribute__((packed));
// #define NUM_LOOPS 50

// int main() {
//     struct counters counters;
//     counters.little = 0;
//     counters.medium = 0;
//     counters.large = 0;

//     for (size_t i = 0; i < NUM_LOOPS; i++) {
//         counters.large++;
//         counters.medium++;
//         counters.little++;
//         printf("%u, %u, %u\n", counters.little, counters.medium, counters.large);
//     }
//     printf("Sizeof counters = %d\n", sizeof(counters));
//     return 0;
// }