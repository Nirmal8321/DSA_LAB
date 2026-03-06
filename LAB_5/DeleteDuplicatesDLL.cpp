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

void deleteDuplicates(Node** head_ref) {
    if (*head_ref == NULL) return;
    
    Node* current = *head_ref;
    
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* nextNext = current->next->next;
            delete current->next;
            current->next = nextNext;
            if (nextNext != NULL)
                nextNext->prev = current;
        } else {
            current = current->next;
        }
    }
}

int main() {
    // 1 <-> 1 <-> 2 <-> 3 <-> 3 <-> 4
    Node* head = new Node(1);
    head->next = new Node(1); head->next->prev = head;
    head->next->next = new Node(2); head->next->next->prev = head->next;
    head->next->next->next = new Node(3); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3); head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4); head->next->next->next->next->next->prev = head->next->next->next->next;
    
    cout << "Original List: ";
    printList(head);
    
    deleteDuplicates(&head);
    
    cout << "After removing duplicates: ";
    printList(head);
    
    return 0;
}
