#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
private:
T1 first;
T2 second;
public:
Pair(const T1& f, const T2& s) : first(f), second(s) {}
void print() const {
std::cout << "Pair: " << first << ", " << second << " " << std::endl;
}
};

int main(){
Pair<int, double> p1(5, 3.14);
std::cout << "Test 1 (int, double): ";
p1.print();
Pair<std::string, int> p2("Age", 19);
std::cout << "Test 2 (string, int): ";
p2.print();
Pair<double, std::string> p3(99.9, "USD");

std::cout << "Test 3 (double, string): ";
p3.print();
return 0;
}