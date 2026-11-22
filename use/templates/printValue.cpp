#include <iostream>
#include <cassert>

template<typename T>
void printValue(T value){
    std::cout << value << "\n";
}

template<>
void printValue<bool>(bool value){
    if(value){
        std::cout << "true\n";
    }
    else{
        std::cout << "false\n";
    }
}

template<>
void printValue<char*>(char* value){
    std::cout << '"'<< value << '"' << "\n";
}

void test_printValue(){
    printValue(67);
    printValue(3.7);

    bool a = true;
    bool b = false;

    printValue(a);
    printValue(b);

    char text[] = "ar";

    printValue(text);

    assert(a == true);
    assert(b == false);
}

int main(){
    test_printValue();

    return 0;
}