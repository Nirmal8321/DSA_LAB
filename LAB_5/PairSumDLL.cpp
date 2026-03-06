#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void pairSum(Node* head, int x) {
    Node* first = head;
    Node* second = head;
    
    // Move second to end
    while (second->next != NULL)
        second = second->next;
        
    bool found = false;
    
    // Two pointer approach
    while (first != second && second->next != first) {
        if ((first->data + second->data) == x) {
            found = true;
            cout << "(" << first->data << ", " << second->data << ")" << endl;
            first = first->next;
            second = second->prev;
        } else {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    
    if (!found)
        cout << "No pair found" << endl;
}

int main() {
    // Sorted DLL: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    
    head->next = n2; n2->prev = head;
    n2->next = n4; n4->prev = n2;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;
    n6->next = n8; n8->prev = n6;
    n8->next = n9; n9->prev = n8;
    
    int x = 7;
    cout << "Pairs with sum " << x << ":" << endl;
    pairSum(head, x);
    
    return 0;
}
