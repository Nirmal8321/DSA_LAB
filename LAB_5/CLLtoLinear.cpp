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

void printList(Node* head, bool isCircular) {
    if (head == NULL) return;
    Node* temp = head;
    if (isCircular) {
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    } else {
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void convertToLinear(Node* head) {
    if (head == NULL) return;
    
    Node* current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = NULL;
}

int main() {
    // 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    cout << "Circular List: ";
    printList(head, true);
    
    convertToLinear(head);
    
    cout << "Linear List: ";
    printList(head, false);
    
    return 0;
}
