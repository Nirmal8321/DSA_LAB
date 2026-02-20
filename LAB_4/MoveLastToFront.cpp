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

void moveLastToFront(Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    
    Node* secLast = NULL;
    Node* last = *head_ref;
    
    while (last->next != NULL) {
        secLast = last;
        last = last->next;
    }
    
    secLast->next = NULL;
    last->next = *head_ref;
    *head_ref = last;
}

int main() {
    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    cout << "Original List: ";
    printList(head);
    
    moveLastToFront(&head);
    
    cout << "After moving last to front: ";
    printList(head);
    
    return 0;
}
