#include <iostream>
#include <string>
template <typename T, int N>
 class FixedArray{
   T arr[N];
     
 public:
 
    FixedArray(){
        for(int i =0; i < N; i++){
            arr[i] = T();
        }
    }
    void set(int index, T value){
        if(index < 0 || index >= N){
            std:: cout << "Error" << std:: endl;
            return;
        }
        arr[index] = value;
    }
 
    T get(int index){
        if(index < 0 || index >= N){
            std:: cout << "Error" << std:: endl;
            return T();
        }
        return arr[index];
    }
 
 int Size (){
     return N;
 }
 
 void print(){
    for (int i = 0; i < N; i++){
        std::cout << arr[i] << " ";
    }
    std:: cout << std:: endl;
 }
 
};
int main()
{
    FixedArray<int, 5> arr1;
    arr1.set(4, 10);
    arr1.set(0, 2);
    arr1.set(1, 5);
    arr1.set(2, 7);
    arr1.print();
    std:: cout << "Size = " << arr1.Size() << std:: endl;
    std:: cout << "Chislo = " << arr1.get(2) << std:: endl;
    
    
    FixedArray<double, 3> arr2;
    arr2.set(0, 2.2);
    arr2.set(1, 5.5);
    arr2.set(2, 3.14);
    arr2.print();
    std:: cout << "Size = " << arr2.Size() << std:: endl;
    std:: cout << "Chislo = " << arr2.get(0) << std:: endl;
    
    
    FixedArray<std::string, 4> arr3;
    arr3.set(0, "Hello");
    arr3.set(1, "World");
    arr3.set(2, "!");
    arr3.print();
    std:: cout << "Size = " << arr3.Size() << std:: endl;
    std:: cout << "Chislo = " << arr3.get(2) << std:: endl;
    

    return 0;
}
