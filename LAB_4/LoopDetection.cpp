#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to detect a loop in the linked list
bool detectLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        // If slow and fast pointers meet, there is a loop
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    // Creating a linked list with a loop
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    // Creating a loop: 40 points back to 20
    head->next->next->next->next = head->next;
    
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    
    // Removing the loop for testing negative case
    head->next->next->next->next = NULL;
    
    if (detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected." << endl;
    }
    
    return 0;
}
