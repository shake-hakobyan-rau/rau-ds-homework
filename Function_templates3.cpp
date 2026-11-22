#include <iostream>
#include <string>

template <typename T>
T sumArray(const T* arr, int size){
T sum = T();    
    for(int i = 0; i < size; i++){
     sum += arr[i];   
    }    
    return sum;
}
int main(){
int intArray [] = {10, 20, 30, 40};
double doubleArray [] = {1.2, 2.3, 3.4, 4.5};
std::string strArray [] = {"Hello, World!"};
std::cout << sumArray(intArray, std::size(intArray)) << '\n';
std::cout << sumArray(doubleArray, std::size(doubleArray)) << '\n';
std::cout << sumArray(strArray, std::size(strArray)) << '\n';
return 0;
}