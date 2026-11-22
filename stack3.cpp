#include <iostream>
#include <string>
#include <stack>

void reverseString(std::string& s){
std::stack<char> st;
for(char c : s){
st.push(c);
}
for(int i = 0; i < s.length(); i++){
s[i] = st.top();
st.pop();
}
}
int main(){
std::string s = "Hello";
reverseString(s);
std::cout << s << '\n';    
}
