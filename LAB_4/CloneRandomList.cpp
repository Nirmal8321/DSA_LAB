#include <iostream>
#include <unordered_map>
using namespace std;

// Node structure with random pointer
struct Node {
    int data;
    Node* next;
    Node* random;
    
    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        cout << "Data: " << head->data << ", Random: ";
        if (head->random)
            cout << head->random->data;
        else
            cout << "NULL";
        cout << endl;
        head = head->next;
    }
}

// Function to clone the list
Node* cloneList(Node* head) {
    if (head == NULL) return NULL;
    
    unordered_map<Node*, Node*> map;
    
    Node* temp = head;
    // First pass: Create copy of each node and store in map
    while (temp != NULL) {
        map[temp] = new Node(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    // Second pass: Link next and random pointers
    while (temp != NULL) {
        map[temp]->next = map[temp->next];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }
    
    return map[head];
}

int main() {
    // Creating a linked list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    
    // Setting random pointers
    head->random = head->next->next;      // 1 -> 3
    head->next->random = head;            // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4
    head->next->next->next->random = head->next; // 4 -> 2
    
    cout << "Original List:" << endl;
    printList(head);
    
    Node* clonedHead = cloneList(head);
    
    cout << "\nCloned List:" << endl;
    printList(clonedHead);
    
    return 0;
}
