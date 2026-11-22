#include <iostream>
#include <forward_list>
#include <cassert>

void mergeSortedLists(std::forward_list<int>& fl1, std::forward_list<int>& fl2) {
    fl1.merge(fl2);
    fl2.clear();
}

void test() {
    std::forward_list<int> fl1 = {1, 3, 5};
    std::forward_list<int> fl2 = {2, 4, 6};

    mergeSortedLists(fl1, fl2);

    assert((fl1 == std::forward_list<int>{1, 2, 3, 4, 5, 6}));
    assert(fl2.empty());

    std::forward_list<int> a = {1, 2};
    std::forward_list<int> b;

    mergeSortedLists(a, b);

    assert((a == std::forward_list<int>{1, 2}));
    assert(b.empty());

    std::forward_list<int> c;
    std::forward_list<int> d = {3, 4};

    mergeSortedLists(c, d);

    assert((c == std::forward_list<int>{3, 4}));
    assert(d.empty());
}

int main() {
    test();
    std::cout << "all tests passed";
    return 0;
}
