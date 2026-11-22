#include <iostream>
#include <vector>
#include <algorithm>

int findSubsequence(const std::vector<int>& main_vec, const 
std::vector<int>& sub_vec){
if(sub_vec.empty()) return 0;
if(main_vec.size() < sub_vec.size()) return -1;
for(size_t i = 0; i <= main_vec.size() - sub_vec.size(); ++i){
bool found = true;
for(size_t j = 0; j < sub_vec.size(); ++j){
    if(main_vec[i + j] != sub_vec[j]){
        found = false;
        break;
    }
}
if(found) return static_cast<int>(i);   
}
return -1;   
}    
int main(){
std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
std::vector<int> sub_vec = {3, 4, 5};
int index = findSubsequence(main_vec, sub_vec);
std::cout << "//rezult: " << index << std::endl;
return 0;  
}