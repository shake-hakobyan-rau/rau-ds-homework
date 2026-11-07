#include <iostream>
#include <cassert>

template<typename T>
class Range{
private:
    T start;
    T end;

public:
    Range(T a, T b){
        start = a;
        end = b;
    }
    bool contains(const T& value){
        return value >= start && value <= end;
    }
    T length(){
        return end - start;
    }
    void print(){
        std::cout << start << " " << end << "\n";
    }
};

void test_Range(){
    Range<int> r1(3, 10);

    assert(r1.contains(5) == true);
    assert(r1.contains(15) == false);
    assert(r1.length() == 7);

    r1.print();

    Range<double> r2(1.5, 6.5);

    assert(r2.contains(4.0) == true);
    assert(r2.contains(7.0) == false);
    assert(r2.length() == 5.0);

    r2.print();

    Range<char> r3('a', 'f');

    assert(r3.contains('c') == true);
    assert(r3.contains('z') == false);
    assert(r3.length() == 5);

    r3.print();
}

int main(){
    test_Range();

    return 0;
}