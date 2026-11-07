#include <iostream>
#include <cstring>

template<typename T>
bool isEqual(T x, T y){
return x == y;    
}
template<>
bool isEqual(const char* x, const char* y){
return strcmp(x, y) == 0;    
}
int main(){
std::cout << std::boolalpha;    
std::cout << isEqual(5, 5) << "\n";
std::cout << isEqual("Hello", "World") << "\n";
return 0;    
}