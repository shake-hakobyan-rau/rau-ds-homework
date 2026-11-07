#include <iostream>
#include <string>

template<typename T>
void printValue(T value){
std::cout << value;
}
template<>
void printValue(bool value){
if(value){
std::cout << "true";   
} 
else{
std::cout << "false";    
}
}
template<>
void printValue(const char* value){
std::cout << "\"" << value << "\"";    
}  

int main(){
printValue(5);
std::cout << "\n";
printValue(true);
std::cout << "\n";
printValue("text");
std::cout << "\n";
return 0;
}