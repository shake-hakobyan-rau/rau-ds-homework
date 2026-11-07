#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int>mergeSortedVectors(const std::vector<int>& vec1,
const std::vector<int>& vec2){    
std::vector<int>merged;
merged.reserve(vec1.size() + vec2.size());
size_t i = 0;
size_t j = 0;
while(i < vec1.size() && j < vec1.size()){
if(vec1[i] <= vec2[j]){
merged.push_back(vec1[i]);
i++;
}     
else{
merged.push_back(vec2[j]);
j++;
}  
}
while(i < vec1.size()){
merged.push_back(vec1[i]);
i++;    
}
while(j < vec2.size()){
merged.push_back(vec2[j]);
j++;    
}
return merged;
}
int main(){
std::vector<int> vec1 = {1, 3, 5, 7};   
std::vector<int> vec2 = {2, 4, 6, 8, 9};
std::vector<int> merged = mergeSortedVectors(vec1, vec2);
std::cout << "Rezult: ";
for(int n : merged){
std::cout << n << " ";
}    
std::cout << "\n";
return 0;
}