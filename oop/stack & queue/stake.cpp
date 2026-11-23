#include <iostream>
#include <cstring>
#include <stack>
bool isBalanced(const std::string& str){
    std::stack<char> st;
    for(int i =0; i < str.length(); i++){
        
        if('(' == str[i] || '[' == str[i] || '{' == str[i]){
            st.push(str[i]);
        }
        else{
            if (st.empty()){
                return false;
            }
           if( (st.top() == '(' && str[i] == ')') || (st.top() == '[' && str[i] == ']') || (st.top() == '{' && str[i] == '}') ) {
               st.pop();
           } else {
               return false;
           }
        }
    }
    return st.empty();
}
int main()
{
    std::cout << isBalanced("({[]})") << std::endl;
    std::cout << isBalanced("{([]){") << std::endl;
    std::cout << isBalanced("[{()}](") << std::endl;

    return 0;
}
