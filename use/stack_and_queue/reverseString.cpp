#include <iostream>
#include <stack>
#include <string>
#include <cassert>

void reverseString(std::string& s) {
    std::stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }
    for (int i = 0; i < s.size(); i++) {
        s[i] = st.top();
        st.pop();
    }
}

void test() {
    std::string s1 = "Hello";
    reverseString(s1);
    assert(s1 == "olleH");

    std::string s2 = "World";
    reverseString(s2);
    assert(s2 == "dlroW");

    std::string s3 = "abc";
    reverseString(s3);
    assert(s3 == "cba");

    std::string s4 = "";
    reverseString(s4);
    assert(s4 == "");
}

int main() {
    test();
    std::cout << "passed";
}
