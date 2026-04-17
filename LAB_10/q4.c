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

Node *insert(Node *root, int key) {
    if (!root) return create_node(key);
    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    return root;
}

int search(Node *root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

int main(void) {
    int arr[] = {50, 30, 70, 20, 40};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    Node *root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);

    int key = 40;
    if (search(root, key)) printf("%d Found\n", key);
    else printf("%d Not Found\n", key);
    return 0;
}
