#include <iostream>
#include <string>
template <typename T>
 T sumArray(T* arr, int size){
    T sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
 }


int main()
{
    int a[] = {1, 3, 0, 9};
    std::cout << sumArray(a, 4) << std:: endl;
    
    double b[] = {1.35, 0.25, 2.55};
    std::cout << sumArray(b, 3) << std:: endl;
    
    

    return 0;
}
