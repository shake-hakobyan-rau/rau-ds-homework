#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec,
Predicate pred){
std::vector<T> result;
std::copy_if(vec.begin(), vec.end(), std::back_inserter(result),
 pred);
return result;    
}
bool isEven(int x){
return x % 2 == 0;    
}
int main(){
std::vector<int> vec = {1, 2, 3, 4, 5, 6};
std::vector<int> filtered = filterVector(vec, isEven);
std::cout << "filtered: ";
for(int x : filtered){
    std::cout << x << " ";
}
std::cout << "\n";

return 0;
}