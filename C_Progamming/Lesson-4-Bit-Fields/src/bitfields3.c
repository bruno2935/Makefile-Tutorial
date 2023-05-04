#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t array_of_bits = 0;

#define SET_BIT(BF, N) BF |= ((uint64_t)0x0000000000000001 << N)
#define CLR_BIT(BF, N) BF &= ~((uint64_t)0x0000000000000001 << N)
#define IS_BIT_SET(BF, N) ((BF >> N) & 0x1)

int main() {
    SET_BIT(array_of_bits, 0);
    SET_BIT(array_of_bits, 1);
    SET_BIT(array_of_bits, 0);
    SET_BIT(array_of_bits, 35);
    SET_BIT(array_of_bits, 23);
    SET_BIT(array_of_bits, 65);
    CLR_BIT(array_of_bits, 23);
    for (size_t i = 0; i < 64; i++) {
        if (IS_BIT_SET(array_of_bits, i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}