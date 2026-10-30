#include <iostream>
#include <string>
#include <cassert>

template<typename T>
void printElement(T value){
    std::cout << value << "\n";
}

void test_printElement(){
    printElement(5);
    printElement(3.5);
    printElement(std::string("h"));

    assert(5 == 5);
    assert(3.5 == 3.5);
    assert(std::string("h") == "h");
}

int main(){
    test_printElement();

    return 0;
}