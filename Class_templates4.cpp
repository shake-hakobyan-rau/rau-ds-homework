#include <iostream>
#include <string>

template<typename T>
class Range{
private:
    T start;
    T end;
public:
    Range(T start, T end) : start(start), end(end){}
    bool contains(const T& value) const{
        return (value <= end && value >= start);
} 
 auto lenght()const{
    return end - start;
 }       
 void print()const{
    std::cout << start << " " << end;
 }     
};
int main(){
Range<int> int_range(5, 10);
int_range.print();
std::cout << std::endl;
std::cout << int_range.contains(7) << std::endl;
std::cout << int_range.lenght() << std::endl;

Range<double> double_range(1.5, 5.3);
double_range.print();
std::cout << std::endl;
std::cout << double_range.contains(7.1) << std::endl;
std::cout << double_range.lenght() << std::endl;

Range<char> char_range('a', 'x');
char_range.print();
std::cout << std::endl;
std::cout << char_range.contains('y') << std::endl;
return 0;
}