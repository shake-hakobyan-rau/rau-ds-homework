#include <iostream>
#include <vector>

int removeElementsGreaterThan(std::vector<int>&v, int thres){
int c = 0;
while(!v.empty() && v.back() > thres){
v.pop_back();
c++;    
}
return c;
}
int main(){
std::vector<int> v = {1, 3, 5, 7, 9};
int removed = removeElementsGreaterThan(v, 5);
std::cout << "Removed: " << removed << std::endl;
std::cout << "Elements: ";
for(int x : v){
std::cout << x << " ";    
}
std::cout << '\n';
return 0;     
}