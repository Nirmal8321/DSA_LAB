#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Comparator for priority queue
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKSortedLists(vector<Node*>& lists) {
    priority_queue<Node*, vector<Node*>, compare> pq;
    
    // Push the head of each list into the priority queue
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL)
            pq.push(lists[i]);
    }
    
    Node* dummy = new Node(0);
    Node* tail = dummy;
    
    while (!pq.empty()) {
        Node* top = pq.top();
        pq.pop();
        
        tail->next = top;
        tail = tail->next;
        
        if (top->next != NULL)
            pq.push(top->next);
    }
    
    return dummy->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // List 1: 1 -> 4 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);
    
    // List 2: 1 -> 3 -> 4
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);
    
    // List 3: 2 -> 6
    Node* l3 = new Node(2);
    l3->next = new Node(6);
    
    vector<Node*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    
    cout << "Merging 3 sorted lists..." << endl;
    
    Node* merged = mergeKSortedLists(lists);
    
    cout << "Merged List: ";
    printList(merged);
    
    return 0;
}
