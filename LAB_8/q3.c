#include <stdio.h>

#define TABLE_SIZE 100

int mid_square_hash(int key) {
    int square = key * key;
    return (square / 10) % TABLE_SIZE;
}

int folding_hash(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 100;
        key /= 100;
    }
    return sum % TABLE_SIZE;
}

int main(void) {
    int keys[] = {44, 1234, 5678, 9876};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));

    printf("Mid-Square and Folding Hashing\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d -> Mid-Square: %d, Folding: %d\n",
               keys[i], mid_square_hash(keys[i]), folding_hash(keys[i]));
    }

    return 0;
}
