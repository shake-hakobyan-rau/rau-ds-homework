#include <iostream>
#include <vector>

template <typename T>
void resizeVector(std::vector<T>& vec, size_t new_size, const T& default_value){

std::cout << "before ch: ";
for(const auto& item : vec){
std::cout << item << " ";
}
std::cout << "\n";    
vec.resize(new_size, default_value);
std::cout << "after ch: ";
for(const auto& item : vec){
std::cout << item << " ";    
}
std::cout << "\n";
}
int main(){
std::vector<int> v = {1, 2, 3};
resizeVector(v, 5, 42);
return 0;
}