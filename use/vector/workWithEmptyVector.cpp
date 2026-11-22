#include <iostream>
#include <vector>
#include <cassert>

void workWithEmptyVector(std::vector<int>& vec){
    for(int i = 0; i < 10; ++i){
        vec.push_back(i + 1);
        std::cout << vec.size() << " "
                  << vec.capacity() << "\n";
    }
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}

void test_workWithEmptyVector(){
    std::vector<int> vec;
    workWithEmptyVector(vec);

    assert(vec.size() == 10);
    assert(vec[0] == 1);
    assert(vec[9] == 10);
}

int main(){
    test_workWithEmptyVector();

    return 0;
}