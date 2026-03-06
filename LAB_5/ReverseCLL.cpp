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

void reverseCLL(Node** head_ref) {
    if (*head_ref == NULL) return;
    
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    Node* head = *head_ref;
    
    // Reverse logic similar to SLL but with loop condition
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    
    // Fix the last node (which was head) to point to the new head (which is prev)
    // The previous last node is now 'prev', and 'head' is the old head (now last)
    head->next = prev;
    *head_ref = prev;
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
    
    reverseCLL(&head);
    
    cout << "Reversed CLL: ";
    printList(head);
    
    return 0;
}
