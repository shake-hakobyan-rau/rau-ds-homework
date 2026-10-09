#include <iostream>
#include <cstring>
#include <vector>
#include <stdexcept>
#include <stack>
int evaluateRPN(std::vector<std::string>& expr){
    std::stack<int> st;
    for(int i =0; i < expr.size(); i++){
        std::string temp = expr[i];
        if(temp == "+" || temp == "-" || temp == "*" || temp == "/"){
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
             int result = 0;
             
            if(temp == "+"){
                result = first + second;
            }
            else if(temp == "-"){
                result = first - second;
            }
            else if(temp == "*"){
                result = first * second;
            }
            else if(temp == "/"){
                if(second != 0)
                    result = first / second;
            }
            st.push(result);
        }
        else{
            st.push(std::stoi(temp));
        }
    }
        return st.top();
    }
int main(){
std::vector<std::string> expr = {"2", "1", "+", "3", "*"};
int result = evaluateRPN(expr);
std::cout << result << std::endl;

std::vector<std::string> expr1 = {"10", "4", "-"};
int result1 = evaluateRPN(expr1);
std::cout << result1 << std::endl;

std::vector<std::string> expr2 = {"10", "5", "/"};
int result2 = evaluateRPN(expr2);
std::cout << result2 << std::endl;

std::vector<std::string> expr3 = {"35"};
int result3 = evaluateRPN(expr3);
std::cout << result3 << std::endl;

std::vector<std::string> expr4 = {"-15"};
int result4 = evaluateRPN(expr4);
std::cout << result4 << std::endl;

std::vector<std::string> expr5 = {"0", "4", "*"};
int result5 = evaluateRPN(expr5);
std::cout << result5 << std::endl;

    return 0;
}
