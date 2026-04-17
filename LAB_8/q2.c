#include <math.h>
#include <stdio.h>

#define TABLE_SIZE 10
#define A 0.6180339887

int multiplication_hash(int key) {
    double product = key * A;
    double fractional = product - floor(product);
    return (int)(TABLE_SIZE * fractional);
}

int main(void) {
    int keys[] = {50, 700, 76, 85, 92, 73, 101};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));

    printf("Multiplication Method Hashing\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d -> Index %d\n", keys[i], multiplication_hash(keys[i]));
    }

    return 0;
}
