#include <iostream>
#include <vector>

void createAndFillVector(int N){
std::vector<int> vec(N);
for(int i = 0; i < N; ++i){
vec[i] = i + 1;
}
for(int i = 0; i < N; ++i){
std::cout << vec[i] << " ";  
}
std::cout << "Size: " << vec.size() << '\n';
std::cout << "Capacity: " << vec.capacity() << '\n';
}
int main(){
createAndFillVector(5);
return 0;    
}
