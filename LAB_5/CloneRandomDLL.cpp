#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random; // Random pointer
    
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
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

Node* cloneDLL(Node* head) {
    if (head == NULL) return NULL;
    
    unordered_map<Node*, Node*> map;
    Node* temp = head;
    
    // Create copy of each node
    while (temp != NULL) {
        map[temp] = new Node(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    
    // Link next, prev, and random pointers
    while (temp != NULL) {
        map[temp]->next = map[temp->next];
        map[temp]->prev = map[temp->prev];
        map[temp]->random = map[temp->random];
        temp = temp->next;
    }
    
    return map[head];
}

int main() {
    // 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    
    // Random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    
    cout << "Original DLL:" << endl;
    printList(head);
    
    Node* clonedHead = cloneDLL(head);
    
    cout << "\nCloned DLL:" << endl;
    printList(clonedHead);
    
    return 0;
}
