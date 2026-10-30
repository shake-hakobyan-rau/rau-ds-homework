#include <iostream>
#include <string>
#include <cassert>

template<typename T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

void test_mySwap(){
    int a = 17;
    int b = 4;

    mySwap(a, b);

    assert(a == 4);
    assert(b == 17);

    std::cout << a << " " << b << "\n";

    double x = 8.25;
    double y = 1.75;

    mySwap(x, y);

    assert(x == 1.75);
    assert(y == 8.25);

    std::cout << x << " " << y << "\n";

    std::string s1 = "c";
    std::string s2 = "d";
    
    mySwap(s1, s2);
    
    assert(s1 == "d");
    assert(s2 == "c");
    
    std::cout << s1 << " " << s2 << "\n";
}

int main(){
    test_mySwap();

    return 0;
}