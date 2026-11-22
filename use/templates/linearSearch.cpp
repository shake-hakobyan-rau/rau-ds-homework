#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template<typename T>
int linearSearch(std::vector<T>& vec, T value){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i] == value){
            return i;
        }
    }
    return -1;
}

void test_linearSearch(){
    std::vector<int> vec1 = {4, 8, 2, 9};
    int index1 = linearSearch(vec1, 2);

    assert(index1 == 2);
    std::cout << index1 << "\n";

    std::vector<double> vec2 = {1.2, 3.7, 5.5};
    int index2 = linearSearch(vec2, 5.5);

    assert(index2 == 2);
    std::cout << index2 << "\n";

    std::vector<std::string> vec3 = {"a", "w", "q"};
    int index3 = linearSearch(vec3, std::string("w"));

    assert(index3 == 1);
    std::cout << index3 << "\n";

    int index4 = linearSearch(vec1, 100);

    assert(index4 == -1);
    std::cout << index4 << "\n";
}

int main(){
    test_linearSearch();

    return 0;
}