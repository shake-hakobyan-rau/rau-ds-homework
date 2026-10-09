#include <iostream>
#include <cstring>
template <typename T>
void printVlaue(T value){
    std:: cout << value << std:: endl;
}

template <>
void printValue<bool>(bool value){
    std :: cout <<(value ? "true" : "false") << std :: endl;
}

template <>
void printValue<char*>(char* value){
    std:: cout <<"\"" << value << "\"" << std :: endl;
}
int main(){
    printValue(12);
    printValue(3.14);
    printValue(true);
    printValue(false);
    
    char str = "Hello";
    printValue(str);
    return 0;
}
