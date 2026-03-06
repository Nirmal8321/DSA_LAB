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

void splitList(Node* head, Node** head1_ref, Node** head2_ref) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    
    if (head == NULL) return;
    
    // If there are odd nodes, fast_ptr->next becomes head
    // If there are even nodes, fast_ptr->next->next becomes head
    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    
    // If there are even elements, move fast_ptr to end
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
        
    // Set the head pointer of first half
    *head1_ref = head;
    
    // Set the head pointer of second half
    if (head->next != head)
        *head2_ref = slow_ptr->next;
        
    // Make second half circular
    fast_ptr->next = slow_ptr->next;
    
    // Make first half circular
    slow_ptr->next = head;
}

int main() {
    // 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head; // Close loop
    
    cout << "Original Circular List: ";
    printList(head);
    
    Node *head1 = NULL, *head2 = NULL;
    splitList(head, &head1, &head2);
    
    cout << "First Half: ";
    printList(head1);
    
    cout << "Second Half: ";
    printList(head2);
    
    return 0;
}
