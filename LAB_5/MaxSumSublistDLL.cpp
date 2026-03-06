#include <iostream>
#include <climits>
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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Kadane's Algorithm adapted for Linked List
int maxSubListSum(Node* head) {
    int maxSoFar = INT_MIN;
    int currentMax = 0;
    
    while (head != NULL) {
        currentMax += head->data;
        
        if (maxSoFar < currentMax)
            maxSoFar = currentMax;
            
        if (currentMax < 0)
            currentMax = 0;
            
        head = head->next;
    }
    
    return maxSoFar;
}

int main() {
    // -2 <-> -5 <-> 6 <-> -2 <-> -3 <-> 1 <-> 5 <-> -6
    Node* head = new Node(-2);
    Node* cur = head;
    int arr[] = {-5, 6, -2, -3, 1, 5, -6};
    
    for(int val : arr) {
        Node* newNode = new Node(val);
        cur->next = newNode;
        newNode->prev = cur;
        cur = newNode;
    }
    
    cout << "List: ";
    printList(head);
    
    cout << "Maximum Sum Sublist: " << maxSubListSum(head) << endl;
    
    return 0;
}
