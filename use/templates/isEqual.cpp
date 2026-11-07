#include <iostream>
#include <cstring>
#include <cassert>

template<typename T>
bool isEqual(T a, T b){
    return a == b;
}
template<>
bool isEqual<const char*>(const char* a, const char* b){
    return std::strcmp(a, b) == 0;
}

void test_isEqual(){
    int a = 5;
    int b = 5;
    int c = 8;

    assert(isEqual(a, b) == true);
    assert(isEqual(a, c) == false);

    std::cout << isEqual(a, b) << "\n";
    std::cout << isEqual(a, c) << "\n";

    double x = 2.5;
    double y = 2.5;

    assert(isEqual(x, y) == true);

    std::cout << isEqual(x, y) << "\n";

    const char* s1 = "abc";
    const char* s2 = "abc";
    const char* s3 = "xyz";

    assert(isEqual(s1, s2) == true);
    assert(isEqual(s1, s3) == false);

    std::cout << isEqual(s1, s2) << "\n";
    std::cout << isEqual(s1, s3) << "\n";
}

int main(){
    test_isEqual();

    return 0;
}