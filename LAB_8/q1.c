#include <stdio.h>

#define TABLE_SIZE 10

int main(void) {
    int keys[] = {50, 700, 76, 85, 92, 73, 101};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));

    printf("Division Method Hashing (h(k) = k %% %d)\n", TABLE_SIZE);
    for (int i = 0; i < n; i++) {
        int index = keys[i] % TABLE_SIZE;
        printf("Key %d -> Index %d\n", keys[i], index);
    }

    return 0;
}
