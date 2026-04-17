#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main(void) {
    int tree_array[7] = {10, 5, 20, -1, -1, 15, 25};
    printf("Array Representation:\n");
    for (int i = 0; i < 7; i++) {
        if (tree_array[i] == -1) printf("[%d] = NULL\n", i);
        else printf("[%d] = %d\n", i, tree_array[i]);
    }

    Node *root = create_node(10);
    root->left = create_node(5);
    root->right = create_node(20);

    printf("\nLinked List Representation Root: %d\n", root->data);
    printf("Left Child: %d, Right Child: %d\n", root->left->data, root->right->data);
    return 0;
}
