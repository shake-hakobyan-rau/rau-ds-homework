#include <iostream>
#include <string>
#include <cassert>

template<typename T>
T sumArray(T* arr, int size){
    T sum = T();
    for(int i = 0; i < size; ++i){
        sum += arr[i];
    }
    return sum;
}

void test_sumArray(){
    int arr1[] = {4, 7, 2, 6};
    int sum1 = sumArray(arr1, 4);

    assert(sum1 == 19);
    std::cout << sum1 << "\n";

    double arr2[] = {1.5, 2.5, 4.0};
    double sum2 = sumArray(arr2, 3);

    assert(sum2 == 8.0);
    std::cout << sum2 << "\n";

    std::string arr3[] = {"a", "w", "q"};
    std::string sum3 = sumArray(arr3, 3);

    assert(sum3 == "awq");
    std::cout << sum3 << "\n";
}

int main(){
    test_sumArray();

    return 0;
}