#include <iostream>
#include <string>
#include <vector>
#include <stack>

int evaluateRPN(std::vector<std::string> tokens){
std::stack<int> s;
for(std::string token : tokens){
    if(token == "+" || token == "-" || token == "*" || token == "/"){
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        if(token  == "+") s.push(a + b);
        if(token  == "-") s.push(a - b);
        if(token  == "*") s.push(a * b);
        if(token  == "/") s.push(a / b);
    }
    else{
        s.push(std::stoi(token));
    }
}
return s.top();
}
int main(){
std::vector<std::string> expr = {"2", "1", "+", "3", "*"}; 
std::cout << evaluateRPN(expr) << '\n';
}
