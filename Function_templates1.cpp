#include <iostream>
#include <string>

template <typename T>
void printElement(const T& element){
    std::cout << element << std::endl;
}    
int main(){
    int n = 5;
    
    printElement(n);
    double k = 0.5;
    
    printElement(k);
    std::string s = "Hello, World!";
    printElement(s);
    return 0;
}