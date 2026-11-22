#include <iostream>
#include <vector>

void workWithEmptyVector(){
    std::vector<int>vec;
    for(int i = 1; i <= 10; ++i){
       vec.push_back(i);
       std::cout << "Element: " << i 
                 << " | Size: " << vec.size()
                 << " | Capacity: " << vec.capacity() << std::endl;
    }
}
int main(){
workWithEmptyVector();
return 0;    
}
