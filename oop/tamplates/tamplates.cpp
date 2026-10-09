#include <iostream>
#include <string>
template <typename T>
void printElement(T value){
    std::cout << value << std:: endl;
}

int main()
{
printElement(5);
printElement(3.55);
printElement("Hello");
    return 0;
}
