#include <iostream>
#include <string>

template <typename T>
void mySwap(T& a, T& b){
T temp = a;
a = b;
b = temp;
}
int main(){
int x = 7;
int y = 15;
mySwap(x, y);
std::cout << x << " " << y << std::endl;
double n = 1.5;
double m = 3.3;
mySwap(n, m);
std::cout << n << " " << m << std::endl;
std::string s = "Hello";
std::string c = "World";
mySwap(s, c);
std::cout << s << " " << c << std::endl;
return 0;
}