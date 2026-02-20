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
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse list in groups of k
Node* reverseKGroup(Node* head, int k) {
    if (head == NULL) return NULL;
    
    Node* cursor = head;
    for(int i = 0; i < k; i++) {
        if(cursor == NULL) return head; // Less than k nodes, don't reverse (or do, depends on problem variant. Usually don't)
        cursor = cursor->next;
    }
    
    // Reverse first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    // Recursively call for the rest of the list
    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }
    
    return prev; // New head of the group
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 8; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    
    cout << "Original List: ";
    printList(head);
    
    int k = 3;
    head = reverseKGroup(head, k);
    
    cout << "Reversed in groups of " << k << ": ";
    printList(head);
    
    return 0;
}
