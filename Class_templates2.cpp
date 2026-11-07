#include <iostream>
#include <string>

template <typename T, int N>
class FixedArray{
private:
    T data[N];
public:
    void set(int index, T value){
        data[index] = value;
     }   
    T get(int index){
        return data[index];
    }
    int size(){
     return N;   
    }    
};
int main(){
FixedArray<int, 3> int_array;
int_array.set(0, 5);
int_array.set(1, 3);
int_array.set(2, 4);
std::cout << "size: " << int_array.size() << " " << "value: " << int_array.get(0) << std::endl;

FixedArray<double, 2> double_array;
double_array.set(0, 2.5);
double_array.set(1, 3.14);
std::cout << "size: " << double_array.size() << " " << "value: " << double_array.get(1) << std::endl;

FixedArray<std::string, 2> string_array;
string_array.set(0, "Hello");
string_array.set(1, "World");
std::cout << "size: " << string_array.size() << " " << "value: " << string_array.get(0) << std::endl;
return 0;
}
