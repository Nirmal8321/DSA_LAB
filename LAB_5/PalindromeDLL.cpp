#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    
    Node(char val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

bool isPalindrome(Node* head) {
    if (head == NULL) return true;
    
    Node* left = head;
    Node* right = head;
    
    // Move right to the end
    while (right->next != NULL)
        right = right->next;
        
    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;
            
        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    // r <-> a <-> c <-> e <-> c <-> a <-> r
    string s = "racecar";
    Node* head = new Node(s[0]);
    Node* cur = head;
    
    for(int i = 1; i < s.length(); i++) {
        Node* newNode = new Node(s[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = newNode;
    }
    
    if (isPalindrome(head))
        cout << "It is a Palindrome" << endl;
    else
        cout << "Not a Palindrome" << endl;
        
    return 0;
}
