#include <iostream>
#include <string>
#include <vector>

template <typename T>
int linearSearch(const std::vector<T>& vec, const T& target){
for(int i = 0; i < vec.size(); i++){
if(vec[i] == target){
return i;    
}
}
return -1;    
}
int main(){
std::cout << "index 30: " << linearSearch<int>({10, 20, 30, 40}, 30) << '\n';
std::cout << "index 0.5: " << linearSearch<double>({0.5, 3.2, 1.8}, 0.5) << '\n';
std::cout << "index mango: " << linearSearch<std::string>({"apple", "mango"}, "mango") << '\n';
return 0;
} 
