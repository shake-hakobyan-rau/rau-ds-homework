#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& str){
std::stack<char> s;
for(char ch : str){
if(ch == '(' || ch == '[' || ch == '{'){
    s.push(ch);
}    
else if(ch ==')' || ch == ']' || ch == '}'){
    if(s.empty()){
    return false;
}
char top = s.top();
if((ch == ')' && top == '(')||
   ( ch == ']' && top == '[')||
   (ch == '}' && top == '{')){
    s.pop();
    }
    else{
    return false;
    }    
    }
}
    /* code */
return s.empty();

}
int main(){
std::cout << std::boolalpha;
std::cout << isBalanced("{[]}") << '\n';
std::cout << isBalanced("([)]") << '\n';
std::cout << isBalanced("{[}]") << '\n';  
}

