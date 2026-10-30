#include <iostream>
#include <stack>
#include <string>
#include <cassert>

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
            if (c == '}' && top != '{') return false;
        }
    }
    return st.empty();
}

void test() {
    assert(isBalanced("({[]})") == true);
    assert(isBalanced("([)]") == false);
    assert(isBalanced("{[}]") == false);
    assert(isBalanced("()") == true);
    assert(isBalanced("(") == false);
    assert(isBalanced("") == true);
}

int main() {
    test();
    std::cout << "passed";
}
