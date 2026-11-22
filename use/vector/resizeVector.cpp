#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
void resizeVector(std::vector<T>& vec, int newSize, T value){
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    vec.resize(newSize, value);
    for(int i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
}

void test_resizeVector(){
    std::vector<int> vec = {1, 2, 3};
    resizeVector(vec, 5, 42);

    assert(vec.size() == 5);
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    assert(vec[3] == 42);
    assert(vec[4] == 42);
}

int main(){
    test_resizeVector();

    return 0;
}