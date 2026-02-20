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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to remove duplicates from a sorted list
void removeDuplicates(Node* head) {
    Node* current = head;
    
    // Iterate through the list
    while (current != NULL && current->next != NULL) {
        // If current data is same as next data
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp; // Free memory
        } else {
            // Move to next node only if no deletion
            current = current->next;
        }
    }
}

int main() {
    // Creating a sorted linked list with duplicates: 10 -> 10 -> 20 -> 30 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(30);
    head->next->next->next->next->next = new Node(40);
    
    cout << "Original List: ";
    printList(head);
    
    removeDuplicates(head);
    
    cout << "After removing duplicates: ";
    printList(head);
    
    return 0;
}
