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

Node *min_value_node(Node *node) {
    Node *cur = node;
    while (cur && cur->left) cur = cur->left;
    return cur;
}

Node *delete_node(Node *root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = delete_node(root->left, key);
    else if (key > root->data) root->right = delete_node(root->right, key);
    else {
        if (!root->left) {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(void) {
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = (int)(sizeof(arr) / sizeof(arr[0]));
    Node *root = NULL;
    for (int i = 0; i < n; i++) root = insert(root, arr[i]);

    root = delete_node(root, 30);
    inorder(root);
    printf("\n");
    return 0;
}
