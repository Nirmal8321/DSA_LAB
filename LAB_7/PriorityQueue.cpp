#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
    
    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
    Node* head;

public:
    PriorityQueue() { head = NULL; }
    
    // Higher value -> Higher priority
    void enqueue(int d, int p) {
        Node* newNode = new Node(d, p);
        if (head == NULL || p > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL && temp->next->priority >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void dequeue() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int peek() {
        if (head == NULL) return -1;
        return head->data;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(4, 1);
    pq.enqueue(5, 2);
    pq.enqueue(6, 3);
    pq.enqueue(7, 0);
    
    while (!pq.isEmpty()) {
        cout << pq.peek() << " ";
        pq.dequeue();
    }
    
    return 0;
}
