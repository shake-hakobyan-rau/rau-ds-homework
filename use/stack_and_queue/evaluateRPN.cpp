#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cassert>

int evaluateRPN(const std::vector<std::string>& expr) {
    std::stack<int> st;
    for (int i = 0; i < expr.size(); i++) {
        std::string s = expr[i];
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (s == "+") st.push(a + b);
            if (s == "-") st.push(a - b);
            if (s == "*") st.push(a * b);
            if (s == "/") st.push(a / b);
        }
        else {
            st.push(std::stoi(s));
        }
    }
    return st.top();
}

void test() {
    assert(evaluateRPN({"2", "1", "+", "3", "*"}) == 9);
    assert(evaluateRPN({"4", "2", "/"}) == 2);
    assert(evaluateRPN({"5", "3", "-"}) == 2);
    assert(evaluateRPN({"2", "3", "+"}) == 5);
    assert(evaluateRPN({"10", "2", "/"}) == 5);
}

int main() {
    test();
    std::cout << "passed";
}
