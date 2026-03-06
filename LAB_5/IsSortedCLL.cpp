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

bool isSorted(Node* head) {
    if (head == NULL) return true;
    
    Node* current = head;
    do {
        // If next value is smaller, then it is not sorted
        // But we need to handle the wrap around case where max connects to min
        // For strictly increasing, current->data <= current->next->data should hold until wrap around.
        // Actually, simplest check for "Is Sorted" means all elements are in order starting from min.
        // But usually for circular, we just check if there is at most one drop.
        
        if (current->next == head) break; // Finished checking
        if (current->data > current->next->data) return false;
        
        current = current->next;
    } while (current != head);
    
    return true;
}

// Improved version that finds min and checks order
bool isSortedImproved(Node* head) {
    if (head == NULL) return true;
    
    // Find absolute minimum node to start checking
    Node* minNode = head;
    Node* curr = head;
    do {
        if (curr->data < minNode->data)
            minNode = curr;
        curr = curr->next;
    } while (curr != head);
    
    // Now check if sorted starting from minNode
    curr = minNode;
    do {
        if (curr->next != minNode && curr->data > curr->next->data)
            return false;
        curr = curr->next;
    } while (curr->next != minNode);
    
    return true;
}

int main() {
    // 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    if (isSortedImproved(head))
        cout << "Sorted" << endl;
    else
        cout << "Not Sorted" << endl;
        
    return 0;
}
