#include <iostream>
#include <string>
#include <cassert>

template<typename T1, typename T2>
class Pair{
private:
    T1 first;
    T2 second;

public:
    Pair(T1 a, T2 b){
        first = a;
        second = b;
    }
    T1 getFirst(){
        return first;
    }
    T2 getSecond(){
        return second;
    }
    void print(){
        std::cout << first << " " << second << "\n";
    }
};

void test_Pair(){
    Pair<int, double> p1(1, 0.5);

    assert(p1.getFirst() == 1);
    assert(p1.getSecond() == 0.5);

    p1.print();

    Pair<std::string, int> p2("abc", 2);

    assert(p2.getFirst() == "abc");
    assert(p2.getSecond() == 2);

    p2.print();
}

int main(){
    test_Pair();

    return 0;
}