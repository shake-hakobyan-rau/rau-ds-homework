#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(){
    std::vector<int> vec;
    std::cout << vec.size() << " " << vec.capacity() << "\n";
    vec.reserve(500);
    for(int i = 0; i < 500; ++i){
        vec.push_back(i + 1);
    }
    std::cout << vec.size() << " " << vec.capacity() << "\n";
}

void test_manageCapacity(){
    std::vector<int> vec;
    vec.reserve(500);
    for(int i = 0; i < 500; ++i){
        vec.push_back(i + 1);
    }
    
    assert(vec.size() == 500);
    assert(vec[0] == 1);
    assert(vec[499] == 500);
    assert(vec.capacity() >= 500);
}

int main(){
    manageCapacity();
    test_manageCapacity();

    return 0;
}