#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to find the middle element using slow and fast pointers
void findMiddle(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    // Move fast pointer by 2 steps and slow pointer by 1 step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout << "The middle element is: " << slow->data << endl;
}

int main() {
    // Creating a sample linked list: 11 -> 22 -> 33 -> 44 -> 55
    Node* head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    head->next->next->next->next = new Node(55);
    
    cout << "Linked List: ";
    printList(head);
    
    findMiddle(head);
    
    // Adding one more node to check even length case: 11 -> 22 -> 33 -> 44 -> 55 -> 66
    head->next->next->next->next->next = new Node(66);
    
    cout << "Linked List: ";
    printList(head);
    
    findMiddle(head); // Should print 44 (second middle for even)
    
    return 0;
}
