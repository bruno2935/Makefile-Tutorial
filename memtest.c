#include <stdlib.h>

int main() {
    int *p = malloc(sizeof *p);

    *p = 45;

    return 0;
}