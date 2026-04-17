#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7

typedef struct Node {
    int key;
    struct Node *next;
} Node;

void insert(Node *table[], int key) {
    int idx = key % TABLE_SIZE;
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = table[idx];
    table[idx] = new_node;
}

void print_table(Node *table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);
        Node *cur = table[i];
        while (cur != NULL) {
            printf("%d -> ", cur->key);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

int main(void) {
    int keys[] = {23, 43, 13, 27, 33};
    int n = (int)(sizeof(keys) / sizeof(keys[0]));
    Node *table[TABLE_SIZE] = {NULL};

    for (int i = 0; i < n; i++) {
        insert(table, keys[i]);
    }

    printf("Chaining Hash Table:\n");
    print_table(table);
    return 0;
}
