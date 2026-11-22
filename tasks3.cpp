#include <iostream>
#include <vector>

std::vector<int>creatVectorFromInput(){
    std::vector<int>vec;
    int number;
    while(std::cin >> number && number != 0){
        vec.push_back(number);
    }    
    return vec;
}
int main(){
    std::vector<int> inputVec = creatVectorFromInput();
    std::cout << "Size: " << inputVec.size() << std::endl;
    std::cout << "Elements: ";
    for(int elem : inputVec){
        std::cout << elem << " ";
        std::cout << std::endl;
        return 0;
    }