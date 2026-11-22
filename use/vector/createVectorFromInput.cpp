#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput(){

    int n;
    std::cin >> n;
    std::vector<int> vec;
    while(n != 0){
        vec.push_back(n);
        std::cin >> n;
    }
    return vec;
}

void test_createVectorFromInput(){
    std::vector<int> vec = createVectorFromInput();

    assert(vec.size() == 3);
    assert(vec[0] == 7);
    assert(vec[1] == 8);
    assert(vec[2] == 9);

    std::cout << vec.size() << "\n";
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}

int main(){
    test_createVectorFromInput();

    return 0;
}