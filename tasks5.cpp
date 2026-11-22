#include <iostream>
#include <vector>

void manageCapacity(std::vector<int>& v){
std::cout << "size: " << v.size()
          << "capacity: " << v.capacity() << std::endl;
v.reserve(v.size() + 500);
std::cout <<"after reserve() capacity: " << v.capacity() << std::endl;  
for(int i = 1; i <= 500; ++i){
v.push_back(i);    
}
std::cout << "New size: " << v.size()
          << "New capacity: " << v.capacity() << std::endl;
}
int main(){
std::vector<int> my_vector = {10, 20, 30};
manageCapacity(my_vector);
return 0;    
}          