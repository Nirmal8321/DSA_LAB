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

Node* mergeCLL(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    Node* last1 = head1;
    while (last1->next != head1)
        last1 = last1->next;
        
    Node* last2 = head2;
    while (last2->next != head2)
        last2 = last2->next;
        
    last1->next = head2;
    last2->next = head1;
    
    return head1;
}

int main() {
    // List 1: 1 -> 2
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = head1;
    
    // List 2: 3 -> 4
    Node* head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = head2;
    
    cout << "List 1: ";
    printList(head1);
    
    cout << "List 2: ";
    printList(head2);
    
    Node* merged = mergeCLL(head1, head2);
    
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}
