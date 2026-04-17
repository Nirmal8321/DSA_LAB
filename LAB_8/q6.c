#include <stdio.h>

#define TABLE_SIZE 11

void init_table(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }
}

int h1(int key) { return key % TABLE_SIZE; }
int h2(int key) { return 7 - (key % 7); }

void insert_double_hash(int table[], int key) {
    int i = 0;
    while (i < TABLE_SIZE) {
        int idx = (h1(key) + i * h2(key)) % TABLE_SIZE;
        if (table[idx] == -1) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int main(void) {
    int keys[] = {23, 43, 13, 27, 33};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));
    int table[TABLE_SIZE];
    init_table(table);

    for (int i = 0; i < n; i++) {
        insert_double_hash(table, keys[i]);
    }

    printf("Double Hashing Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == -1) {
            printf("[%d] -> EMPTY\n", i);
        } else {
            printf("[%d] -> %d\n", i, table[i]);
        }
    }

    return 0;
}
