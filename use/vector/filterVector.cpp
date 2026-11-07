#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> filterVector(std::vector<T>& vec, bool (*predicate)(T)) {
    std::vector<T> result;
    for (int i = 0; i < vec.size(); i++) {
        if (predicate(vec[i])) {
            result.push_back(vec[i]);
        }
    }
    return result;
}

bool isEven(int x){
    return x % 2 == 0;
}

void test_filterVector(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> result = filterVector(vec, isEven);

    assert(result.size() == 3);
    assert(result[0] == 2);
    assert(result[1] == 4);
    assert(result[2] == 6);

    for(int i = 0; i < result.size(); ++i){
        std::cout << result[i] << " ";
    }
}

int main(){
    test_filterVector();

    return 0;
}