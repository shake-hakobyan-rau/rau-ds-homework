#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(int n){
    std::vector<int> vec(n);
    for(int i = 0; i < n; ++i){
        vec[i] = i + 1;
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    std::cout << vec.size() << " " << vec.capacity() << "\n";

    return vec;
}

void test_createAndFillVector(){
    std::vector<int> vec = createAndFillVector(3);

    assert(vec.size() == 3);
    assert(vec[0] == 1);
    assert(vec[1] == 2);
    assert(vec[2] == 3);
    
}

int main(){
    test_createAndFillVector();

    return 0;
}