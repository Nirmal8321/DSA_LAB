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

int getCount(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersectionNode(int d, Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;
    
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) return NULL;
        current1 = current1->next;
    }
    
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) return current1;
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return NULL;
}

Node* findIntersection(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    
    if (c1 > c2) {
        d = c1 - c2;
        return getIntersectionNode(d, head1, head2);
    } else {
        d = c2 - c1;
        return getIntersectionNode(d, head2, head1);
    }
}

int main() {
    // List 1: 3 -> 6 -> 9 -> 15 -> 30
    Node* head1 = new Node(3);
    head1->next = new Node(6);
    head1->next->next = new Node(9);
    head1->next->next->next = new Node(15);
    head1->next->next->next->next = new Node(30);
    
    // List 2: 10 -> 15 -> 30 (Intersecting at 15)
    Node* head2 = new Node(10);
    head2->next = head1->next->next->next; // Pointing to 15
    
    Node* intersection = findIntersection(head1, head2);
    
    if (intersection) {
        cout << "Intersection point data: " << intersection->data << endl;
    } else {
        cout << "No intersection point found." << endl;
    }
    
    return 0;
}
