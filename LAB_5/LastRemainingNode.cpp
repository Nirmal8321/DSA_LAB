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

// Function to find the last remaining node (Josephus Problem)
int getJosephusPosition(int n, int k) {
    // Create a circular linked list of size n
    Node* head = new Node(1);
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        prev->next = new Node(i);
        prev = prev->next;
    }
    prev->next = head; // Connect last to first
    
    Node* ptr1 = head;
    Node* ptr2 = head;
    
    while (ptr1->next != ptr1) {
        // Find k-th node
        int count = 1;
        while (count != k) {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            count++;
        }
        
        // Delete k-th node
        ptr2->next = ptr1->next;
        ptr1 = ptr2->next;
    }
    
    return ptr1->data;
}

int main() {
    int n = 14;
    int k = 2;
    cout << "The chosen place is " << getJosephusPosition(n, k) << endl;
    return 0;
}
