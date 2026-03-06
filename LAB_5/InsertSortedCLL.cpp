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

void insertSorted(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* current = *head_ref;
    
    // Case 1: Empty List
    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    // Case 2: New node is smaller than head
    else if (current->data >= new_node->data) {
        while (current->next != *head_ref)
            current = current->next;
            
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    // Case 3: Locate the node before the point of insertion
    else {
        while (current->next != *head_ref && current->next->data < new_node->data)
            current = current->next;
            
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    Node* head = NULL;
    
    insertSorted(&head, 3);
    insertSorted(&head, 1);
    insertSorted(&head, 4);
    insertSorted(&head, 2);
    
    cout << "Sorted Circular List: ";
    printList(head);
    
    return 0;
}
