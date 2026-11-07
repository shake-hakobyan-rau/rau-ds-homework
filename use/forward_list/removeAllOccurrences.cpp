#include <iostream>
#include <forward_list>
#include <cassert>

int removeAllOccurrences(std::forward_list<int>& fl, int value) {
    int count = 0;
    auto prev = fl.before_begin();
    auto current = fl.begin();
    while (current != fl.end()) {
        if (*current == value) {
            current = fl.erase_after(prev);
            count++;
        }
        else {
            prev = current;
            ++current;
        }
    }
    return count;
}

void test() {
    std::forward_list<int> fl = {1, 2, 3, 2, 4, 2};

    int removed = removeAllOccurrences(fl, 2);

    assert(removed == 3);
    assert((fl == std::forward_list<int>{1, 3, 4}));

    assert(removeAllOccurrences(fl, 10) == 0);

    std::forward_list<int> fl2 = {5, 5, 5};
    assert(removeAllOccurrences(fl2, 5) == 3);
    assert(fl2.empty());

    std::forward_list<int> empty;
    assert(removeAllOccurrences(empty, 1) == 0);
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
