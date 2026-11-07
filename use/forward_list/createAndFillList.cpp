#include <iostream>
#include <forward_list>
#include <cassert>

void createAndFillList(int n) {
    std::forward_list<int> fl;
    for (int i = 1; i <= n; i++) {
        fl.push_front(i);
    }
    for (int x : fl) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

void test() {
    createAndFillList(5);
    createAndFillList(3);
    createAndFillList(0);

    assert(true);
}

int main() {
    test();
    return 0;
}
