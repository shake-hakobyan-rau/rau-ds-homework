#include <iostream>
#include <stack>
#include <string>
#include <cassert>

bool isBalanced(std::string& s){
    std::stack<char> st;

    for(int i = 0; i < s.size();++i){
        char d = s[i];
        if (d == '(' || d == '{' || d == '['){
            st.push(d);
        }
        else if(d == ')' || d == '}' || ']'){
            if(s.empty()){
                return false;
            }
            char top = st.top();
            st.pop();
            if(d == ')' || top != '(') return false;
                if(d == '}' || top != '{') return false;
            if(d == ']' || top != '[') return false;
        }
    }
    return st.empty();
}
