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

Node* mergeSortedLists(Node* l1, Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    Node* dummy = new Node(0);
    Node* tail = dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    
    return dummy->next;
}

int main() {
    // List 1: 1 -> 3 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);
    
    // List 2: 2 -> 4 -> 6
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);
    
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    Node* merged = mergeSortedLists(l1, l2);
    
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}
