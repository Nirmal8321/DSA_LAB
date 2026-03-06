#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverseDLL(Node** head_ref) {
    Node* temp = NULL;
    Node* current = *head_ref;
    
    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to next node (which is now in prev)
    }
    
    // Before changing head, check for the case of empty list or list with only one node
    if (temp != NULL)
        *head_ref = temp->prev;
}

int main() {
    // 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    
    head->next = second; second->prev = head;
    second->next = third; third->prev = second;
    third->next = fourth; fourth->prev = third;
    fourth->next = fifth; fifth->prev = fourth;
    
    cout << "Original DLL: ";
    printList(head);
    
    reverseDLL(&head);
    
    cout << "Reversed DLL: ";
    printList(head);
    
    return 0;
}
