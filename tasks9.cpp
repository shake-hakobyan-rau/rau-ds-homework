#include <iostream>
#include <vector>
std::vector<std::vector<int>>groupAdjacent(const
std::vector<int>& vec){
std::vector<std::vector<int>> result;
if(vec.empty()) {
return result;
}    
std::vector<int> current_group = {vec[0]};
for(size_t i = 1; i < vec.size(); ++i){
if(vec[i] == vec[i - 1]){
current_group.push_back(vec[i]);

} 
else{
result.push_back(current_group);
current_group = {vec[i]};
    
}  
}
result.push_back(current_group);
return result;   
}
int main(){
std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
std::vector<std::vector<int>> groups = groupAdjacent(vec);
std::cout << "{";
for(size_t i = 0; i < groups.size(); ++i){
std::cout << "{";
for(size_t j = 0; j < groups[i].size(); ++j){
std::cout << groups[i] [j];
if(j + 1 < groups[i].size()){
    std::cout << ", ";
}   
}
std::cout << "}";
if(i + 1 < groups.size()){
std::cout << ", ";
}   
}
std::cout << "}\n";
return 0;
}     
