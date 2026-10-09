#include <iostream>
#include <cstring>
#include <stack>
void reverseString(std::string& str){
    std::stack<char> st;
    for(int i = 0; i < str.size(); i++){
        st.push(str[i]);
    }
    
    for(int i = 0; i < str.size(); i++){
        str[i] = st.top();
        st.pop();
    }
}
int main()
{
std::string str = "hello";
reverseString(str);
std::cout << str << std::endl;

std::string str2 = " ";
reverseString(str2);
std::cout << str2 << std::endl;

std::string str3 = "a";
reverseString(str3);
std::cout << str3 << std::endl;

std::string str4 = "h e l l o";
reverseString(str4);
std::cout << str4 << std::endl;

std::string str5 = "!99%";
reverseString(str5);
std::cout << str5 << std::endl;

    return 0;
}
