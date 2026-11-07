#include <iostream>
#include <string>
#include <cassert>

template<typename T, int N>
class FixedArray{
private:
    T arr[N];

public:
    void set(int index, T value){
        arr[index] = value;
    }
    T get(int index){
        return arr[index];
    }
    int size(){
        return N;
    }
};

void test_FixedArray(){
    FixedArray<int, 4> a;

    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);
    a.set(3, 40);

    assert(a.get(0) == 10);
    assert(a.get(1) == 20);
    assert(a.get(2) == 30);
    assert(a.get(3) == 40);
    assert(a.size() == 4);

    std::cout << a.get(0) << " " << a.get(1) << " " << a.get(2) << " "<< a.get(3) << "\n";

    FixedArray<std::string, 3> b;

    b.set(0, "a");
    b.set(1, "w");
    b.set(2, "q");

    assert(b.get(0) == "a");
    assert(b.get(1) == "w");
    assert(b.get(2) == "q");
    assert(b.size() == 3);

    std::cout << b.get(0) << " " << b.get(1) << " " << b.get(2) << "\n";
}

int main(){
    test_FixedArray();

    return 0;
}