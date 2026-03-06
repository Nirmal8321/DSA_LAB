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

Node* mergeSortedDLL(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    if (head1->data < head2->data) {
        head1->next = mergeSortedDLL(head1->next, head2);
        if (head1->next != NULL)
            head1->next->prev = head1;
        head1->prev = NULL;
        return head1;
    } else {
        head2->next = mergeSortedDLL(head1, head2->next);
        if (head2->next != NULL)
            head2->next->prev = head2;
        head2->prev = NULL;
        return head2;
    }
}

int main() {
    // List 1: 1 <-> 3 <-> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3); l1->next->prev = l1;
    l1->next->next = new Node(5); l1->next->next->prev = l1->next;
    
    // List 2: 2 <-> 4 <-> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4); l2->next->prev = l2;
    l2->next->next = new Node(6); l2->next->next->prev = l2->next;
    
    cout << "List 1: "; printList(l1);
    cout << "List 2: "; printList(l2);
    
    Node* merged = mergeSortedDLL(l1, l2);
    
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}
