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

int countNodesInLoop(Node* head) {
    if (head == NULL) return 0;
    
    int count = 1;
    Node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; // Loop back to head
    
    cout << "Number of nodes in loop: " << countNodesInLoop(head) << endl;
    
    return 0;
}
