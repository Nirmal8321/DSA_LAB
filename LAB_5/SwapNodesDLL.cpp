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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int countNodes(Node* s) {
    int count = 0;
    while (s != NULL) {
        count++;
        s = s->next;
    }
    return count;
}

void swapKth(Node** head_ref, int k) {
    int n = countNodes(*head_ref);
    if (n < k) return;
    if (2 * k - 1 == n) return;
    
    Node* x = *head_ref;
    Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
    
    Node* y = *head_ref;
    Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
    
    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;
    
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
    
    if (k == 1) *head_ref = y;
    if (k == n) *head_ref = x;
    
    // Adjust prev pointers
    // This is simplified swapping logic; full pointer update including prev is cleaner usually but verbose.
    // Re-linking pointers for DLL correctness:
    if(x->next) x->next->prev = x;
    if(y->next) y->next->prev = y;
    if(x->prev) x->prev->next = x; // Wait, above logic handles nexts.
    // Fixing prevs:
    temp = x->prev;
    x->prev = y->prev;
    y->prev = temp;
    
    if (x->prev) x->prev->next = x;
    if (y->prev) y->prev->next = y; 
}

int main() {
    // 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2); head->next->prev = head;
    head->next->next = new Node(3); head->next->next->prev = head->next;
    head->next->next->next = new Node(4); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5); head->next->next->next->next->prev = head->next->next->next;
    
    cout << "Original List: ";
    printList(head);
    
    int k = 2;
    swapKth(&head, k);
    
    cout << "After swapping " << k << "th nodes: ";
    printList(head);
    
    return 0;
}
