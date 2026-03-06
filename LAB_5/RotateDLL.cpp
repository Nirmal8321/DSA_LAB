#include <iostream>
using namespace std;

struct Node {
    char data; // Using char for variety
    Node* prev;
    Node* next;
    
    Node(char val) {
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

void rotate(Node** head_ref, int N) {
    if (N == 0) return;
    
    Node* current = *head_ref;
    
    // Find the Nth node
    int count = 1;
    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }
    
    // If current is NULL, N is greater than or equal to count of nodes
    if (current == NULL) return;
    
    Node* NthNode = current;
    
    // If Nth node is the last node
    if (current->next == NULL) return;
    
    // Move current to last node
    while (current->next != NULL)
        current = current->next;
    
    // Connect last node to old head
    current->next = *head_ref;
    (*head_ref)->prev = current;
    
    // Change head to (N+1)th node
    *head_ref = NthNode->next;
    (*head_ref)->prev = NULL;
    
    // Break the link of Nth node
    NthNode->next = NULL;
}

int main() {
    // a <-> b <-> c <-> d <-> e
    Node* head = new Node('a');
    head->next = new Node('b'); head->next->prev = head;
    head->next->next = new Node('c'); head->next->next->prev = head->next;
    head->next->next->next = new Node('d'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('e'); head->next->next->next->next->prev = head->next->next->next;
    
    cout << "Original List: ";
    printList(head);
    
    int N = 2;
    rotate(&head, N);
    
    cout << "Rotated by " << N << ": ";
    printList(head);
    
    return 0;
}
