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

class CircularQueue {
    Node *front, *rear;

public:
    CircularQueue() {
        front = rear = NULL;
    }
    
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (front == NULL) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        
        rear = newNode;
        rear->next = front;
    }
    
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        if (front == rear) {
            delete front;
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }
    
    void display() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    
    cout << "Circular Queue: ";
    cq.display();
    
    cq.dequeue();
    cout << "After dequeue: ";
    cq.display();
    
    return 0;
}
