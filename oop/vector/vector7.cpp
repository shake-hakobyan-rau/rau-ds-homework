#include <iostream>
#include <vector>
std::vector<int> mergeSortedvector(std::vector<int>& vec1, std::vector<int>& vec2){

    std::vector<int> merged;
    
    int i = 0;
    int j = 0;
    
    for(int p = 0; p < vec1.size() + vec2.size(); p++){
        if(i < vec1.size() && j < vec2.size()){
            if(vec1[i] <= vec2[j]){
                merged.push_back(vec1[i]);
                i++;
            }
            else{
              merged.push_back(vec2[j]);  
              j++;
            }
        }
        else if(i < vec1.size()){
            merged.push_back(vec1[i]);
            i++;
        }
        else{
            merged.push_back(vec2[j]);
            j++;
        }
    }
    return merged;
}
int main()
{
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};
    std::vector<int> merged = mergeSortedvector(vec1, vec2);
    
    for(int i =0 ; i < merged.size(); i++){
        std::cout << merged[i];
    }
    return 0;
}
