#include <iostream>
#include <string>
template <typename T>
void MySwap(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
int x = 5, y = 10;
MySwap(x, y);
std:: cout << x << std:: endl << y << std:: endl;

double a = 3.15, b = 0.10;
MySwap(a, b);
std:: cout << a << std:: endl << b << std:: endl;

std:: string z = "Hello", c = "World";
MySwap(z, c);
std:: cout << z << std:: endl << c << std:: endl;

    return 0;
}
