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

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) return true;
    
    // Find middle
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* secondHalf = reverseList(slow->next);
    Node* firstHalf = head;
    Node* tempSecond = secondHalf;
    
    bool isPalin = true;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            isPalin = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    
    // Restore list (optional but good practice)
    slow->next = reverseList(tempSecond);
    
    return isPalin;
}

int main() {
    // Creating palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    
    cout << "List: ";
    printList(head);
    
    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }
    
    // Creating non-palindrome list: 1 -> 2 -> 3 -> 4
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    
    cout << "List: ";
    printList(head2);
    
    if (isPalindrome(head2)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is NOT a palindrome." << endl;
    }
    
    return 0;
}
