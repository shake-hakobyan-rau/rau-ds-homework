#include <iostream>
#include <cstring>
template <typename T>
bool isEqual(T a, T b){
    return a == b;
}

template<>
bool isEqual<const char*>(const char* a, const char* b){
    return std::strcmp(a, b) == 0;
}
int main(){
    std:: cout << isEqual(5, 5) << std:: endl;
    std:: cout << isEqual(5, 3) << std:: endl;
    std:: cout << isEqual(5.2, 5.2) << std:: endl;
    std:: cout << isEqual(3.14, 3.47) << std:: endl;

    const char* a = "bbb";
    const char* b = "bbb";
    const char* c = "aaa";
    
    std:: cout << isEqual(a, b) << std:: endl;
    std:: cout << isEqual(a, c) << std:: endl;

    return 0;
}
