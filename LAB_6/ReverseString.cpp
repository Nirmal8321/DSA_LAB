#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseString(string &s) {
    stack<char> st;
    
    for (int i = 0; i < s.length(); i++) {
        st.push(s[i]);
    }
    
    for (int i = 0; i < s.length(); i++) {
        s[i] = st.top();
        st.pop();
    }
}

int main() {
    string s = "Hello World";
    
    cout << "Original String: " << s << endl;
    
    reverseString(s);
    
    cout << "Reversed String: " << s << endl;
    
    return 0;
}
