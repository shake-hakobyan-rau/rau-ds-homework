#include <iostream>
#include <string>
template <typename T1, typename T2>
 class Pair{
    T1 number;
    T2 chislo;
    
    public:
    Pair (T1 n, T2 ch) : number(n), chislo(ch){}
    
    void print(){
        std::cout << "Pervoe chislo = " << number << std:: endl << "Vtoroe chislo = " << chislo <<  std:: endl;
        
    }
    
    
};
int main()
{
Pair<int, double> p1 (10, 3.14);
p1.print();

Pair<int, std::string> p2 (18, "Hello");
p2.print();

Pair<std::string, double> p3 ("World", 1.1);
p3.print();

    return 0;
}
