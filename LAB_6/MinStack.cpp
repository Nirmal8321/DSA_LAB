#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s;
    int minEle;

public:
    void getMin() {
        if (s.empty())
            cout << "Stack is empty\n";
        else
            cout << "Minimum Element in the stack is: " << minEle << "\n";
    }

    void peek() {
        if (s.empty()) {
            cout << "Stack is empty ";
            return;
        }
        int t = s.top();
        cout << "Top Element is: ";
        (t < minEle) ? cout << minEle : cout << t;
        cout << "\n";
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top Element Removed: ";
        int t = s.top();
        s.pop();

        if (t < minEle) {
            cout << minEle << "\n";
            minEle = 2 * minEle - t;
        } else
            cout << t << "\n";
    }

    void push(int x) {
        if (s.empty()) {
            minEle = x;
            s.push(x);
            cout << "Number Inserted: " << x << "\n";
            return;
        }
        if (x < minEle) {
            s.push(2 * x - minEle);
            minEle = x;
        } else
            s.push(x);
        cout << "Number Inserted: " << x << "\n";
    }
};

int main() {
    MinStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.peek();
    
    return 0;
}
