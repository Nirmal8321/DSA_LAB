#include <iostream>
using namespace std;

// Node structure with next and bottom pointers
struct Node {
    int data;
    Node* next;
    Node* bottom;
    
    Node(int val) {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;
    
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    return result;
}

Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;
        
    // Recur for list on right
    root->next = flatten(root->next);
    
    // Merge this list with the list on right
    root = merge(root, root->next);
    
    return root;
}

void printList(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
}

int main() {
    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    Node* root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);
    
    root->bottom = new Node(7);
    root->bottom->bottom = new Node(8);
    root->bottom->bottom->bottom = new Node(30);
    
    root->next->bottom = new Node(20);
    
    root->next->next->bottom = new Node(22);
    root->next->next->bottom->bottom = new Node(50);
    
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom->bottom = new Node(45);
    
    cout << "Original structure created." << endl;
    
    root = flatten(root);
    
    cout << "Flattened List: ";
    printList(root);
    
    return 0;
}
