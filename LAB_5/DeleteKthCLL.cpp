#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)" << endl;
}

void deleteNode(Node** head_ref, int key) {
    if (*head_ref == NULL) return;
    
    Node* curr = *head_ref, *prev = NULL;
    
    // Check if node is head
    while (curr->data != key) {
        if (curr->next == *head_ref) {
            cout << "Node not found" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    
    // Determine if it is the only node
    if (curr->next == *head_ref && prev == NULL) {
        *head_ref = NULL;
        delete curr;
        return;
    }
    
    // If multiple nodes
    if (curr == *head_ref) {
        prev = *head_ref;
        while (prev->next != *head_ref)
            prev = prev->next;
        *head_ref = curr->next;
        prev->next = *head_ref;
        delete curr;
    } else {
        prev->next = curr->next;
        delete curr;
    }
}

// Function to delete Kth node from beginning
void deleteKthNode(Node** head_ref, int k) {
    if (*head_ref == NULL || k <= 0) return;
    
    Node* curr = *head_ref;
    Node* prev = NULL;
    
    // If k=1, special handling
    if (k == 1) {
        deleteNode(head_ref, curr->data);
        return;
    }
    
    for (int i = 1; i < k; i++) {
        prev = curr;
        curr = curr->next;
        if (curr == *head_ref && i != k) return; // K > length
    }
    
    prev->next = curr->next;
    delete curr;
}

int main() {
    // 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    cout << "Original CLL: ";
    printList(head);
    
    deleteKthNode(&head, 3);
    
    cout << "After deleting 3rd node: ";
    printList(head);
    
    return 0;
}
