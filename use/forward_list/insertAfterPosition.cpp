#include <iostream>
#include <forward_list>
#include <cassert>

bool insertAfterPosition(std::forward_list<int>& fl, int position, int value) {
    if (position < 0) {
        return false;
    }
    auto it = fl.begin();
    for (int i = 0; i < position; i++) {
        if (it == fl.end()) {
            return false;
        }
        ++it;
    }
    if (it == fl.end()) {
        return false;
    }
    fl.insert_after(it, value);
    return true;
}

void test() {
    std::forward_list<int> fl = {1, 2, 3, 4};

    assert(insertAfterPosition(fl, 1, 99));
    assert((fl == std::forward_list<int>{1, 2, 99, 3, 4}));

    assert(!insertAfterPosition(fl, 10, 5));
    assert(!insertAfterPosition(fl, -1, 5));
    assert(!insertAfterPosition(fl, 5, 5));

    std::forward_list<int> empty;
    assert(!insertAfterPosition(empty, 0, 10));
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
