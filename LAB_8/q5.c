#include <stdio.h>

#define TABLE_SIZE 7

void init_table(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
}

void insert_quadratic(int table[], int key) {
    int hash = key % TABLE_SIZE;
    int i = 0;
    while (i < TABLE_SIZE) {
        int idx = (hash + i * i) % TABLE_SIZE;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int main(void) {
    int keys[] = {23, 43, 13, 27};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));
    int table[TABLE_SIZE];
    init_table(table);

    for (int i = 0; i < n; i++) {
        insert_quadratic(table, keys[i]);
    }

    printf("Quadratic Probing Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1) {
            printf("[%d] -> EMPTY\n", i);
        } else {
            printf("[%d] -> %d\n", i, table[i]);
        }
    }

    return 0;
}
